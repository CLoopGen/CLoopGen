#include <stdio.h>

#include <inttypes.h>

extern unsigned char *agenkey;
extern size_t agenkeylen;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t step = 2;
    for (i = 0; i < agenkeylen; i += step) {
        if (i + 1 < agenkeylen) {
            if (agenkey[i] != 0 || agenkey[i + 1] != 0)
                break;
        } else {
            if (agenkey[i] != 0)
                break;
        }
    }
}
