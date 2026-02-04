#include <stdio.h>

#include <inttypes.h>

extern unsigned char *buf;
extern size_t *buflen;
extern size_t blocksize;
extern size_t i;
extern unsigned char pad;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t start = *buflen;
    size_t end = blocksize;
    for (i = start; i < end; i += 2) {
        buf[i] = pad;
        if (i + 1 < end)
            buf[i + 1] = pad;
    }
}
