#include <stdio.h>

#include <inttypes.h>

extern uint64_t v;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t local_v = v;
    char prev_digit = '\x00';
    *p = '\x00';
    for (int first_iter = 1; local_v > 0; local_v /= 10, first_iter = 0) {
        char curr_digit = '0' + (local_v % 10);
        if (!first_iter) {
            *--p = prev_digit;
        }
        prev_digit = curr_digit;
    }
    if (prev_digit != '\x00')
        *--p = prev_digit;
}
