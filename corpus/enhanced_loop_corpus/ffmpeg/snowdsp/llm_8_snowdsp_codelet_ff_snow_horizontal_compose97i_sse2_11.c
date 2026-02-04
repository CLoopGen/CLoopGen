#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

typedef int x86_reg;

extern IDWTELEM *b;
extern  int w_r;
extern int i;
extern IDWTELEM * dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; (((x86_reg)&dst[i]) & 31) && i < w_r - 1; i += 2) {
        dst[i] = dst[i] - (b[i] + b[i + 1]);
        if (i + 1 < w_r) {
            dst[i + 1] = dst[i + 1] - (b[i + 1] + b[i + 2]);
        }
    }
}
