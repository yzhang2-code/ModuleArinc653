# Makefile - Makefile for RK3399 board
#
# Copyright (c) 2024 lucky_zhang@aliyun.com, Inc.
#
# The right to copy, distribute or otherwise make use of this
# software may be licensed only pursuant to the terms of an
# applicable lucky_zhang@aliyun.com license agreement.
#
# changed history
# --------------------
# 20jun24,yzhang  written

CC := aarch64-linux-gnu-
hvImage.bin:hvStart.o      
	$(CC)ld  -ThvImage.lds $^  -o  hvImage.elf
	$(CC)objcopy  -O binary -S hvImage.elf   $@
	$(CC)objdump  -D  -m  arm  hvImage.elf > hvImage.dis

hvStart.o:hvStart.S
	$(CC)gcc -c hvStart.S -o hvStart.o -I../../../arm64/include/
%.o:%.c
	$(CC)gcc -Wall  -nostdlib  -c  -O2  -o  $@  $<
%.o:%.s
	$(CC)gcc -Wall  -nostdlib  -c  -O2  -o  $@  $<
%.o:%.S
	$(CC)gcc -Wall  -nostdlib  -c  -O2  -o  $@  $<

.PHONY:
clean:
	rm *.o *.bin  *.elf *.dis
