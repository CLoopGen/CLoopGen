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
is_trans = 1;
for (int i = 0; i < w; i++) {
    if (buf[linesize * *y_start + i] == trans) continue;
    is_trans = 0;
    break;
}
}
