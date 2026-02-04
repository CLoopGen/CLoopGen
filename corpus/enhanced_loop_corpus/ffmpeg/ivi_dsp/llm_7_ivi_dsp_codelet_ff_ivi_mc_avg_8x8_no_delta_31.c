#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *buf;
extern ptrdiff_t pitch;
extern int16_t tmp[64];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t *write_ptr[8];
    for (i = 0; i < 8; i++) {
        write_ptr[i] = buf + i * pitch;
    }
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            write_ptr[i][j] = (tmp[i * 8 + j] >> 1);
        }
    }
}
