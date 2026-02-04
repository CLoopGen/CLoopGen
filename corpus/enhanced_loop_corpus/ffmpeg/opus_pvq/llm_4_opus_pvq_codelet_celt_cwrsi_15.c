#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t K;
extern uint32_t i;
extern uint32_t p;
extern  uint32_t *row;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = row[K]; p > i && K > 0; p = row[K])
        K--;
}
