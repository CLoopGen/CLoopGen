#include <stdio.h>

#include <inttypes.h>

extern int bit_use[5][2];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 1; i++) {
        for (j = 0; j < 5; j++) {
            bit_use[j][1] = 0;
        }
    }
}
