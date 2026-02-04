#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern int zeros;
extern uint8_t *dst_end;
extern  uint8_t *src_end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t prev_src_val = 0;
    int consecutive_zeros = 0;
    uint8_t* write_ptr = dst;
    for (; src < src_end; src++) {
        uint8_t current = *src;
        if (consecutive_zeros == 2 && current <= 3) {
            if (write_ptr + 1 < dst_end) {
                *(write_ptr++) = 3;
            }
        }
        if (write_ptr < dst_end)
            *write_ptr = current;
        write_ptr++;
        if (current == 0 && prev_src_val == 0)
            consecutive_zeros = (consecutive_zeros == 2) ? 2 : 2; // lock at 2 after two consecutive
        else if (current == 0)
            consecutive_zeros = 1;
        else
            consecutive_zeros = 0;
        prev_src_val = current;
    }
    dst = write_ptr;
    zeros = consecutive_zeros;
}
