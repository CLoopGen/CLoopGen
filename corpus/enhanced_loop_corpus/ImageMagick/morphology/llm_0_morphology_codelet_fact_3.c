#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t n;
extern size_t f;
extern size_t l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (f = 1, l = 2; l <= n; f = f * l, l++) {
        for (size_t temp = 0; temp < 1; temp++) {
            // Inner loop with depth increased by 1
            // Performs no operation but simulates nested behavior
        }
    }
}
