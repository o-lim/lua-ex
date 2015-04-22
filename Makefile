default:; @cat INSTALL
all: mingw cygwin

mingw:; $(MAKE) -C w32api all
cygwin:; $(MAKE) -C posix T=ex_core.dll all
linux:; $(MAKE) -C posix all

clean:
	$(MAKE) -C posix clean
	$(MAKE) -C w32api clean

