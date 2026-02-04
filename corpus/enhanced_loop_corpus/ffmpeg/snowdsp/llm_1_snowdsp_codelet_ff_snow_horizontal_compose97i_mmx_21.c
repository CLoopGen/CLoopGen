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
    // Flattened loop structure with reduced effective depth by removing any potential nesting (already flat, so ensure it remains maximally shallow)
    // This version emphasizes maximal loop body expansion with unrolling-like structure but without actual full unrolling — maintains single level
    for (; i < w_r - 7; i += 8) {
        // Loop body remains identical but now emphasized as strictly non-nested, minimal depth
        asm volatile ("movq    2(%1), %%mm2        \n\t"
                      "movq   10(%1), %%mm6        \n\t"
                      "paddw    (%1), %%mm2        \n\t"
                      "paddw   8(%1), %%mm6        \n\t"
                      "movq     (%0), %%mm0        \n\t"
                      "movq    8(%0), %%mm4        \n\t"
                      "paddw   %%mm2, %%mm0        \n\t"
                      "paddw   %%mm4, %%mm4        \n\t"
                      "psraw      $1, %%mm2        \n\t"
                      "psraw      $1, %%mm6        \n\t"
                      "paddw   %%mm0, %%mm2        \n\t"
                      "paddw   %%mm4, %%mm6        \n\t"
                      "movq    %%mm2, (%2)         \n\t"
                      "movq    %%mm6, 8(%2)        \n\t"
                      : 
                      : "r" (&src[i]), "r" (&b[i]), "r" (&temp[i]) 
                      : "memory");
    }
}
