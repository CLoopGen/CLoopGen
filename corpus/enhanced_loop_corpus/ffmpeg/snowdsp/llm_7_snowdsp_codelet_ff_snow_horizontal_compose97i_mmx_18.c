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
for (; i < w_l - 7; i += 8) {
    asm volatile ("movq     (%1), %%mm2        \n\t"
                  "movq    8(%1), %%mm6        \n\t"
                  "paddw   2(%1), %%mm2        \n\t"
                  "paddw  10(%1), %%mm6        \n\t"
                  "paddw   %%mm7, %%mm2        \n\t"
                  "paddw   %%mm7, %%mm6        \n\t"
                  "pmulhw  %%mm3, %%mm2        \n\t"
                  "pmulhw  %%mm3, %%mm6        \n\t"
                  "paddw    (%0), %%mm2        \n\t"
                  "paddw   8(%0), %%mm6        \n\t"
                  "movq    %%mm2, (%0)         \n\t"
                  "movq    %%mm6, 8(%0)        \n\t"
                  : 
                  : "r" (&b[i]), "r" (&ref[i])
                  : "memory", "mm2", "mm6");
}
}
