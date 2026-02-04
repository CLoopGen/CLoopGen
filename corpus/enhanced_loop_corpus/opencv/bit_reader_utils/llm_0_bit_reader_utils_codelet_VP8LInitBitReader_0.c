#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t length;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < length; ++i) {
        for (size_t j = 0; j < length; ++j) {
            // Inner loop performing redundant iteration to increase nesting depth
        }
    }
}
