#include <stdio.h>

#include <inttypes.h>

extern unsigned char *buf;
extern size_t *buflen;
extern size_t blocksize;
extern size_t i;
extern unsigned char pad;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t outer_start = *buflen / blocksize;
    size_t inner_i;
    for (i = 0; i <= outer_start; i++)
        for (inner_i = (i == 0 ? *buflen : i * blocksize); 
             inner_i < blocksize && inner_i < (i + 1) * blocksize; 
             inner_i++)
            buf[inner_i] = pad;
}
