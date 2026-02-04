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
    for (i -= 30; i >= 0; i -= 32) {
        asm volatile (
            "movq        (%1), %%mm0       \n\t"
            "movq       8(%1), %%mm2       \n\t"
            "movq      16(%1), %%mm4       \n\t"
            "movq      24(%1), %%mm6       \n\t"
            "movq        (%1), %%mm1       \n\t"
            "movq       8(%1), %%mm3       \n\t"
            "movq      16(%1), %%mm5       \n\t"
            "movq      24(%1), %%mm7       \n\t"
            : 
            : "r" (&b[i]), "r" (&b[i >> 1])
            : "memory"
        );

        if (temp[i >> 1] > 0) {
            asm volatile (
                "punpcklwd   (%1), %%mm0       \n\t"
                "punpcklwd  8(%1), %%mm2       \n\t"
                "punpcklwd 16(%1), %%mm4       \n\t"
                "punpcklwd 24(%1), %%mm6       \n\t"
                "movq       %%mm0, (%0)        \n\t"
                "movq       %%mm2, 16(%0)      \n\t"
                "movq       %%mm4, 32(%0)      \n\t"
                "movq       %%mm6, 48(%0)      \n\t"
                "punpckhwd   (%1), %%mm1       \n\t"
                "punpckhwd  8(%1), %%mm3       \n\t"
                "punpckhwd 16(%1), %%mm5       \n\t"
                "punpckhwd 24(%1), %%mm7       \n\t"
                "movq       %%mm1, 8(%0)       \n\t"
                "movq       %%mm3, 24(%0)      \n\t"
                "movq       %%mm5, 40(%0)      \n\t"
                "movq       %%mm7, 56(%0)      \n\t"
                : 
                : "r" (&b[i]), "r" (&temp[i >> 1])
                : "memory"
            );
        } else {
            asm volatile (
                "pxor %%mm0, %%mm0           \n\t"
                "pxor %%mm2, %%mm2           \n\t"
                "pxor %%mm4, %%mm4           \n\t"
                "pxor %%mm6, %%mm6           \n\t"
                "pxor %%mm1, %%mm1           \n\t"
                "pxor %%mm3, %%mm3           \n\t"
                "pxor %%mm5, %%mm5           \n\t"
                "pxor %%mm7, %%mm7           \n\t"
                "movq       %%mm0, (%0)        \n\t"
                "movq       %%mm2, 16(%0)      \n\t"
                "movq       %%mm4, 32(%0)      \n\t"
                "movq       %%mm6, 48(%0)      \n\t"
                "movq       %%mm1, 8(%0)       \n\t"
                "movq       %%mm3, 24(%0)      \n\t"
                "movq       %%mm5, 40(%0)      \n\t"
                "movq       %%mm7, 56(%0)      \n\t"
                : 
                : "r" (&b[i])
                : "memory"
            );
        }
    }
}
