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
    asm volatile ("movdqa      (%1), %%xmm0       \n\t"
                  "movdqa    16(%1), %%xmm2       \n\t"
                  "movdqa    32(%1), %%xmm4       \n\t"
                  "movdqa    48(%1), %%xmm6       \n\t"
                  "movdqa      (%1), %%xmm1       \n\t"
                  "movdqa    16(%1), %%xmm3       \n\t"
                  "movdqa    32(%1), %%xmm5       \n\t"
                  "movdqa    48(%1), %%xmm7       \n\t"
                  "punpcklwd   (%2), %%xmm0       \n\t"
                  "punpcklwd 16(%2), %%xmm2       \n\t"
                  "punpcklwd 32(%2), %%xmm4       \n\t"
                  "punpcklwd 48(%2), %%xmm6       \n\t"
                  "movdqa    %%xmm0, (%0)         \n\t"
                  "movdqa    %%xmm2, 32(%0)       \n\t"
                  "movdqa    %%xmm4, 64(%0)       \n\t"
                  "movdqa    %%xmm6, 96(%0)       \n\t"
                  "punpckhwd   (%2), %%xmm1       \n\t"
                  "punpckhwd 16(%2), %%xmm3       \n\t"
                  "punpckhwd 32(%2), %%xmm5       \n\t"
                  "punpckhwd 48(%2), %%xmm7       \n\t"
                  "movdqa    %%xmm1, 16(%0)       \n\t"
                  "movdqa    %%xmm3, 48(%0)       \n\t"
                  "movdqa    %%xmm5, 80(%0)       \n\t"
                  "movdqa    %%xmm7, 112(%0)      \n\t"
                  :
                  : "r" (&b[i]), "r" (&b[i - 32]), "r" (&temp[i])
                  : "memory", "xmm0", "xmm1", "xmm2", "xmm3", "xmm4", "xmm5", "xmm6", "xmm7");
}
}
