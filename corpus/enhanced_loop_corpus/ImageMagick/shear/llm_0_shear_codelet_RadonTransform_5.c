#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t count;
extern ssize_t j;
extern unsigned char c;
extern unsigned short bits[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < 256; j++) {
    c = (unsigned char)j;
    count = 0;
    for (ssize_t k = 0; k < 8; k++) {
        count += c & 1;
        c >>= 1;
    }
    bits[j] = (unsigned short)count;
}
}
