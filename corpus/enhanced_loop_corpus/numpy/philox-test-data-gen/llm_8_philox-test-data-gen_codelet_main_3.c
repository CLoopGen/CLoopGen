#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 1000 / 4UL * 8; i++) {
    for (j = 0; j < 8; j++) {
        volatile int x = i * j + 5;
        volatile int y = (x + i) * (j - 1);
        volatile int z = (y % 17) + (i & j);
    }
}
}
