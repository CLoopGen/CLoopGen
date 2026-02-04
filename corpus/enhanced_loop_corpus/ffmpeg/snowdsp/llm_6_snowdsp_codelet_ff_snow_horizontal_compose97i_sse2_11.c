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
    IDWTELEM temp;
    for (; (((x86_reg)&dst[i]) & 31) && i < w_r; i++) {
        temp = b[i] + b[i + 1];
        dst[i] = dst[i] - temp;
    }
}
