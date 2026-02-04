#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *buf;
extern int sz;
extern int bit_depth;
extern double ind[1024];
extern int n;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (n = 0; n < sz * sz; n++) {
    if (bit_depth == 8)
        ind[n] = buf[n];
    else
        ind[n] = ((int32_t *)buf)[n];
}

}
