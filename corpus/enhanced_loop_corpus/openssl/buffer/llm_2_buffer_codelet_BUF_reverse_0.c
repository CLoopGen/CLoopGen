#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern  unsigned char *in;
extern size_t size;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (i = 0; i < size; i += 2) {
        *out-- = in[i];
        if (i + 1 < size) {
            *(out - 1) = in[i + 1];
            out--;
        }
    }
}
