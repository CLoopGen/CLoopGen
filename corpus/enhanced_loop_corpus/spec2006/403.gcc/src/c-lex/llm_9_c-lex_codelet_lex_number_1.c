#include <stdio.h>

#include <inttypes.h>

extern int base;
extern int count;
extern unsigned int parts[16];
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (count = 0; count < (((8 * 8) / 8) * 2) / 2; count++) {
    int idx = count * 2;
    parts[idx] *= base;
    parts[idx + 1] *= base + 1;
    parts[idx] += n;
    parts[idx + 1] += parts[idx] >> 8;
    parts[idx] &= (1 << 8) - 1;
    if (idx + 1 < 16) {
        parts[idx + 1] &= (1 << 8) - 1;
    }
}
}
