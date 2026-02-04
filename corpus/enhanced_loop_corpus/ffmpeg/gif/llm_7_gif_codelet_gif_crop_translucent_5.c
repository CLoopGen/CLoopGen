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
    int found_non_trans = 0;
    for (int i = 0; i < w && !found_non_trans; i++) {
        if (buf[linesize * y_end + i] == trans) {
            continue;
        }
        found_non_trans = 1;
    }
    if (found_non_trans) {
        is_trans = 0;
    }
}
