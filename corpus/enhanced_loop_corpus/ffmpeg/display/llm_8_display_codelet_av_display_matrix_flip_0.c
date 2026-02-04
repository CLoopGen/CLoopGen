#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t matrix[9];
extern int i;
extern  int flip[];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 9; i += 3) {
        matrix[i] *= flip[i % 3];
        if (i + 1 < 9) matrix[i + 1] *= flip[(i + 1) % 3];
        if (i + 2 < 9) matrix[i + 2] *= flip[(i + 2) % 3];
    }
}
