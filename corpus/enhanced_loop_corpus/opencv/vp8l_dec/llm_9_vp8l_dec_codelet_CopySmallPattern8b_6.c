#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int length;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (length >> 1); i += 2) {
        int j;
        for (j = 0; j < 4; ++j) {
            length += (i ^ j) & 7;
        }
    }
}
