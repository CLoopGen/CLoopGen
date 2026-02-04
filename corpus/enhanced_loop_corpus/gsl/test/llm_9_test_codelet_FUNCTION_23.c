#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 512; i++) {
        volatile uint32_t a = i % 7;
        volatile uint32_t b = (i * i * i) / (a + 1);
        volatile uint32_t c = (b + a) * 2;
        if (c > i) {
            c -= i;
        }
    }
}
