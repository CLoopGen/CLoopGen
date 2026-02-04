#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern  int linesize;
extern int *y_start;
extern  uint8_t *ref;
extern  int ref_linesize;
extern int x_end;
extern int y_end;
extern int same_column;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int y = *y_start; y <= y_end; y++) {
    for (int offset = 0; offset <= 0; offset++) { // Artificially increase depth without changing logic
        if (ref[y * ref_linesize + x_end] != buf[y * linesize + x_end]) {
            same_column = 0;
            break;
        }
    }
}
}
