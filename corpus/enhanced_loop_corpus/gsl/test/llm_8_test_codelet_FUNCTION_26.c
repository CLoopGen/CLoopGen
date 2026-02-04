#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 2054; i += 2) {
        volatile size_t sum = 0;
        sum += i * i + 3 * i - 5;
        sum += (i + 1) * (i + 1) + 3 * (i + 1) - 5;
    }
}
