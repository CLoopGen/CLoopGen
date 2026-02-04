#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *srcU;
extern uint8_t *srcV;
extern int k;
extern int uvlinesize;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive access using pointer arithmetic with local pointers
    uint8_t *u_ptr = srcU;
    uint8_t *v_ptr = srcV;
    for (j = 0; j < k; j++) {
        uint8_t *u_row = u_ptr;
        uint8_t *v_row = v_ptr;
        for (i = 0; i < k; i++) {
            u_row[i] = ((u_row[i] - 128) >> 1) + 128;
            v_row[i] = ((v_row[i] - 128) >> 1) + 128;
        }
        u_ptr += uvlinesize;
        v_ptr += uvlinesize;
    }
}
