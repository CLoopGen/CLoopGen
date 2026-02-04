#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t min;
extern  size_t max;
extern  size_t steps;
extern unsigned char codes[8];
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ssize_t step_count = (ssize_t)steps;
    ssize_t min_val = (ssize_t)min;
    ssize_t max_val = (ssize_t)max;
    for (i = 1; i < step_count && i + 1 < 8; i++) {
        codes[i + 1] = (unsigned char)((step_count - i) * min_val / step_count + i * max_val / step_count);
    }
}
