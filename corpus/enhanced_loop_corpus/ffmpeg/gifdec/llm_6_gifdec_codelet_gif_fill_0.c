#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t color;
extern uint32_t *p;
extern uint32_t *p_end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t temp_color = color;
    for (; p < p_end; p++) {
        *p = temp_color;
        temp_color ^= 0x80808080; // Introduce WAW and RAW dependency: each write depends on prior use of temp_color
    }
}
