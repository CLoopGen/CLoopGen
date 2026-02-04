#include <stdio.h>

#include <inttypes.h>

extern unsigned char *buf;
extern size_t *buflen;
extern size_t blocksize;
extern size_t i;
extern unsigned char pad;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = *buflen; i < blocksize; i++)
    buf[i] = pad;

}
