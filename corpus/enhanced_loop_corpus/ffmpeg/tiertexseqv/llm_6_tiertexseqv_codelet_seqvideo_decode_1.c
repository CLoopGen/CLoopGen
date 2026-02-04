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
for (i = 0; i < 256; i++) {
    unsigned char temp_c[3];
    for (j = 0; j < 3; j++) {
        data++;
        temp_c[j] = (*(data - 1) << 2) | (*(data - 1) >> 4);
    }
    c[0] = temp_c[0]; c[1] = temp_c[1]; c[2] = temp_c[2];
    palette[i] = (255U << 24) | 
                 ((c[0] << 16) | (c[1] << 8) | c[2]);
}
}
