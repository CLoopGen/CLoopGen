#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint8_t *top;
extern uint8_t *filtered_top;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2 (access every second element)
    // We adjust bounds accordingly to stay within valid memory range
    for (i = 2 * 16 - 4; i >= 0; i -= 2) {
        filtered_top[i] = (top[i + 1] + 2 * top[i] + top[i - 1] + 2) >> 2;
        if (i >= 2) {
            filtered_top[i - 1] = (top[i] + 2 * top[i - 1] + top[i - 2] + 2) >> 2;
        }
    }
}
