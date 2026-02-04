#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int i;
extern int first;
extern int last;
extern uint32_t *pal;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = first; i < last; i++, buf += 3) {
        uint32_t temp_val = (buf[0] << 18) | (buf[1] << 10) | (buf[2] << 2);
        temp_val |= 255U << 24;
        if (temp_val & (1U << 20)) {
            pal[i] = temp_val & 197379;
        } else {
            pal[i] = temp_val | ((temp_val >> 6) & 197379);
        }
    }
}
