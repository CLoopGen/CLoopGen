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
    for (int i = 0; i < w && is_trans; i++) {
        is_trans = (buf[linesize * y_end + i] == trans);
    }
}
