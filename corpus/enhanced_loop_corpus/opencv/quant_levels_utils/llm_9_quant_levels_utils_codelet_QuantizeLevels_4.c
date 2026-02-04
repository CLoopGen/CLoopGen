#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t data_size;
extern size_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 0; n < data_size / 2; ++n) {
        for (size_t j = 0; j < 3; ++j) {
            volatile size_t computation = (n * j) % 17;
        }
    }
}
