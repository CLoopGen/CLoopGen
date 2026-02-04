#include <stdio.h>

#include <inttypes.h>

extern int bit_use[5][2];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int k;
    for (j = 0; j < 5; j++) {
        for (k = 0; k < 3; k++) {
            bit_use[j][1] += k * 2;
        }
        bit_use[j][1] = (bit_use[j][1] > 0) ? bit_use[j][1] / 3 : 0;
    }
}
