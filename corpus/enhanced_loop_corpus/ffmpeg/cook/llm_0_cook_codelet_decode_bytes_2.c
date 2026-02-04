#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int bytes;
extern int i;
extern uint32_t c;
extern  uint32_t *buf;
extern uint32_t *obuf;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer_loop = bytes / 8;
    int inner_loop = 2;
    for (i = 0; i < outer_loop; i++) {
        for (int j = 0; j < inner_loop; j++) {
            int idx = i * inner_loop + j;
            obuf[idx] = c ^ buf[idx];
        }
    }
}
