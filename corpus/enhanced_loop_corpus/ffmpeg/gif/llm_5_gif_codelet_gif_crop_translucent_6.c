#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern  int linesize;
extern int *x_start;
extern int *y_start;
extern int trans;
extern int y_end;
extern int is_trans;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    is_trans = 1;
    for (int i = *y_start; i < y_end; i++) {
        if (buf[linesize * i + *x_start] == trans) continue;
        is_trans = 0;
        break;
    }
}
