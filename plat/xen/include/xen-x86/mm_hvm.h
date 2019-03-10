/* SPDX-License-Identifier: MIT */
/*
 * (C) 2016 - Juergen Gross, SUSE Linux GmbH
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#ifndef _MM_HVM_H
#define _MM_HVM_H

#include <xen-x86/setup.h>

#define mfn_to_pfn(_mfn) ((unsigned long)(_mfn))
#define pfn_to_mfn(_pfn) ((unsigned long)(_pfn))

#if 0
/* for P2M */
#ifdef __x86_64__
#define P2M_SHIFT       9
#else
#define P2M_SHIFT       10
#endif
#define P2M_ENTRIES     (1UL << P2M_SHIFT)
#define P2M_MASK        (P2M_ENTRIES - 1)
#define L1_P2M_SHIFT    P2M_SHIFT
#define L2_P2M_SHIFT    (2 * P2M_SHIFT)
#define L3_P2M_SHIFT    (3 * P2M_SHIFT)
#define L1_P2M_IDX(pfn) ((pfn) & P2M_MASK)
#define L2_P2M_IDX(pfn) (((pfn) >> L1_P2M_SHIFT) & P2M_MASK)
#define L3_P2M_IDX(pfn) (((pfn) >> L2_P2M_SHIFT) & P2M_MASK)
#define INVALID_P2M_ENTRY (~0UL)

void p2m_chk_pfn(unsigned long pfn);

static inline unsigned long p2m_pages(unsigned long pages)
{
	return (pages + P2M_ENTRIES - 1) >> L1_P2M_SHIFT;
}

void arch_init_p2m(unsigned long max_pfn_p);

#endif

#endif /* _MM_PV_H */
