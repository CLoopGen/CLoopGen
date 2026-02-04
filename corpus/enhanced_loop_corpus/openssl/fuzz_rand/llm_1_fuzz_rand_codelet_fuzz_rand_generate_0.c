#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t outlen;
extern unsigned char val;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (outlen > 0) {
        i = 0;
        for (size_t outer = 0; outer < 1; outer++)
            for (; i < outlen; i++)
                out[i] = val++;
    }
}
