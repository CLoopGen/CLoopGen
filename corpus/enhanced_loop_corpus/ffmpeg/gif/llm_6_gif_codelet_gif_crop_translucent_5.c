#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern  int linesize;
extern int trans;
extern  int w;
extern int y_end;
extern int is_trans;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_is_trans = is_trans;
    for (int i = 0; i < w; i++) {
        uint8_t temp = buf[linesize * y_end + i];
        if (temp != trans) {
            local_is_trans = 0;
        }
    }
    is_trans = local_is_trans;
}
