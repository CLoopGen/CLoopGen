#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *left;
extern int i;
extern uint8_t v[30];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < 16 - 2; i++) {
        v[(i - 1) * 2] = (left[i] + left[i - 1] + 1) >> 1;
        v[(i - 1) * 2 + 1] = (left[i - 1] + left[i] * 2 + left[i + 1] + 2) >> 2;
    }
    // Introduce a final iteration fix-up to preserve semantic scope
    if (16 - 2 > 0) {
        v[(16 - 3) * 2] = (left[16 - 2] + left[16 - 2 + 1] + 1) >> 1;
        v[(16 - 3) * 2 + 1] = (left[16 - 2] + left[16 - 2 + 1] * 2 + left[16 - 2 + 2] + 2) >> 2;
    }
}
