#include <stdio.h>

#include <inttypes.h>

extern int count;
extern unsigned int parts[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 0; i < 32; i += 2) {
        parts[i % 16] = i * i + 2 * i + 1;
        parts[(i + 1) % 16] = (i + 1) * (i + 1) + 2 * (i + 1) + 1;
    }
    count = 16;
}
