/* hvImage.lds - RK3399 linked script */

/*
 * Copyright (c) 2024 lucky_zhang@aliyun.com, Inc.
 *
 * The right to copy, distribute or otherwise make use of this
 * software may be licensed only pursuant to the terms of an
 * applicable lucky_zhang@aliyun.com license agreement.
 */

/*
changed history
--------------------
20jun24,yzhang  written
*/

OUTPUT_FORMAT("elf64-littleaarch64", "elf64-littleaarch64", "elf64-littleaarch64")
OUTPUT_ARCH(aarch64)
ENTRY(_hvStart)

SECTIONS
{
    . = 0x20000000;
    . = ALIGN(4096);
    .text : 
    {
        hvStart.o
        *(.text)
    }
    
    . = ALIGN(16);
    .rodata:{*(.rodata)}

    . = ALIGN(16);
    .data:{*(.data)}

    . = ALIGN(16);
    _bss_start = . ;
    .bss : {*(.bss)}
    _bss_end = . ;
}
