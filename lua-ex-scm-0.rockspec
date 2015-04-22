package = "lua-ex"
version = "scm-0"
source = {
  url = "git://github.com/luaforge/lua-ex.git",
  branch = "master"
}
description = {
  summary = "Lua Extension API.",
  detailed = [[
    The Lua Extension API is a proposal for a standard set of functions 
    to provide a more complete programming environment for Lua.
  ]],
  homepage = "https://github.com/luaforge/lua-ex",
}
dependencies = {
  "lua >= 5.1"
}

local function make_plat(plat)
  local defines = {
    unix = {
      "_XOPEN_SOURCE=600",
    },
    cygwin = {
      "_XOPEN_SOURCE=600",
      "MISSING_POSIX_SPAWN",
    },
    win32 = {
      "WIN32_LEAN_AND_MEAN",
      "NOGDI",
    },
  }
  local modules = {
    unix = {
      ex = {
        sources = {
          "posix/ex.c",
          "posix/spawn.c",
        },
        defines = defines[plat],
        incdir = "/posix",
      },
    },
    cygwin = {
      ex = {
        sources = {
          "posix/ex.c",
          "posix/spawn.c",
          "posix/posix_spawn.c",
        },
        defines = defines[plat],
        incdir = "/posix",
      },
    },
    win32 = {
      ex = {
        sources = {
          "w32api/ex.c",
          "w32api/spawn.c",
          "w32api/pusherror.c",
          "w32api/dirent.c",
        },
        defines = defines[plat],
        incdir = "/w32api",
      },
    },
  }
  return { modules = modules[plat] }
end

build = {
  type = "builtin",
  platforms = {
    unix    = make_plat("unix"),
    cygwin  = make_plat("cygwin"),
    mingw32 = make_plat("win32"),
    win32   = make_plat("win32"),
  },
}
