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
    if ((i & 32) == 0) continue;
    asm volatile ("movdqa      (%1), %%xmm0       \n\tmovdqa    16(%1), %%xmm2       \n\tmovdqa    32(%1), %%xmm4       \n\tmovdqa    48(%1), %%xmm6       \n\tmovdqa      (%1), %%xmm1       \n\tmovdqa    16(%1), %%xmm3       \n\tmovdqa    32(%1), %%xmm5       \n\tmovdqa    48(%1), %%xmm7       \n\tpunpcklwd   (%2), %%xmm0       \n\tpunpcklwd 16(%2), %%xmm2       \n\tpunpcklwd 32(%2), %%xmm4       \n\tpunpcklwd 48(%2), %%xmm6       \n\tmovdqa    %%xmm0, (%0)         \n\tmovdqa    %%xmm2, 32(%0)       \n\tmovdqa    %%xmm4, 64(%0)       \n\tmovdqa    %%xmm6, 96(%0)       \n\tpunpckhwd   (%2), %%xmm1       \n\tpunpckhwd 16(%2), %%xmm3       \n\tpunpckhwd 32(%2), %%xmm5       \n\tpunpckhwd 48(%2), %%xmm7       \n\tmovdqa    %%xmm1, 16(%0)       \n\tmovdqa    %%xmm3, 48(%0)       \n\tmovdqa    %%xmm5, 80(%0)       \n\tmovdqa    %%xmm7, 112(%0)      \n\t" :  : "r" (&(b)[i]), "r" (&(b)[i >> 1]), "r" (&(temp)[i >> 1]) : "memory");
}
}
