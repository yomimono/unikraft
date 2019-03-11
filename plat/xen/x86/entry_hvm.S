/* Included by x86_[32|64].S */
#include <xen-x86/desc.h>

        .code32                 /* Always starts in 32bit flat mode. */

        mov $(X86_CR4_PAE | X86_CR4_OSFXSR), %eax
        mov %eax, %cr4
        mov $page_table_base, %eax
        mov %eax, %cr3

#ifdef __X86_64__               /* EFER.LME = 1 */
        mov $MSR_EFER, %ecx
        rdmsr
        bts $_EFER_LME, %eax
        wrmsr
#endif /* __X86_64__ */

        mov %cr0, %eax
        or $X86_CR0_PG, %eax
        mov %eax, %cr0

        lgdt gdt_ptr

        /* Load code segment. */
        ljmp $__KERN_CS, $1f
#ifdef __X86_64__
        .code64
#endif

        /* Load data segments. */
1:
        mov $__USER_DS, %eax
        mov %eax, %ds
        mov %eax, %es
        mov %eax, %fs
        mov %eax, %gs
        mov $__KERN_DS, %eax
        mov %eax, %ss

        mov %ebx, %esi
