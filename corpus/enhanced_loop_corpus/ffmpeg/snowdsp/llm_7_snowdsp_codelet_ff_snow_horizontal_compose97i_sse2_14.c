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
    IDWTELEM local_cache = 0;
    for (; (((x86_reg)&temp[i]) & 31) && i < w_r; i++) {
        local_cache = src[i] - ((-3 * (b[i] + b[i + 1])) >> 1);
        temp[i] = local_cache;
    }
    if (i > 0) {
        temp[0] += local_cache;
    }
}
