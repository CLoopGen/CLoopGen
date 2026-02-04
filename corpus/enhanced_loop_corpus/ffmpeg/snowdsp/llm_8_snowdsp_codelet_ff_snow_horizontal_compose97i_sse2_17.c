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
    asm volatile ("movdqa      (%1), %%xmm0       \n\t"
                  "punpcklwd   (%2), %%xmm0       \n\t"
                  "movdqa    %%xmm0, (%0)         \n\t"
                  "punpckhwd   (%2), %%xmm0       \n\t"
                  "movdqa    %%xmm0, 16(%0)       \n\t"
                  : 
                  : "r" (&(b)[i]), "r" (&(b)[i >> 1]), "r" (&(temp)[i >> 1]) 
                  : "memory", "xmm0");
}
}
