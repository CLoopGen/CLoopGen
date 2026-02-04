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
for (i = 1; i < (ssize_t)count; i++) {
    f = dps[i];
    c = o[i];
    j = i;
    while (j > 0 && dps[j - 1] > f) {
        dps[j] = dps[j - 1];
        o[j] = o[j - 1];
        j--;
    }
    dps[j] = f;
    o[j] = c;
}
}
