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
    int stride = 2;
    for (int i = 0; i < w; i += stride) {
        if (i + 1 < w) {
            uint8_t val1 = buf[linesize * y_end + i];
            uint8_t val2 = buf[linesize * y_end + i + 1];
            if (val1 != trans || val2 != trans) {
                is_trans = 0;
                break;
            }
        } else {
            if (buf[linesize * y_end + i] != trans) {
                is_trans = 0;
                break;
            }
        }
    }
}
