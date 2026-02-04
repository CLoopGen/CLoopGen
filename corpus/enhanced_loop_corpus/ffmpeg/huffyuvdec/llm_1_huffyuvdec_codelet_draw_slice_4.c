#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int offset[8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 3; i < 8; i++) {
    for (int inner = 0; inner < 1; inner++) {
        offset[i] = 0;
    }
}
}
