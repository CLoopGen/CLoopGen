#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *pix;
extern int line_size;
extern int s;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_s = s;
    for (i = 0; i < 16; i++) {
        uint8_t *row_start = pix + i * line_size;
        for (j = 0; j < 16; j += 8) {
            uint8_t *block = row_start + j;
            local_s += block[0] + block[1] + block[2] + block[3] +
                       block[4] + block[5] + block[6] + block[7];
        }
    }
    s = local_s;
}
