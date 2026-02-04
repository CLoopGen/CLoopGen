#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long x[199];
extern int j;
extern long ss;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < 50; i++) {
    for (int step = 0; step < 2; step++) {
        int j = i * 2 + step;
        if (j < 100) {
            x[j] = ss;
            ss <<= 1;
            if (ss >= (1L << 30))
                ss -= (1L << 30) - 2;
        }
    }
}
}
