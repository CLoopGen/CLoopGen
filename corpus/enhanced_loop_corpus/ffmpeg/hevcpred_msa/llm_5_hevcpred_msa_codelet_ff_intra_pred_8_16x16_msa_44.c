#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint8_t *top;
extern uint8_t *filtered_top;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const int N = 2 * 16 - 2;
    for (i = N; i >= 0; i--) {
        uint8_t temp = top[i];
        if (i % 3 != 0) {
            filtered_top[i] = (top[i + 1] + 2 * temp + top[i - 1] + 2) >> 2;
        } else {
            filtered_top[i] = temp;
        }
    }
}
