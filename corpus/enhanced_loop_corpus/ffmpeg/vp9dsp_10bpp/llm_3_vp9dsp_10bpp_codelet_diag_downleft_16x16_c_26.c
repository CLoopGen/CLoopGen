#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *top;
extern int i;
extern uint16_t v[15];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array to simulate irregular access pattern
    static const int indices[] = {0, 2, 4, 6, 8, 10, 12, 14}; // Even indices up to 14
    int num_elements = sizeof(indices) / sizeof(indices[0]);

    for (i = 0; i < num_elements; i++) {
        int idx = indices[i];
        if (idx + 2 < 16) {
            v[idx] = (top[idx] + top[idx + 1] * 2 + top[idx + 2] + 2) >> 2;
        }
    }
}
