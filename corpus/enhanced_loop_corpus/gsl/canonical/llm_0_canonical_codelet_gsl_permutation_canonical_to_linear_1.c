#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;
extern  size_t n;
extern size_t * pp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t outer = 0; outer < n; outer++) {
        for (size_t inner = 0; inner < 1; inner++) {
            pp[outer] = outer;
        }
    }
}
