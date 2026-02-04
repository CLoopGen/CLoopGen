#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *vector;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 114; i > 0; i--) {
        if (i % 2 == 0) {
            vector[i + 72] = vector[i];
        }
    }
}
