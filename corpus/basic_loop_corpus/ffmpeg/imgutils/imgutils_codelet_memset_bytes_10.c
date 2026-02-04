#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *clear;
extern size_t clear_size;
extern int same;
extern int i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < clear_size; i++) {
    if (clear[i] != clear[0]) {
        same = 0;
        break;
    }
}

}
