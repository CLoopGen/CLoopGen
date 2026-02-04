#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t count;
extern float dps[16];
extern float f;
extern ssize_t i;
extern ssize_t j;
extern unsigned char c;
extern unsigned char *o;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
size_t stride = 1;
for (i = stride; i < (ssize_t)count; i += stride) {
    for (j = i; j >= stride && dps[j] < dps[j - stride]; j -= stride) {
        f = dps[j];
        dps[j] = dps[j - stride];
        dps[j - stride] = f;
        c = o[j];
        o[j] = o[j - stride];
        o[j - stride] = c;
    }
}
}
