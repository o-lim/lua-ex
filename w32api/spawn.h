#ifndef SPAWN_H
#define SPAWN_H
#include <lua.h>

#include <windows.h>

#define PROCESS_HANDLE "process"
struct process;
struct spawn_params;

struct spawn_params *spawn_param_init(lua_State *L);
void spawn_param_filename(struct spawn_params *p, const char *filename);
void spawn_param_args(struct spawn_params *p);
void spawn_param_env(struct spawn_params *p);
void spawn_param_redirect(struct spawn_params *p, const char *stdname, FILE *f);
int spawn_param_execute(struct spawn_params *p);

int process_wait(lua_State *L);
int process_tostring(lua_State *L);

#endif/*SPAWN_H*/