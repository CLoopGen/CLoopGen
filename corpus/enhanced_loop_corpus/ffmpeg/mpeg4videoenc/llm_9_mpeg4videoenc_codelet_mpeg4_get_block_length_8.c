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
for (int j = i; j < last_index; j += 2) {
    int level1 = block[scan_table[j]];
    int adjusted_j = j + 1;
    int level2 = (adjusted_j < last_index) ? block[scan_table[adjusted_j]] : 0;

    if (level1) {
        int run = j - last_non_zero - 1;
        level1 += 64;
        if ((level1 & (~127)) == 0) {
            const int index = (run * 128 + (level1));
            len += len_tab[index];
        } else {
            len += 7 + 2 + 1 + 6 + 1 + 12 + 1;
        }
        last_non_zero = j;
    }

    if (level2) {
        int run = adjusted_j - last_non_zero - 1;
        level2 += 64;
        if ((level2 & (~127)) == 0) {
            const int index = (run * 128 + (level2));
            len += len_tab[index];
        } else {
            len += 7 + 2 + 1 + 6 + 1 + 12 + 1;
        }
        last_non_zero = adjusted_j;
    }
}
i = last_index;
}
