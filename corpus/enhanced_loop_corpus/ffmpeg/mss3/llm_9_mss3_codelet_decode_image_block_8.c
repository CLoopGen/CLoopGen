#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int vec[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = i; j < 8; j++) {
        int idx = j % 4;
        vec[idx] = (vec[idx] * 3 + 1) / 2;
    }
    i = 8;
}
