/*
 * "ex" API implementation
 * http://lua-users.org/wiki/ExtensionProposal
 * Copyright 2007 Mark Edgar < medgar at gmail com >
 */
#include <stdlib.h>
#include <assert.h>
#include <errno.h>

#include <unistd.h>
#include <limits.h>
#include <sys/types.h>

#include "environ.h"
#include "posix_spawn.h"

#ifndef OPEN_MAX
#define OPEN_MAX sysconf(_SC_OPEN_MAX)
#endif

int posix_spawnattr_init(posix_spawnattr_t *attrp)
{
  attrp->flags = 0;
  return 0;
}

int posix_spawnattr_getflags(
  const posix_spawnattr_t *restrict attrp,
  short *restrict flags)
{
  *flags = attrp->flags;
  return 0;
}

int posix_spawnattr_setflags(
  posix_spawnattr_t *attrp,
  short flags)
{
  attrp->flags = flags;
  return 0;
}

int posix_spawnattr_destroy(posix_spawnattr_t *attrp)
{
  return 0;
}

int posix_spawn_file_actions_init(
  posix_spawn_file_actions_t *act)
{
  act->dups[0] = act->dups[1] = act->dups[2] = -1;
  return 0;
}

int posix_spawn_file_actions_adddup2(
  posix_spawn_file_actions_t *act,
  int d,
  int n)
{
  /* good faith effort to determine validity of descriptors */
  if (d < 0 || OPEN_MAX < d || n < 0 || OPEN_MAX < n) {
    errno = EBADF;
    return -1;
  }
  /* we only support duplication to 0,1,2 */
  if (2 < n) {
    errno = EINVAL;
    return -1;
  }
  act->dups[n] = d;
  return 0;
}

int posix_spawn_file_actions_destroy(
  posix_spawn_file_actions_t *act)
{
  return 0;
}

int posix_spawnp(
  pid_t *restrict ppid,
  const char *restrict path,
  const posix_spawn_file_actions_t *act,
  const posix_spawnattr_t *restrict attrp,
  char *const argv[restrict],
  char *const envp[restrict])
{
  const short usevfork = POSIX_SPAWN_USEVFORK;
  short flags = 0;

  if (!ppid || !path || !argv || !envp)
    return EINVAL;

  posix_spawnattr_getflags(attrp, &flags);
  if (flags & usevfork) {
    *ppid = vfork();
  } else {
    *ppid = fork();
  }

  switch (*ppid) {
  case -1: return -1;
  default: return 0;
  case 0:
    if (act) {
      int i;
      for (i = 0; i < 3; i++)
        if (act->dups[i] != -1 && -1 == dup2(act->dups[i], i))
          _exit(111);
    }
    environ = (char **)envp;
    execvp(path, argv);
    _exit(111);
    /*NOTREACHED*/
  }
}
