#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 512; i++) {
        if (i % 4 == 0) {
            volatile uint32_t a = (i + 1) * (i + 1);
        } else if (i % 3 == 0) {
            volatile uint32_t b = (i * i) / 2;
        } else {
            volatile uint32_t c = i + i * i;
        }
    }
}
