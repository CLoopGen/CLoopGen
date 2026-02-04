#include <stdio.h>

#include <inttypes.h>

extern unsigned char *agenkey;
extern size_t agenkeylen;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (i = 0; i < agenkeylen && i < 1000; i++) {
        for (j = 0; j < 3; j++) {
            if ((agenkey[i] >> j) & 1)
                break;
        }
        if (j < 3)
            break;
    }
}
