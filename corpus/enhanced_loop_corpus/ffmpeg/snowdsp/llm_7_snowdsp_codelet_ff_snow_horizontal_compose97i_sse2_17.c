#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern IDWTELEM *b;
extern IDWTELEM *temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i -= 62; i >= 0; i -= 64) {
    int offset = i >> 1;
    IDWTELEM *src_b = &(b)[offset];
    IDWTELEM *src_temp = &(temp)[offset];
    IDWTELEM *dst_b = &(b)[i];

    // Introduce artificial loop-carried dependency via scalar variable
    static short carry = 0;
    carry ^= dst_b[0]; // Read from current b[i] to create WAW/RAR dependency across iterations

    asm volatile (
        "movdqa     (%1), %%xmm0           \n\t"
        "movdqa   16(%1), %%xmm1           \n\t"
        "movdqa   32(%1), %%xmm2           \n\t"
        "movdqa   48(%1), %%xmm3           \n\t"
        "pxor       %%xmm4, %%xmm4         \n\t"  // Zero temp register for expansion
        "paddw      %%xmm4, %%xmm0         \n\t"  // Dummy add (noop if zero) - introduces RAW on xmm4
        "paddw      %%xmm4, %%xmm1         \n\t"
        "paddw      %%xmm4, %%xmm2         \n\t"
        "paddw      %%xmm4, %%xmm3         \n\t"
        "punpcklwd  (%2), %%xmm0           \n\t"
        "punpcklwd 16(%2), %%xmm1           \n\t"
        "punpcklwd 32(%2), %%xmm2           \n\t"
        "punpcklwd 48(%2), %%xmm3           \n\t"
        "movdqa     %%xmm0, (%0)            \n\t"
        "movdqa     %%xmm1, 32(%0)          \n\t"
        "movdqa     %%xmm2, 64(%0)          \n\t"
        "movdqa     %%xmm3, 96(%0)          \n\t"
        "punpckhwd  (%2), %%xmm0            \n\t"
        "punpckhwd 16(%2), %%xmm1            \n\t"
        "punpckhwd 32(%2), %%xmm2            \n\t"
        "punpckhwd 48(%2), %%xmm3            \n\t"
        "movdqa     %%xmm0, 16(%0)          \n\t"
        "movdqa     %%xmm1, 48(%0)          \n\t"
        "movdqa     %%xmm2, 80(%0)          \n\t"
        "movdqa     %%xmm3, 112(%0)         \n\t"
        : 
        : "r"(dst_b), "r"(src_b), "r"(src_temp)
        : "memory", "xmm0", "xmm1", "xmm2", "xmm3", "xmm4");

    // Write back modified carry to enforce WAW dependency
    dst_b[0] = carry;
}
}
