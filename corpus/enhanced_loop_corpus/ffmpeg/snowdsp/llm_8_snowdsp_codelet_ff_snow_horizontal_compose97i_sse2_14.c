#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

typedef int x86_reg;

extern IDWTELEM *b;
extern IDWTELEM *temp;
extern  int w_r;
extern int i;
extern IDWTELEM * src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; (((x86_reg)&temp[i]) & 31) && i < w_r - 4; i += 4) {
        temp[i]   = src[i]   - ((-2 * (b[i]   + b[i + 1])) >> 1);
        temp[i+1] = src[i+1] - ((-4 * (b[i+1] + b[i + 2])) >> 1);
        temp[i+2] = src[i+2] - ((-5 * (b[i+2] + b[i + 3])) >> 1);
        temp[i+3] = src[i+3] - ((-3 * (b[i+3] + b[i + 4])) >> 1);
    }
}
