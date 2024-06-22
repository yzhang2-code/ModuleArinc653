/* hvStart.S - RK3399 system-dependent routines */

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
18jun24,yzhang  written
*/

/* includes */

#include <asmArm64.h>

/* export */

ASM_FUNC_EXPORT(_hvStart)

/*******************************************************************************
* _hvStart - start Partition Hypervisor after boot
*
* This function is the system start-up entry point for Partition Hypervisor in 
* RAM, the first code executed after booting.  It disables interrupts, sets up
* the stack, and jumps to the C routine startKernel() in bootConfig.c.
*
* Function Prototype:
* void _hvStart
*     (
*     void * dtbAddr
*     )
*/

ASM_FUNC_BEGIN(_hvStart)

    /* MMU = off, I-Cache = off, D-Cache = off here */

    /* save dtb address */

    MOV     X20, X0
  
    /* read current exception level */
    
    MRS	    X1, CurrentEL
    CMP     X1, 0xC
    B.EQ    el3_mode
    CMP     X1, 0x8
    B.EQ    el2_mode
    CMP     X1, 0x4
    B.EQ    el1_mode

el3_mode:


el2_mode:


el1_mode:

ASM_FUNC_END(_hvStart)
