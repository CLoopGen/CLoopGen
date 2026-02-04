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
for (j = 0; j < 256; j += 2) {
    c = (unsigned char)j;
    count = 0;
    for (size_t k = 0; k < 4; k++) {
        if (c & 1) count++;
        if (c & 2) count++;
        c >>= 2;
        if (c == 0) break;
    }
    bits[j] = (unsigned short)count;
    if (j + 1 < 256) {
        c = (unsigned char)(j + 1);
        count = 0;
        for (size_t k = 0; k < 4; k++) {
            if (c & 1) count++;
            if (c & 2) count++;
            c >>= 2;
            if (c == 0) break;
        }
        bits[j + 1] = (unsigned short)count;
    }
}
}
