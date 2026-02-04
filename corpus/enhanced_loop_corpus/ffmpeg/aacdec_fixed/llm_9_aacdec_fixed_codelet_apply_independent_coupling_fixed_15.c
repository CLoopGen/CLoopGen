#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int c;
extern int shift;
extern int tmp;
extern  int *src;
extern unsigned int *dest;
extern  int len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len; i++) {
        int64_t scaled_val = (int64_t)src[i] * c;
        int64_t offset_val = scaled_val + (int64_t)68719476736L;
        int shifted_val = (int)(offset_val >> 37);
        int multiplier = (1U << shift);
        dest[i] = (unsigned int)((int)dest[i] + shifted_val * multiplier);
    }
}
