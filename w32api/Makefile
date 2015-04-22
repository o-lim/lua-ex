include ../conf

TGT_ARCH=
CFLAGS= $(WARNINGS) $(DEFINES) $(INCLUDES) $(MYCFLAGS)
DEFINES= -DWIN32_LEAN_AND_MEAN -DNOGDI
INCLUDES= $(LUAINC)
WARNINGS= -W -Wall
LIBS= $(LUALIB)

TDIR?= ../ex
T?= core.dll
default: all

OBJS= ex.o spawn.o pusherror.o dirent.o
$(TDIR):; mkdir -p $(TDIR)
$(TDIR)/$(T): $(OBJS) | $(TDIR); $(CC) $(TGT_ARCH) -shared -o $@ $(OBJS) $(LIBS)
all: $(TDIR)/$(T) | $(TDIR); cp -p ../src/*.lua $(TDIR)

clean:; rm -rf *.dll *.o $(TDIR)
