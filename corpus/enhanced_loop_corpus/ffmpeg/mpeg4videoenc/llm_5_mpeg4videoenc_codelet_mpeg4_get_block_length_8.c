#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern uint8_t *scan_table;
extern int i;
extern int last_non_zero;
extern uint8_t *len_tab;
extern  int last_index;
extern int len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; i < last_index; i++) {
    int level = block[scan_table[i]];
    if (level) {
        int run = i - last_non_zero - 1;
        level += 64;
        const int is_small = (level & (~127)) == 0;
        len += is_small ? len_tab[(run * 128 + level)] : (7 + 2 + 1 + 6 + 1 + 12 + 1);
        last_non_zero = i;
    } else {
        if (i >= last_index - 1) break;
    }
}
}
