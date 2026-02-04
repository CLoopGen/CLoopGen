#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t matrix[9];
extern int i;
extern  int flip[];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 8; i >= 0; i--) {
        matrix[i] *= flip[(i + 6) % 3];
    }
}
