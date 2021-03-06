/*
 * "ex" API implementation
 * http://lua-users.org/wiki/ExtensionProposal
 * Copyright 2007 Mark Edgar < medgar at gmail com >
 */
#include <sched.h>
#include <signal.h>
#include <sys/types.h>

#if __STDC_VERSION__ < 199901L
#define restrict
#endif

typedef struct {
  short int flags;
} posix_spawnattr_t;

#define POSIX_SPAWN_RESETIDS        0x01
#define POSIX_SPAWN_SETPGROUP       0x02
#define POSIX_SPAWN_SETSIGDEF       0x04
#define POSIX_SPAWN_SETSIGMASK      0x08
#define POSIX_SPAWN_SETSCHEDPARAM   0x10
#define POSIX_SPAWN_SETSCHEDULER    0x20
#define POSIX_SPAWN_USEVFORK        0x40

#define posix_spawnattr_init posix_spawnattr_init_
#define posix_spawnattr_getflags posix_spawnattr_getflags_
#define posix_spawnattr_setflags posix_spawnattr_setflags_
#define posix_spawnattr_getpgroup posix_spawnattr_getpgroup_
#define posix_spawnattr_setpgroup posix_spawnattr_setpgroup_
#define posix_spawnattr_getschedparam posix_spawnattr_getschedparam_
#define posix_spawnattr_setschedparam posix_spawnattr_setschedparam_
#define posix_spawnattr_getschedpolicy posix_spawnattr_getschedpolicy_
#define posix_spawnattr_setschedpolicy posix_spawnattr_setschedpolicy_
#define posix_spawnattr_getsigdefault posix_spawnattr_getsigdefault_
#define posix_spawnattr_setsigdefault posix_spawnattr_setsigdefault_
#define posix_spawnattr_getsigmask posix_spawnattr_getsigmask_
#define posix_spawnattr_setsigmask posix_spawnattr_setsigmask_
#define posix_spawnattr_destroy posix_spawnattr_destroy_
#define posix_spawn_file_actions_init posix_spawn_file_actions_init_
#define posix_spawn_file_actions_adddup2 posix_spawn_file_actions_adddup2_
#define posix_spawn_file_actions_addclose posix_spawn_file_actions_addclose_
#define posix_spawn_file_actions_addopen posix_spawn_file_actions_addopen_
#define posix_spawn_file_actions_destroy posix_spawn_file_actions_destroy_
#define posix_spawn posix_spawn_
#define posix_spawnp posix_spawnp_

int posix_spawnattr_init_(posix_spawnattr_t *attrp);
int posix_spawnattr_getflags_(
  const posix_spawnattr_t *restrict attrp,
  short *restrict flags);
int posix_spawnattr_setflags_(
  posix_spawnattr_t *attrp,
  short flags);
int posix_spawnattr_getpgroup_(
  const posix_spawnattr_t *restrict attrp,
  pid_t *restrict pgroup);
int posix_spawnattr_setpgroup_(
  posix_spawnattr_t *attrp,
  pid_t pgroup);
int posix_spawnattr_getschedparam_(
  const posix_spawnattr_t *restrict attrp,
  struct sched_param *restrict schedparam);
int posix_spawnattr_setschedparam_(
  posix_spawnattr_t *restrict attrp,
  const struct sched_param *restrict schedparam);
int posix_spawnattr_getschedpolicy_(
  const posix_spawnattr_t *restrict attrp,
  int *restrict schedpolicy);
int posix_spawnattr_setschedpolicy_(
  posix_spawnattr_t *attrp,
  int schedpolicy);
int posix_spawnattr_getsigdefault_(
  const posix_spawnattr_t *restrict attrp,
  sigset_t *restrict sigdefault);
int posix_spawnattr_setsigdefault_(
  posix_spawnattr_t *restrict attrp,
  const sigset_t *restrict sigdefault);
int posix_spawnattr_getsigmask_(
  const posix_spawnattr_t *restrict attrp,
  sigset_t *restrict sigmask);
int posix_spawnattr_setsigmask_(
  posix_spawnattr_t *restrict attrp,
  const sigset_t *restrict sigmask);
int posix_spawnattr_destroy_(posix_spawnattr_t *attrp);

typedef struct posix_spawn_file_actions posix_spawn_file_actions_t;
struct posix_spawn_file_actions {
  int dups[3];
};

int posix_spawn_file_actions_init_(posix_spawn_file_actions_t *file_actions);
int posix_spawn_file_actions_adddup2_(
  posix_spawn_file_actions_t *file_actions,
  int filedes,
  int newfiledes);
int posix_spawn_file_actions_addclose_(
  posix_spawn_file_actions_t *file_actions,
  int filedes);
int posix_spawn_file_actions_addopen_(
  posix_spawn_file_actions_t *restrict file_actions,
  int filedes,
  const char *restrict path,
  int oflag,
  mode_t mode);
int posix_spawn_file_actions_destroy_(posix_spawn_file_actions_t *file_actions);

int posix_spawn_(
  pid_t *restrict,
  const char *restrict,
  const posix_spawn_file_actions_t *,
  const posix_spawnattr_t *restrict,
  char *const argv[restrict],
  char *const envp[restrict]);
int posix_spawnp_(
  pid_t *restrict,
  const char *restrict,
  const posix_spawn_file_actions_t *,
  const posix_spawnattr_t *restrict,
  char *const argv[restrict],
  char *const envp[restrict]);
