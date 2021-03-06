/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Authors: Costin Lupu <costin.lupu@cs.pub.ro>
 *
 * Copyright (c) 2018, NEC Europe Ltd., NEC Corporation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * THIS HEADER MAY NOT BE EXTRACTED OR MODIFIED IN ANY WAY.
 */
#ifndef __PLAT_CMN_X86_CPU_DEFS_H__
#define __PLAT_CMN_X86_CPU_DEFS_H__

/* EFLAGS register */
#define X86_EFLAGS_CF           (1 <<  0)   /* carry flag                */
#define X86_EFLAGS_PF           (1 <<  2)   /* parity flag               */
#define X86_EFLAGS_AF           (1 <<  4)   /* auxiliary flag            */
#define X86_EFLAGS_ZF           (1 <<  6)   /* zero flag                 */
#define X86_EFLAGS_SF           (1 <<  7)   /* sign flag                 */
#define X86_EFLAGS_TF           (1 <<  8)   /* trap flag                 */
#define X86_EFLAGS_IF           (1 <<  9)   /* interrupt flag            */
#define X86_EFLAGS_DF           (1 << 10)   /* direction flag            */
#define X86_EFLAGS_OF           (1 << 11)   /* overflow flag             */
#define X86_EFLAGS_NT           (1 << 14)   /* nested task flag          */
#define X86_EFLAGS_RF           (1 << 16)   /* resume flag               */
#define X86_EFLAGS_VM           (1 << 17)   /* virtual 8086 mode flag    */
#define X86_EFLAGS_AC           (1 << 18)   /* alignment check flag      */
#define X86_EFLAGS_VIF          (1 << 19)   /* virtual interrupt flag    */
#define X86_EFLAGS_VIP          (1 << 20)   /* virtual interrupt pending */
#define X86_EFLAGS_ID           (1 << 21)   /* ID flag                   */


/*
 * Basic CPU control in CR0
 */
#define X86_CR0_MP              (1 << 1)    /* Monitor Coprocessor */
#define X86_CR0_EM              (1 << 2)    /* Emulation */
#define X86_CR0_NE              (1 << 5)    /* Numeric Exception */
#define X86_CR0_PG              (1 << 31)   /* Paging */

/*
 * Intel CPU features in CR4
 */
#define X86_CR4_PAE             (1 << 5)    /* enable PAE */
#define X86_CR4_OSFXSR          (1 << 9)    /* OS support for FXSAVE/FXRSTOR */
#define X86_CR4_OSXMMEXCPT      (1 << 10)   /* OS support for FP exceptions */

/*
 * Intel CPU features in EFER
 */
#define X86_EFER_LME            (1 << 8)    /* Long mode enable (R/W) */

#endif /* __PLAT_CMN_X86_CPU_DEFS_H__ */
