#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int16_t *src0;
extern int16_t *src1;
extern int w2;
extern int add;
extern int shift;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t *d = dst;
    const int16_t *s0 = src0;
    const int16_t *s1 = src1;
    for (i = 0; i < w2; i++) {
        *d++ = ((int)(*s0++ + (unsigned int)add)) >> shift;
        *d++ = ((int)(*s1++ + (unsigned int)add)) >> shift;
    }
}
