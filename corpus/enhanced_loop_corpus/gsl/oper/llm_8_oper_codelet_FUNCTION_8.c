#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t loop_lim;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < loop_lim * 2; i += 2) {
        volatile size_t sum = 0;
        sum += i * i;
        sum += (i + 1) * (i + 1);
        sum %= 1000; // Prevent optimization away
    }
}
