#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *ch_assign;
extern int8_t *output_shift;
extern uint8_t max_matrix_channel;
extern int shift;
extern int inorder;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i <= max_matrix_channel; i++) {
    if (shift == 6 || output_shift[i] == shift) {
        if (ch_assign[i] != i) {
            inorder = 0;
        }
    } else {
        shift = 6;
        if (ch_assign[i] != i) {
            inorder = 0;
        }
    }
}
}
