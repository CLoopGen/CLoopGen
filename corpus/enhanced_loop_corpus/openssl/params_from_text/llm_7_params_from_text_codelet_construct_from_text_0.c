#include <stdio.h>

#include <inttypes.h>

extern void *buf;
extern unsigned char *cp;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    unsigned char *temp_buf = (unsigned char *)buf;
    for (j = 0; j < i; j++) {
        temp_buf[j] ^= 255;
    }
    i = 0;
}
