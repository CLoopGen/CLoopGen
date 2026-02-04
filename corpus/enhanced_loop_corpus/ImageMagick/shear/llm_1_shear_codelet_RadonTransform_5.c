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
    for (ssize_t shift = 0; shift < 8; shift++) {
        unsigned char temp_c = c >> shift;
        if ((temp_c & 1) == 1) {
            count++;
        }
    }
    bits[j] = (unsigned short)count;
}
}
