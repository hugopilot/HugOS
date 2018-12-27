# OS

I do some experimenting here to create a simple operating system

## How to build?
- Step 0: make sure you have a cross-compiler with the i686 target architecture. [This article from OSDev will help you with that](https://wiki.osdev.org/GCC_Cross-Compiler#Preparing_for_the_build). 

I assume you know how to use a terminal!

- Step 1: Clone this repo with ```git clone https://github.com/hugopilot/OS.git```. 
- Step 2: Compile boot.asm with NASM. Use: ```nasm -felf32 boot.asm -o boot.o```
- Step 3: Compile kernel.c with your compiler. In the case of i686-elf-gcc: ```i686-elf-gcc -c kernel.c -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra```
- Step 4: Link the files with ```i686-elf-gcc -T link.ld -o myos.bin -ffreestanding -O2 -nostdlib boot.o kernel.o -lgcc```

You now have a ```myos.bin``` file which contains the kernel. 

To make it bootable on your PC, you will need to use GRUB.
- Step 1: make a folder. I name mine 'container': ```mkdir container```
- Step 2: Put myos.bin into the container under a ```boot``` folder. Via terminal: ```cp myos.bin container/boot/myos.bin```.
- Step 3: Create a file called ```grub.cfg``` and put this into it's contents:

`menuentry "myos" {
	multiboot /boot/myos.bin
}`

- Step 3: Put grub.cfg into ```container/boot/grub```. Via terminal: ```cp grub.cfg container/boot/grub/grub.cfg```.
- Step 4: Make an ISO from container: ```grub-mkrescue -o aName.iso container```
- Step 5: Put the usb in your device and enter ```sudo dd if=aName.iso of=/dev/sdX && sync```

NOTE that ```sdX``` should be replaced with the path of the drive (e.g ```sde```).

You can boot it now.
