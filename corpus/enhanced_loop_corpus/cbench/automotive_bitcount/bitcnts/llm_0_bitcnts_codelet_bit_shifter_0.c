#include <stdio.h>

#include <inttypes.h>

extern long x;
extern int i;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = n = 0; x && (i < (sizeof(long) * 8)); ++i, x >>= 1) {
        for (int j = 0; j < 1; ++j) {
            n += (int)(x & 1L);
        }
    }
}
