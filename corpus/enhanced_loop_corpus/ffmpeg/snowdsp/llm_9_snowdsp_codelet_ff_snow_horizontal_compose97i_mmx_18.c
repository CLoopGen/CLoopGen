#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern IDWTELEM *b;
extern  int w_l;
extern int i;
extern IDWTELEM * ref;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; i < w_l - 15; i += 16) {
    asm volatile (
        "movq     (%1), %%mm2        \n\t"
        "movq     8(%1), %%mm3       \n\t"
        "movq    16(%1), %%mm4       \n\t"
        "movq    24(%1), %%mm5       \n\t"
        "paddw    2(%1), %%mm2       \n\t"
        "paddw   10(%1), %%mm3       \n\t"
        "paddw   18(%1), %%mm4       \n\t"
        "paddw   26(%1), %%mm5       \n\t"
        "paddw   %%mm7, %%mm2        \n\t"
        "paddw   %%mm7, %%mm3        \n\t"
        "paddw   %%mm7, %%mm4        \n\t"
        "paddw   %%mm7, %%mm5        \n\t"
        "pmulhw  %%mm6, %%mm2        \n\t"
        "pmulhw  %%mm6, %%mm3        \n\t"
        "pmulhw  %%mm6, %%mm4        \n\t"
        "pmulhw  %%mm6, %%mm5        \n\t"
        "paddw    (%0), %%mm2        \n\t"
        "paddw    8(%0), %%mm3       \n\t"
        "paddw   16(%0), %%mm4       \n\t"
        "paddw   24(%0), %%mm5       \n\t"
        "movq    %%mm2, (%0)         \n\t"
        "movq    %%mm3, 8(%0)        \n\t"
        "movq    %%mm4, 16(%0)       \n\t"
        "movq    %%mm5, 24(%0)       \n\t"
        : 
        : "r" (&b[i]), "r" (&ref[i])
        : "memory", "mm2", "mm3", "mm4", "mm5"
    );
}
}
