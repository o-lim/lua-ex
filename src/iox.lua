local ex_core = require 'ex.core'
local iox = {
  lock   = ex_core.lock,
  unlock = ex_core.unlock,

  pipe   = ex_core.pipe,

  popen2 = function(...)
    local proc_rd, wr = ex_core.pipe()
    local rd, proc_wr = ex_core.pipe()
    local proc, err = ex_core.spawn{stdin = proc_rd, stdout = proc_wr, ...}
    proc_rd:close(); proc_wr:close()
    if not proc then
      wr:close(); rd:close()
      return proc, err
    end
    return proc, rd, wr
  end,

  popen3 = function(...)
    local proc_rd, wr = ex_core.pipe()
    local rd, proc_wr = ex_core.pipe()
    local rderr, proc_werr = ex_core.pipe()
    local proc, err = ex_core.spawn{stdin = proc_rd, stdout = proc_wr, stderr = proc_werr, ...}
    proc_rd:close(); proc_wr:close(); proc_werr:close()
    if not proc then
      wr:close(); rd:close(); rderr:close()
      return proc, err
    end
    return proc, rd, wr, rderr
  end,
}

return iox
