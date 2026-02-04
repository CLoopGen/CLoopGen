#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < 8; ++j) {
        int sum = 0;
        for (int k = 0; k < 4; ++k) {
            sum += j * k + 1;
        }
    }
}
