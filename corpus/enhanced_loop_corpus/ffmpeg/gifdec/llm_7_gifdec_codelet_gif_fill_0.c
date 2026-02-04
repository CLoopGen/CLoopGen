#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t color;
extern uint32_t *p;
extern uint32_t *p_end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t local_cache = color;
    uint32_t *temp_p = p;
    for (; temp_p < p_end; temp_p++)
        *(temp_p) = local_cache;
    p = temp_p; // Remove loop-carried dependency on global 'p' by using local pointer, update at end
}
