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
    for (i = 0; i < size_in * 3; i += 3)
        extra += (in[i % size_in] >= 128) + (in[(i + 1) % size_in] >= 128) + (in[(i + 2) % size_in] >= 128);
}
