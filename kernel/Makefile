HOMEDIR=$(HOME)/dev/OS_dev/repo
BASEDIR=$(HOMEDIR)/osbook/devenv/x86_64-elf
EDK2DIR=$(HOMEDIR)/edk2
ENV_OSBOOK = $(HOME)/dev/OS_dev/repo/osbook/devenv

TARGET = kernel.elf
OBJS = main.o

CPPFLAGS=\
         -I$(BASEDIR)/include/c++/v1 -I$(BASEDIR)/include -I$(BASEDIR)/include/freetype2 \
         -I$(EDK2DIR)/MdePkg/Include -I$(EDK2DIR)/MdePkg/Include/X64 \
         -nostdlibinc -D__ELF__ -D_LDBL_EQ_DBL -D_GNU_SOURCE -D_POSIX_TIMERS \
         -DEFIAPI='__attribute__((ms_abi))'
LDFLAGS=-L$(BASEDIR)/lib

CXXFLAGS += -O2 -Wall -g --target=x86_64-elf -ffreestanding -mno-red-zone \
            -fno-exceptions -fno-rtti -std=c++17
LDFLAGS += --entry KernelMain -z norelro --image-base 0x100000 --static

.PHONY: all
all: $(TARGET) 

.PHONY: clean
clean:
	rm -rf *.o

kernel.elf: $(OBJS) Makefile
	ld.lld $(LDFLAGS) -o kernel.elf $(OBJS)

%.o: %.cpp Makefile
	clang++ $(CPPFLAGS) $(CXXFLAGS) -c $<

