CFLAGS = $(WARNINGS) $(DEFINES) $(INCLUDES)
WARNINGS = -W -Wall
#DEFINES = -D_XOPEN_SOURCE=600
INCLUDES = -I$(LUA)/include

LUA = /home/mark/src/lang/lua/lua-5.1-rc1

mingw:; $(MAKE) "EX_LIB=ex.dll"

cygwin:; $(MAKE) "EX_LIB=ex.so" "DEFINES=-D_XOPEN_SOURCE=600"
