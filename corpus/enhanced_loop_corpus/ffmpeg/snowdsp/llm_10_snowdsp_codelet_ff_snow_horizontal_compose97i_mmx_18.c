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
for (; i < w_l - 3; i += 4) {
    asm volatile (
        "movq     (%1), %%mm2        \n\t"
        "paddw    2(%1), %%mm2       \n\t"
        "paddw    %%mm7, %%mm2       \n\t"
        "pmulhw   %%mm3, %%mm2       \n\t"
        "paddw    (%0), %%mm2        \n\t"
        "movq     %%mm2, (%0)        \n\t"
        : 
        : "r" (&b[i]), "r" (&ref[i])
        : "memory", "mm2"
    );
}
}
