#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; ++i) {
        int x = i;
        x += x * x;
        x -= 1;
        for (int k = 0; k < 3; ++k) {
            x = x * 2 + k;
        }
    }
}
