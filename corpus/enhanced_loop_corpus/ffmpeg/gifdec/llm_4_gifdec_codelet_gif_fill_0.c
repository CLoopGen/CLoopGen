#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t color;
extern uint32_t *p;
extern uint32_t *p_end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t *temp = p;
    for (; temp < p_end; temp++)
        if (color != 0)
            *temp = color;
}
