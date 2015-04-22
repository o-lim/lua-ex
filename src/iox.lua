local ex_core = require 'ex.core'
local iox = {
  lock   = ex_core.lock,
  unlock = ex_core.unlock,
  pipe   = ex_core.pipe,
}

return iox
