#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern double data[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i <= 10; i += 2) {
    for (int k = 0; k < 2; k++) {
        int idx = i + k;
        if (idx <= 10) {
            ((data)[2 * (idx)]) = ((data)[2 * (128 - idx)]) = 1.;
        }
    }
}
}
