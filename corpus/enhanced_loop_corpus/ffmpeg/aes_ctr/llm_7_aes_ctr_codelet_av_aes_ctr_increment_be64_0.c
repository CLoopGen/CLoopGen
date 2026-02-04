#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *counter;
extern uint8_t *cur_pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t carry = 0;
    for (ptrdiff_t i = 7; i >= 0; i--) {
        uint8_t sum = counter[i] + 1 + carry;
        carry = (sum == 0) ? 1 : 0;
        counter[i] = sum;
        if (!carry) {
            break;
        }
    }
}
