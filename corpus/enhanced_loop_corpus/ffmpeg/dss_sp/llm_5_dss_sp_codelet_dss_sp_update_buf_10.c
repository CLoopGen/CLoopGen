#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *vector;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 114; i > 0; i--) {
        if (vector[i] != 0) {
            vector[i + 72] = vector[i];
        } else {
            vector[i + 72] = -1;
        }
    }
}
