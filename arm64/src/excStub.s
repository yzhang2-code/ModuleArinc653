/* exceptionStub.s - Arch64 EL2 exception handling */

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
19jun24,yzhang  written
*/

    .balign 4096

FUNC_BEGIN(hvpExcVecBase)

/* ----------- current exception level with SP_EL0 (not used) -----------  */

current_synchronous_sp0:
    sync_handler

    .balign 128
current_irq_sp0:
    irq_handler

    .balign 128
current_fiq_sp0:
    fiq_handler

    .balign 128
current_serror_sp0:
    sync_handler

/* ----------- current exception level with SP_ELx ----------- */

    .balign 128
current_synchronous:
    sync_handler

    .balign 128
current_irq:
    irq_handler

    .balign 128
current_fiq:
    fiq_handler

    .balign 128
current_serror:
    sync_handler

/* ----------- lower exception level in Aarch64 ----------- */

    .balign 128
lower_synchronous_aarch64:
    lower_sync_handler

    .balign 128
lower_irq_aarch64:
    lower_irq_fiq_handler

    .balign 128
lower_fiq_aarch64:
    lower_irq_fiq_handler

    .balign 128
lower_serror_arch64:
    lower_sync_handler

/* ----------- lower exception level in Arch32 ----------- */

    .balign 128
lower_synchronous_aarch32:
    lower_sync_handler

    .balign 128
lower_irq_aarch32:
    lower_irq_fiq_handler

    .balign 128
lower_fiq_aarch32:
    lower_irq_fiq_handler

    .balign 128
lower_serror_arch32:
    lower_sync_handler
