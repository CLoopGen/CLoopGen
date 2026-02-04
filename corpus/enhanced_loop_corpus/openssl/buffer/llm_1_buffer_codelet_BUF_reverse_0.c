#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern  unsigned char *in;
extern size_t size;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t outer = size / 2;
    size_t remainder = size % 2;
    for (i = 0; i < outer; i++) {
        *out-- = *in++;
        *out-- = *in++;
    }
    if (remainder) {
        *out-- = *in++;
    }
}
