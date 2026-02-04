#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *iv;
extern uint8_t indexbuf[8];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using pointer arithmetic and offset array
    uint8_t *iv_ptr = iv + 6;
    for (i = 0; i < 8; i++) {
        *(iv_ptr + i) ^= *(indexbuf + i);
    }
}
