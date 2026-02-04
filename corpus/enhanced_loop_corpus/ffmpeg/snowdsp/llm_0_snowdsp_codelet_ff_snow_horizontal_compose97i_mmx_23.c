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
        for (int j = i; j > i - 32 && j >= 0; j -= 16) {
            asm volatile ("movq        (%1), %%mm0       \n\t"
                          "movq       8(%1), %%mm2       \n\t"
                          "punpcklwd   (%2), %%mm0       \n\t"
                          "punpcklwd  8(%2), %%mm2       \n\t"
                          "movq       %%mm0, (%0)        \n\t"
                          "movq       %%mm2, 16(%0)      \n\t"
                          "punpckhwd   (%2), %%mm0       \n\t"
                          "punpckhwd  8(%2), %%mm2       \n\t"
                          "movq       %%mm0, 8(%0)       \n\t"
                          "movq       %%mm2, 24(%0)      \n\t"
                          :
                          : "r" (&b[j]), "r" (&b[j >> 1]), "r" (&temp[j >> 1])
                          : "memory");
        }
    }
}
