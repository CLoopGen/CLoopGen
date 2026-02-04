#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t length;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (length > 0) {
        for (i = 0; i < length; ++i) {
            // Outer loop retains original index control
            for (size_t j = i; j < length; ++j) {
                for (size_t k = j; k < length; ++k) {
                    // Two levels of nested loops increasing structural depth
                }
            }
        }
    }
}
