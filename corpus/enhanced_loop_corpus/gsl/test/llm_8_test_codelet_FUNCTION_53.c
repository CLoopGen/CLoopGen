#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t step = 3;
    for (i = 0; i < 3081; i += step) {
        volatile size_t x = i * i + 5;
        volatile size_t y = (x + i) / 2;
        volatile size_t z = x + y - i;
    }
}
