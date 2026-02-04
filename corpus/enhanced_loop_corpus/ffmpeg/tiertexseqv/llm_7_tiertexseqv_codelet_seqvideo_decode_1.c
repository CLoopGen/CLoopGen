#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned char *data;
extern int i;
extern int j;
extern unsigned char c[3];
extern uint32_t *palette;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
unsigned char local_c[3];
for (i = 0; i < 256; i++) {
    for (j = 0; j < 3; j++, data++) {
        uint8_t val = *data;
        local_c[j] = (val << 2) | (val >> 4);
    }
    palette[i] = (255U << 24) | 
                 ((local_c[0] << 16) | (local_c[1] << 8) | local_c[2]);
    c[0] = local_c[0]; c[1] = local_c[1]; c[2] = local_c[2];
}
}
