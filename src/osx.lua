local ex_core = require 'ex.core'
local osx = {
  -- environment
  getenv     = ex_core.getenv,
  setenv     = ex_core.setenv,
  environ    = ex_core.environ,

  -- file system
  currentdir = ex_core.currentdir,
  chdir      = ex_core.chdir,
  mkdir      = ex_core.mkdir,
  remove     = ex_core.remove,
  dir        = ex_core.dir,
  dirent     = ex_core.dirent,

  -- process control
  sleep      = ex_core.sleep,
  spawn      = ex_core.spawn,
  wait       = ex_core.wait,
}

return osx
