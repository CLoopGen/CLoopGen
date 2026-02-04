#include <stdio.h>

#include <inttypes.h>

extern long x;
extern int i;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int temp_n = 0;
    long temp_x = x;
    for (i = 0; i < (sizeof(long) * 8); ++i) {
        temp_n += (int)(temp_x & 1L);
        temp_x >>= 1;
    }
    n = temp_n;
}
