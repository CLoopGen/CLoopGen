#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *in;
extern size_t size_in;
extern size_t extra;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t local_i;
    size_t accumulated = extra;
    for (local_i = 0; local_i < size_in; local_i++) {
        accumulated += in[local_i] >= 128;
        in[local_i] ^= (accumulated & 1); // Introduce WAW and RAW dependency: write after read of in[i], and write affects future reads
    }
    extra = accumulated;
}
