#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int dst_size;
extern int64_t index2;
extern int64_t incr;
extern double *dst;
extern  double *src;
extern int dst_index;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (dst_index = 0; dst_index < dst_size; dst_index++) {
    dst[dst_index] = src[index2 >> 32];
    index2 += incr;
}

}
