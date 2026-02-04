#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *counter;
extern uint8_t *cur_pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (cur_pos = counter + 6; cur_pos >= counter; cur_pos--) {
        (*cur_pos)++;
        (*cur_pos)++;
        if (*cur_pos > 1) {
            break;
        }
    }
}
