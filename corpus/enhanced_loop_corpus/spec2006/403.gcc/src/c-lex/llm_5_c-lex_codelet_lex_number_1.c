#include <stdio.h>

#include <inttypes.h>

extern int base;
extern int count;
extern unsigned int parts[16];
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (count = 0; count < (((8 * 8) / 8) * 2); count++) {
        parts[count] *= base;
        if (!count) {
            parts[0] += n;
            continue;
        }
        parts[count] += (parts[count - 1] >> 8);
        parts[count - 1] &= (1 << 8) - 1;
    }
}
