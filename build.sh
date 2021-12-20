#!/bin/bash

make -C kernel

if [ "${1:-}" = "run" ]
then
  cd $HOME/edk2
  source edksetup.sh
  build
  $HOME/os_dev/osbook/devenv/run_qemu.sh Build/MikanLoaderX64/DEBUG_CLANG38/X64/Loader.efi $HOME/os_dev/my_mikanos/kernel/kernel.elf
fi
