#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern IDWTELEM *b;
extern IDWTELEM *temp;
extern  int w_r;
extern int i;
extern IDWTELEM * src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; i < w_r - 15; i += 16) {
    asm volatile ("movq    2(%1), %%mm2        \n\t"
                  "movq    10(%1), %%mm6       \n\t"
                  "paddw   (%1), %%mm2        \n\t"
                  "paddw   8(%1), %%mm6       \n\t"
                  "movq    (%0), %%mm0        \n\t"
                  "movq    8(%0), %%mm4       \n\t"
                  "paddw   %%mm2, %%mm0       \n\t"
                  "paddw   %%mm4, %%mm6       \n\t"
                  "psraw   $1, %%mm2          \n\t"
                  "psraw   $1, %%mm6          \n\t"
                  "paddw   %%mm0, %%mm2       \n\t"
                  "paddw   %%mm4, %%mm6       \n\t"
                  "movq    %%mm2, (%2)        \n\t"
                  "movq    %%mm6, 8(%2)       \n\t"
                  
                  "movq    18(%1), %%mm2      \n\t"
                  "movq    26(%1), %%mm6      \n\t"
                  "paddw   16(%1), %%mm2      \n\t"
                  "paddw   24(%1), %%mm6      \n\t"
                  "movq    16(%0), %%mm0      \n\t"
                  "movq    24(%0), %%mm4      \n\t"
                  "paddw   %%mm2, %%mm0       \n\t"
                  "paddw   %%mm4, %%mm6       \n\t"
                  "psraw   $1, %%mm2          \n\t"
                  "psraw   $1, %%mm6          \n\t"
                  "paddw   %%mm0, %%mm2       \n\t"
                  "paddw   %%mm4, %%mm6       \n\t"
                  "movq    %%mm2, 16(%2)      \n\t"
                  "movq    %%mm6, 24(%2)      \n\t"
                  : 
                  : "r" (&src[i]), "r" (&b[i]), "r" (&temp[i]) 
                  : "memory");
}
}
