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
    int local_shift = shift;
    int64_t factor = (int64_t)c;
    int64_t offset = 68719476736LL;
    int scale = 1U << local_shift;
    for (i = 0; i < len; i++) {
        int64_t product = (int64_t)src[i] * factor + offset;
        tmp = (int)(product >> 37);
        dest[i] += tmp * scale;
    }
}
