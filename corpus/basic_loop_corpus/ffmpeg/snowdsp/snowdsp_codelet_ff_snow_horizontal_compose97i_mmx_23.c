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
    asm volatile ("movq        (%1), %%mm0       \n\tmovq       8(%1), %%mm2       \n\tmovq      16(%1), %%mm4       \n\tmovq      24(%1), %%mm6       \n\tmovq        (%1), %%mm1       \n\tmovq       8(%1), %%mm3       \n\tmovq      16(%1), %%mm5       \n\tmovq      24(%1), %%mm7       \n\tpunpcklwd   (%2), %%mm0       \n\tpunpcklwd  8(%2), %%mm2       \n\tpunpcklwd 16(%2), %%mm4       \n\tpunpcklwd 24(%2), %%mm6       \n\tmovq       %%mm0, (%0)        \n\tmovq       %%mm2, 16(%0)      \n\tmovq       %%mm4, 32(%0)      \n\tmovq       %%mm6, 48(%0)      \n\tpunpckhwd   (%2), %%mm1       \n\tpunpckhwd  8(%2), %%mm3       \n\tpunpckhwd 16(%2), %%mm5       \n\tpunpckhwd 24(%2), %%mm7       \n\tmovq       %%mm1, 8(%0)       \n\tmovq       %%mm3, 24(%0)      \n\tmovq       %%mm5, 40(%0)      \n\tmovq       %%mm7, 56(%0)      \n\t" :  : "r" (&b[i]), "r" (&b[i >> 1]), "r" (&temp[i >> 1]) : "memory");
}

}
