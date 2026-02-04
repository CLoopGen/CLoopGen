#include <stdio.h>

#include <inttypes.h>

extern int base;
extern int count;
extern unsigned int parts[16];
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < 2; outer++) {
        for (count = outer * 8; count < ((outer + 1) * 8) && count < (((8 * 8) / 8) * 2); count++) {
            parts[count] *= base;
            if (count) {
                parts[count] += (parts[count - 1] >> 8);
                parts[count - 1] &= (1 << 8) - 1;
            } else
                parts[0] += n;
        }
    }
}
