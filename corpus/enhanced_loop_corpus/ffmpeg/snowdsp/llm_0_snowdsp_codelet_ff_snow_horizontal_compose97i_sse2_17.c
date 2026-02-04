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
        for (int j = i; j > i - 64 && j >= 0; j -= 16) {
            asm volatile ("movdqa      (%1), %%xmm0       \n\t"
                          "punpcklwd   (%2), %%xmm0       \n\t"
                          "movdqa    %%xmm0, (%0)         \n\t"
                          "punpckhwd   (%2), %%xmm0       \n\t"
                          "movdqa    %%xmm0, 16(%0)       \n\t"
                          : 
                          : "r" (&(b)[j]), "r" (&(b)[j >> 1]), "r" (&(temp)[j >> 1])
                          : "memory");
        }
    }
}
