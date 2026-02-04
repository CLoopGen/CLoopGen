#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *orig;
extern int16_t rem[64];
extern int i;
extern int dc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    int base = i * 8;
    for (int k = 0; k < 8; k++) {
        int idx = base + k;
        rem[idx] = dc - (orig[idx] << 6);
    }
}
}
