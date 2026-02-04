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
    int offset = i >> 1;
    IDWTELEM *src_b = &b[offset];
    IDWTELEM *src_temp = &temp[offset];
    IDWTELEM *dst = &b[i];

    asm volatile (
        "movq       (%1), %%mm0         \n\t"
        "punpcklwd  (%2), %%mm0         \n\t"
        "movq       %%mm0, (%0)          \n\t"
        "movq       8(%1), %%mm1         \n\t"
        "punpcklwd  8(%2), %%mm1         \n\t"
        "movq       %%mm1, 16(%0)        \n\t"
        "movq       16(%1), %%mm2        \n\t"
        "punpcklwd  16(%2), %%mm2        \n\t"
        "movq       %%mm2, 32(%0)        \n\t"
        "movq       24(%1), %%mm3        \n\t"
        "punpcklwd  24(%2), %%mm3        \n\t"
        "movq       %%mm3, 48(%0)        \n\t"
        "movq       (%1), %%mm4          \n\t"
        "punpckhwd  (%2), %%mm4          \n\t"
        "movq       %%mm4, 8(%0)         \n\t"
        "movq       8(%1), %%mm5         \n\t"
        "punpckhwd  8(%2), %%mm5         \n\t"
        "movq       %%mm5, 24(%0)        \n\t"
        "movq       16(%1), %%mm6        \n\t"
        "punpckhwd  16(%2), %%mm6        \n\t"
        "movq       %%mm6, 40(%0)        \n\t"
        "movq       24(%1), %%mm7        \n\t"
        "punpckhwd  24(%2), %%mm7        \n\t"
        "movq       %%mm7, 56(%0)        \n\t"
        : /* no output */
        : "r"(dst), "r"(src_b), "r"(src_temp)
        : "memory", "mm0", "mm1", "mm2", "mm3", "mm4", "mm5", "mm6", "mm7"
    );

    // Introduce artificial loop-carried dependency via scalar update
    // This creates a WAW and RAW dependency across iterations
    b[i] += b[i + 16];
}
}
