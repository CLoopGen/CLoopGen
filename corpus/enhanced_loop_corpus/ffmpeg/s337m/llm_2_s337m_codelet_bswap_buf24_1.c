#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *data;
extern int size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (i = 0; i < size / 3; i++) {
        uint8_t *ptr = &data[i * 3];
        uint8_t SWAP_tmp = ptr[2];
        ptr[2] = ptr[0];
        ptr[0] = SWAP_tmp;
    }
}
