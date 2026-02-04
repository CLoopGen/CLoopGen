#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t outlen;
extern unsigned char val;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char temp_val = val;
    for (i = 0; i < outlen; i++) {
        out[i] = temp_val;
        temp_val++;
    }
    val = temp_val;
}
