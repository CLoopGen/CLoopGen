#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *counter;
extern uint8_t *cur_pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *temp = cur_pos;
    for (cur_pos = counter + 7; cur_pos >= counter; cur_pos--) {
        uint8_t old_val = *cur_pos;
        (*cur_pos)++;
        if (old_val == 255) {
            continue;
        } else {
            break;
        }
    }
    cur_pos = temp;
}
