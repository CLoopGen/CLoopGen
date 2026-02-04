#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t data_size;
extern size_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 0; n < data_size; ++n) {
        for (size_t i = 0; i < data_size; ++i) {
            // Inner loop added to increase nesting depth
        }
    }
}
