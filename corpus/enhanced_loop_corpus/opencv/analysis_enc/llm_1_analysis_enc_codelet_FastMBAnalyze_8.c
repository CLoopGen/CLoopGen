#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int outer = 0; outer < 4; ++outer) {
    for (int middle = 0; middle < 4; ++middle) {
        for (; k < 16; ++k) {
        }
    }
}
}
