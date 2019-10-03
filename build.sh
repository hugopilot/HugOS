#!/bin/bash

export cross_dir="$HOME/compilers/x86_64-elf/bin"

rm build/kernel-x86_64.bin -f
rm build/kernel -rf
make kernel

cd build

cp kernel-x86_64.bin isofiles/boot/kernel.bin

grub-mkrescue -o os.iso isofiles

cd ..
