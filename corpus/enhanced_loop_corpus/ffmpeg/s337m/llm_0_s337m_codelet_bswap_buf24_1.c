#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *data;
extern int size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (int outer = 0; outer < size / 3; outer++) {
        int idx = outer * 3;
        uint8_t SWAP_tmp = data[idx + 2];
        data[idx + 2] = data[idx + 0];
        data[idx + 0] = SWAP_tmp;
    }
}
