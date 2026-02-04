#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *scantable;
extern int16_t (*temp);
extern int i;
extern int last;
extern int run;
extern int bits;
extern int level;
extern int start_i;
extern  int esc_length;
extern uint8_t *length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = start_i; i < last; i++) {
    int j = scantable[i];
    level = temp[j];
    if (!level) {
        run++;
        continue;
    }
    level += 64;
    bits += (level <= 127) ? length[run * 128 + level] : esc_length;
    run = 0;
}
}
