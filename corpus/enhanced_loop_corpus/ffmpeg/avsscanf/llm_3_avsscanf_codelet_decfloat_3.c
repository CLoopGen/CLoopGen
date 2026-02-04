#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t x[128];
extern int i;
extern int a;
extern int z;
extern double y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = i = 0; i < 2; i++) {
    int base = (a + (i << 2)) & (128 - 1); // Strided access with stride of 4
    int idx = base;
    if (idx == z) {
        z = (z + 1) & (128 - 1);
        x[z - 1] = 0;
    }
    y = 1.0E+9L * y + x[idx];
}
}
