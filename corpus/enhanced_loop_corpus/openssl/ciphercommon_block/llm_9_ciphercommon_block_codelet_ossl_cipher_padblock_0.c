#include <stdio.h>

#include <inttypes.h>

extern unsigned char *buf;
extern size_t *buflen;
extern size_t blocksize;
extern size_t i;
extern unsigned char pad;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t limit = blocksize > *buflen ? blocksize : *buflen;
    for (i = *buflen; i < limit; i += 4) {
        buf[i] = pad;
        if (i + 1 < blocksize) buf[i + 1] = pad;
        if (i + 2 < blocksize) buf[i + 2] = pad;
        if (i + 3 < blocksize) buf[i + 3] = pad;
    }
}
