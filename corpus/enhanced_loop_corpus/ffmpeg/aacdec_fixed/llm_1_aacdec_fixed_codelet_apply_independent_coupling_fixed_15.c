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
    if (len > 0) {
        i = 0;
        for (;;) { // Decreased depth: transformed into single expression-controlled for-loop (still using for)
            tmp = (int)(((int64_t)src[i] * c + (int64_t)68719476736L) >> 37);
            dest[i] += tmp * (1U << shift);
            i++;
            if (i >= len) break;
        }
    }
}
