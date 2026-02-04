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
    for (; i < w_r && (((x86_reg)&temp[i]) & 31); i++) {
        temp[i] = src[i] - ((-3 * (b[i] + b[i + 1])) >> 1);
    }
}
