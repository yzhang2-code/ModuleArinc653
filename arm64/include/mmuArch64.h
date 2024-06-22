/* mmuArch64.h - ARM AArch64 MMU headers */

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
22jun24,yzhang  written
*/

/*
DESCRIPTIONS

Virtual Address:

63         48 47          39 38          30 29          21 20           12 11          0
----------------------------------------------------------------------------------------
|            | L0 level VFN | L1 level VFN | L2 level VFN | L3 level VFN | Page Offset |
----------------------------------------------------------------------------------------
             |---------------> Vurtual Frame Number <--------------------|      |
                                                                                |-------
 TTBRx_EL1/2                                                                           |
    |         L0 Table            L1 Table            L2 Table            L3 Table     |
    |       -----------         -----------         ------------         -----------   |
    |       |         |         |         |         |          |         |         |   |
    |       -----------         -----------         ------------         -----------   |
    |       |         |         |         |         |          |         |         |   |
    |       -----------         -----------         ------------         -----------   |
    |       |         |         |         |         |          |         |         |   |
    |       -----------         -----------         ------------         -----------   |
    |       |         |---      |         | ---     |          |---      |         |   |
    |       -----------  |      -----------   |     ------------  |      -----------   |
    |       |         |  |      |         |   |     |          |  |      |         |   |
    |-----> -----------  |----> -----------   |---> ------------  |----> -----------   |
                                                                                       |
Physical Address:                                                              <-------|
                                                                               |
63         48 47                                                       12 11   |      0
----------------------------------------------------------------------------------------
|            |                     Physical Frame Number                 | Page Offset |
----------------------------------------------------------------------------------------

Each table entry of the table L0/1/2 contains a physical address. It consists of an
attribute and a PFN.

Table Entry:
63         59 58   48 47                                            12 11              0
----------------------------------------------------------------------------------------
|  Attribute |       |             Physical Frame Number              |      IGNORE    |
----------------------------------------------------------------------------------------

*/

#ifndef MMUARCH64_H
#define MMUARCH64_H

/* include */

#include <types.h>

#ifdef __cplusplus
extern "C" {
#endif

/* used to determine table index */

#define MMU_ARCH64_INDEX(x, shift, mask) \
    ((((physAddr_t) (x)) >> (shift)) & (mask))

/* 4KB granule table indices */

#define MMU_ARCH64_4KGRANULE_L0_VFN_INDEX(x) \
    MMU_ARCH64_INDEX ((x), 39, 0x1FF)

#define MMU_ARCH64_4KGRANULE_L1_VFN_INDEX(x) \
    MMU_ARCH64_INDEX ((x), 30, 0x1FF)

#define MMU_ARCH64_4KGRANULE_L2_VFN_INDEX(x) \
    MMU_ARCH64_INDEX ((x), 21, 0x1FF)

#define MMU_ARCH64_4KGRANULE_L3_VFN_INDEX(x) \
    MMU_ARCH64_INDEX((x), 12, 0x1FF)

/* convert: PFN <-> Physical Address */

#define MMU_AARCH64_PFN_TO_ADDR(x, rpn_shift) \
    (((physAddr_t) (x)) << (rpn_shift))

#define MMU_AARCH64_ADDR_TO_PFN(x, rpn_shift, rpn_mask) \
    ((((physAddr_t) (x)) >> (rpn_shift)) & (rpn_mask))

/* 4KB granule */

#define MMU_AARCH64_4KGRANULE_1GB_PFN_TO_ADDR(x) \
    MMU_AARCH64_PFN_TO_ADDR (x, 30)

#define MMU_AARCH64_4KGRANULE_ADDR_TO_1GB_PFN(x) \
    MMU_AARCH64_ADDR_TO_PFN (x, 30, 0x3FFFF)

#define MMU_AARCH64_4KGRANULE_2MB_PFN_TO_ADDR(x) \
    MMU_AARCH64_PFN_TO_ADDR (x, 21)

#define MMU_AARCH64_4KGRANULE_ADDR_TO_2MB_PFN(x) \
    MMU_AARCH64_ADDR_TO_PFN (x, 21, 0x7FFFFFF)

#define MMU_AARCH64_4KGRANULE_4KB_PFN_TO_ADDR(x) \
    MMU_AARCH64_PFN_TO_ADDR (x, 12)

#define MMU_AARCH64_4KGRANULE_ADDR_TO_4KB_PFN(x) \
    MMU_AARCH64_ADDR_TO_PFN (x, 12, 0xFFFFFFFFF)

#define MMU_AARCH64_4KGRANULE_TBL_PFN_TO_ADDR(x) \
    MMU_AARCH64_PFN_TO_ADDR (x, 12)

#define MMU_AARCH64_4KGRANULE_ADDR_TO_TBL_PFN(x) \
    MMU_AARCH64_ADDR_TO_PFN (x, 12, 0xFFFFFFFFF)

#ifdef __cplusplus
}
#endif

#endif  /* MMUARCH64_H */
