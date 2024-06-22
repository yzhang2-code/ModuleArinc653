/* asmArch64.h - ARM AArch64 Hypervisor assembly headers */

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

#ifndef ASMARCH64_H
#define ASMARCH64_H

#ifdef __cplusplus
extern "C" {
#endif

#define ASM_FUNC(func)        func
#define ASM_FUNC_LABEL(func)  func:
#define ASM_VAR(name)         name


#define ASM_FUNC_EXPORT(func)  .globl ASM_FUNC (func)
#define ASM_DATA_EXPORT(var)   .globl ASM_VAR (var)
#define ASM_FUNC_IMPORT(func)  .extern ASM_FUNC (func)
#define ASM_DATA_IMPORT(var)   .extern ASM_VAR_DECL (var)
#define ASM_FUNC_BEGIN(func)   ASM_FUNC_LABEL (func)
#define ASM_FUNC_END(func)     .size ASM_FUNC (func), . - ASM_FUNC (func)

#ifdef __cplusplus
}
#endif

#endif  /* ASMARCH64_H */
