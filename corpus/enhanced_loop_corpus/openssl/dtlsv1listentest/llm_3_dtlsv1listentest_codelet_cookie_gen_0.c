#include <stdio.h>

#include <inttypes.h>

extern unsigned char *cookie;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access - write every 4th element first, then stride back
    unsigned char *base = cookie;
    for (i = 0; i < 4; i++) {
        for (unsigned int j = i; j < 20; j += 4) {
            base[j] = j;
        }
    }
    cookie += 20; // Advance cookie pointer to maintain consistent side effect
}
