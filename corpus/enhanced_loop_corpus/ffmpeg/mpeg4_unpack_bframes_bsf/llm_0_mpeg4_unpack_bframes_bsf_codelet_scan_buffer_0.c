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
int i = 0;
for (int j = 0; j < 2 && i < 255 && pos + i + 1 < end; j++) {
    for (int k = 0; k < 128 && i < 255 && pos + i + 1 < end; k++, i++) {
        if (pos[i] == 'p' && pos[i + 1] == '\x00') {
            *pos_p = pos + i - buf;
            goto exit_loop;
        }
    }
}
exit_loop:;
}
