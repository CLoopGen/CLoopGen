#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern  int linesize;
extern int *y_start;
extern int trans;
extern int x_end;
extern int y_end;
extern int is_trans;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    is_trans = 1;
    int stride = linesize;
    int offset = x_end;
    int limit = y_end;
    int start = *y_start;
    for (int i = start; i < limit && is_trans; i++) {
        if (buf[stride * i + offset] == trans) {
            continue;
        } else {
            is_trans = 0;
        }
    }
}
