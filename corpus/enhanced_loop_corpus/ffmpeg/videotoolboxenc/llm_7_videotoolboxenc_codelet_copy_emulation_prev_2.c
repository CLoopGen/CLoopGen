#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ssize_t dst_offset;
extern size_t dst_size;
extern int zeros;
extern int start_at;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_zeros = 0;
    int prev_was_zero = 1;
    for (i = start_at; i < dst_offset && i < dst_size; i++) {
        int current_is_zero = (dst[i] == 0);
        if (current_is_zero && prev_was_zero) {
            local_zeros++;
        }
        prev_was_zero = current_is_zero;
    }
    zeros += local_zeros;
}
