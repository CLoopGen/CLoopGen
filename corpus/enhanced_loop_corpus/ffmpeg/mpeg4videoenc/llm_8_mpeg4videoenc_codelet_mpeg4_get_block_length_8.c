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
for (; i < last_index && i < last_non_zero + 16; i++) {
    int level = block[scan_table[i]];
    if (level) {
        int run = i - last_non_zero - 1;
        level += 64;
        if ((level & (~127)) == 0) {
            const int index = (run * 128 + (level));
            len += len_tab[index];
        } else {
            len += 7 + 2 + 1 + 6 + 1 + 12 + 1;
        }
        last_non_zero = i;
    }
}
}
