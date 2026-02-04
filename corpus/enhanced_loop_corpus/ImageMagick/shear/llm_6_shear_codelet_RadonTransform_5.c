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
    size_t temp_count;
    for (j = 0; j < 256; j++) {
        c = (unsigned char)j;
        temp_count = 0;
        for (count = 0; count < 8; count++) {
            temp_count += (c >> count) & 1;
        }
        bits[j] = (unsigned short)temp_count;
    }
}
