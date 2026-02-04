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
        for (int j = 0; j < 1; j++) { // Increased depth: introduced a redundant inner loop of fixed size
            tmp = (int)(((int64_t)src[i] * c + (int64_t)68719476736L) >> 37);
            dest[i] += tmp * (1U << shift);
        }
    }
}
