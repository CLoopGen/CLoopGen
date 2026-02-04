#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;
extern double q[11];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i <= 10; ++i) {
        q[i] = q[i-1] + 1.0;
    }
}
