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
    for (int i = *y_start; is_trans && i < y_end; i++) {
        is_trans = (buf[linesize * i + x_end] == trans);
    }
}
