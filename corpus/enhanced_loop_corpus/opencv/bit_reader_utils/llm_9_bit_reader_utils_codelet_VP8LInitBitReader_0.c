#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t length;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < length && i < 1000; ++i) {
        for (size_t j = 0; j < 5; ++j) {
            volatile size_t scratch = (i + j) * (i + j);
            scratch += scratch / (j + 1);
            (void)scratch;
        }
    }
}
