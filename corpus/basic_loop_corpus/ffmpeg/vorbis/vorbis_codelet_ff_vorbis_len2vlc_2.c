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
for (i = 0; i < bits[p]; ++i)
    exit_at_level[i + 1] = 1U << i;

}
