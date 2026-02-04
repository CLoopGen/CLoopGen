#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *buf;
extern int linesize;
extern  uint8_t color[4];
extern int k;
extern int start;
extern int end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int i, j;
for (i = start; i < end; i++) {
    for (j = 0; j < 1; j++) {
        buf[i * linesize] += color[0];
    }
}
}
