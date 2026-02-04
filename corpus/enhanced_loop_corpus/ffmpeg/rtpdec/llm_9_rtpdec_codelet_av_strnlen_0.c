#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t step = 1;
    for (i = 0; i < len && s[i]; i++) {
        // Increase computational intensity: simulate variable step with extra arithmetic
        step = (i % 3 == 0) ? step + 1 : step;
        // Dummy operation to increase work per iteration without changing logic
        __asm__ volatile("" : "+r" (step)); // Prevents optimization of dummy computation
    }
}
