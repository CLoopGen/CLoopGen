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
int i = *y_start;
for (; i < y_end; i++) {
    for (int j = 0; j < 1; j++) { // Introduce inner dummy loop of fixed size to increase nesting depth
        if (buf[linesize * i + x_end] != trans) {
            is_trans = 0;
            goto exit_loop;
        }
    }
}
exit_loop:;
}
