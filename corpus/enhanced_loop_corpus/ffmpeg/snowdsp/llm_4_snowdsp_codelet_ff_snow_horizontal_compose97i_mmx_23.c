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
        if ((i & 16) == 0) {
            asm volatile (
                "movq        (%1), %%mm0       \n\t"
                "movq       8(%1), %%mm2       \n\t"
                "movq      16(%1), %%mm4       \n\t"
                "movq      24(%1), %%mm6       \n\t"
                "movq        (%1), %%mm1       \n\t"
                "movq       8(%1), %%mm3       \n\t"
                "movq      16(%1), %%mm5       \n\t"
                "movq      24(%1), %%mm7       \n\t"
                "punpcklwd   (%2), %%mm0       \n\t"
                "punpcklwd  8(%2), %%mm2       \n\t"
                "punpcklwd 16(%2), %%mm4       \n\t"
                "punpcklwd 24(%2), %%mm6       \n\t"
                "movq       %%mm0, (%0)        \n\t"
                "movq       %%mm2, 16(%0)      \n\t"
                "movq       %%mm4, 32(%0)      \n\t"
                "movq       %%mm6, 48(%0)      \n\t"
                "punpckhwd   (%2), %%mm1       \n\t"
                "punpckhwd  8(%2), %%mm3       \n\t"
                "punpckhwd 16(%2), %%mm5       \n\t"
                "punpckhwd 24(%2), %%mm7       \n\t"
                "movq       %%mm1, 8(%0)       \n\t"
                "movq       %%mm3, 24(%0)      \n\t"
                "movq       %%mm5, 40(%0)      \n\t"
                "movq       %%mm7, 56(%0)      \n\t"
                : 
                : "r" (&b[i]), "r" (&b[i >> 1]), "r" (&temp[i >> 1])
                : "memory"
            );
        }
    }
}
