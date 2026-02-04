#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t **in;
extern int len;
extern int shift;
extern int16_t *samples;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < len; i++) {
    unsigned int a = in[0][i];
    int b = in[1][i];
    a -= b >> 1;
    int sum = a + b;
    int diff = a - (b >> 2);
    (*samples++) = sum << shift;
    (*samples++) = a << shift;
    (*samples++) = diff << shift;
    (*samples++) = (sum + diff) << (shift > 0 ? shift - 1 : 0);
}
}
