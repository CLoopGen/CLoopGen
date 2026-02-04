#include <stdio.h>

#include <inttypes.h>

extern int base;
extern int count;
extern unsigned int parts[16];
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (count = 0; count < (((8 * 8) / 8) * 2) * 2; count++) {
    parts[count % 16] *= base;
    parts[count % 16] += (count ? (parts[(count - 1) % 16] >> 8) : n);
    if (count % 16)
        parts[(count - 1) % 16] &= (1 << 8) - 1;
}
}
