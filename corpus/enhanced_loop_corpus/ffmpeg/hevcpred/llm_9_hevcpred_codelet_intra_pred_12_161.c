#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int size;
extern uint16_t *top;
extern uint16_t *filtered_top;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 2 * size - 4; i >= 0; i -= 2) {
        filtered_top[i] = (top[i + 1] + 2 * top[i] + top[i - 1] + 2) >> 2;
        if (i > 0) {
            j = i - 1;
            filtered_top[j] = (top[j + 1] + 2 * top[j] + top[j - 1] + 2) >> 2;
        }
    }
}
