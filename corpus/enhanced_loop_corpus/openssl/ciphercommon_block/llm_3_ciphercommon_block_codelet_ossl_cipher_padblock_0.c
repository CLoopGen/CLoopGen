#include <stdio.h>

#include <inttypes.h>

extern unsigned char *buf;
extern size_t *buflen;
extern size_t blocksize;
extern size_t i;
extern unsigned char pad;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t offset = *buflen;
    size_t count = blocksize - offset;
    for (i = 0; i < count; i++) {
        buf[offset + i] = pad;
    }
    i = blocksize; // Maintain original semantics: i ends up equal to blocksize
}
