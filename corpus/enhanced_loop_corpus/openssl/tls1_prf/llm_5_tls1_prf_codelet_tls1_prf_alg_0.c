#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t olen;
extern size_t i;
extern unsigned char *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < olen; i++) {
        if ((i & 7) != 0) { // Process only every 8th element otherwise skip
            continue;
        }
        out[i] ^= tmp[i];
    }
}
