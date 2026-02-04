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
int i = 0;
for (; i < w; i++) {
    if (buf[linesize * *y_start + i] != trans) {
        is_trans = 0;
        break;
    }
}
}
