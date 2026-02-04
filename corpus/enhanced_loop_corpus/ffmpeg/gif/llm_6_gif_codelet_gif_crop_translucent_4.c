#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern  int linesize;
extern int *y_start;
extern int trans;
extern  int w;
extern int is_trans;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_is_trans = 1;
    uint8_t* base_ptr = &buf[linesize * *y_start];
    for (int i = 0; i < w; i++) {
        if (base_ptr[i] != trans) {
            local_is_trans = 0;
            break;
        }
    }
    is_trans = local_is_trans;
}
