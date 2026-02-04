#include <stdio.h>

#include <inttypes.h>

extern unsigned char *buf;
extern size_t *buflen;
extern size_t blocksize;
extern size_t i;
extern unsigned char pad;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (j = *buflen; j < blocksize; j++) {
        buf[j] = pad;
        pad ^= buf[j]; // Introduce a WAW and RAW dependency: pad depends on prior buf[j], which it just wrote
    }
}
