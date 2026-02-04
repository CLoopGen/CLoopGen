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
    int limit = w > 64 ? 64 : w;
    for (int i = 0; i < limit; i++) {
        size_t index = linesize * y_end + i;
        if ((buf[index] ^ trans) & 1) {
            is_trans = 0;
            break;
        }
    }
}
