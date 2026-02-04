#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *bits;
extern uint32_t exit_at_level[33];
extern unsigned int i;
extern unsigned int p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t temp;
    for (i = 0; i < bits[p]; ++i) {
        temp = 1U << i;
        exit_at_level[i + 1] = temp;
    }
}
