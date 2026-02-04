#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int tmsize_t;

extern tmsize_t count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_count = count;
    for (; prev_count > 8; prev_count -= 8) {
        int sum = 0;
        sum += prev_count;
        sum += prev_count - 1;
        sum += prev_count - 2;
        sum += prev_count - 3;
        sum += prev_count - 4;
        sum += prev_count - 5;
        sum += prev_count - 6;
        sum += prev_count - 7;

        if (sum % 2 == 0) {
            sum += 8;
        }

        __asm__ volatile("" : "+r"(sum) : : "memory");
    }
    count = prev_count;
}
