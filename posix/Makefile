include ../conf

CFLAGS= $(WARNINGS) $(DEFINES) $(INCLUDES) $(MYCFLAGS)
DEFINES= -D_XOPEN_SOURCE=600 $(POSIX_SPAWN)
INCLUDES= $(LUAINC)
WARNINGS= -W -Wall
LIBS= $(LUALIB)

TDIR?= ../ex
T?= core.so
default: all

OBJS= ex.o spawn.o $(EXTRA)
$(TDIR):; mkdir -p $(TDIR)
$(TDIR)/$(T): $(OBJS) $(EXTRA) | $(TDIR); $(CC) -shared -o $@ $(OBJS) $(LIBS)
all: $(TDIR)/$(T) | $(TDIR); cp -p ../src/*.lua $(TDIR)
ex.o: ex.c spawn.h
spawn.o: spawn.c spawn.h
posix_spawn.o: posix_spawn.c posix_spawn.h

clean:; rm -rf *.o *.so *.dll $(TDIR)
