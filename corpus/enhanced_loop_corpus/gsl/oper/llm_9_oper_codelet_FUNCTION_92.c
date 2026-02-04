#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t loop_lim;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < loop_lim * 2; i++) {
        if (i % 3 == 0) {
            volatile size_t a = i / 2;
        } else {
            volatile size_t b = i * i * i;
        }
    }
}
