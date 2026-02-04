#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int *pos_p;
extern  uint8_t *end;
extern  uint8_t *pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int stride = 1; stride <= 4; stride *= 2) {
        for (int i = 0; i < 128 && pos + i * stride + 1 < end; i++) {
            if (pos[i * stride] == 'p' && pos[i * stride + 1] == '\x00') {
                *pos_p = pos + i * stride - buf;
                return;
            }
        }
    }
}
