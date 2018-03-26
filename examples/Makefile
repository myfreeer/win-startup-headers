CC ?= gcc
CFLAGS := -Wall -Wextra -O3 -Os -s -nostartfiles \
	-fmerge-all-constants -fno-asynchronous-unwind-tables \
	-Wl,--gc-sections -Wl,--build-id=none

CHOST = $(shell $(CC) -dumpmachine)
EXTRA_CFLAGS = -fno-ident -fno-stack-protector -fomit-frame-pointer \
	-fno-unwind-tables -falign-functions=1 -falign-jumps=1 -falign-loops=1 \
	-ffunction-sections -fdata-sections  -fno-math-errno

ifneq (,$(findstring x86_64-w64-,$(CHOST)))
    EXTRA_CFLAGS += -Wl,-T,../ldscripts/x86_64.ldscript
else ifneq (,$(findstring i686-w64-,$(CHOST)))
    EXTRA_CFLAGS += -Wl,-T,../ldscripts/i386.ldscript
endif

all: helloworld.exe console.exe hello_win.exe

clean:
	-@rm -f *.exe *.o

console.exe: console.c ../main.h ../commandlinetoargva.h
	$(CC) $< -o $@ $(CFLAGS) $(EXTRA_CFLAGS) -I..

helloworld.exe: helloworld.c ../mainv.h ../commandlinetoargva.h
	$(CC) $< -o $@ $(CFLAGS) $(EXTRA_CFLAGS) -I..

hello_win.exe: hello_win.c ../winmain.h ../commandlinetoargva.h
	$(CC) $< -o $@ $(CFLAGS) $(EXTRA_CFLAGS) -mwindows -I..

%.exe: %.c
	$(CC) $< -o $@ $(CFLAGS) $(EXTRA_CFLAGS) -I..

.PHONY: clean
.SILENT: clean