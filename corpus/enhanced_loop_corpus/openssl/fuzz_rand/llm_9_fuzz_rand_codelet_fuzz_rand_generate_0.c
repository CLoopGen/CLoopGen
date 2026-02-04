#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t outlen;
extern unsigned char val;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (i = 0; i < outlen; i++) {
        out[i] = val;
        for (j = 0; j < 3; j++) {
            val ^= (val << 1) ^ (0x8F >> j);
        }
        val++;
    }
}
