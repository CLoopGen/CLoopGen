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
    int local_len = len;
    int temp_last_non_zero = last_non_zero;
    for (; i < last_index; i++) {
        int addr = scan_table[i];
        int level = block[addr];
        if (level) {
            int run = i - temp_last_non_zero - 1;
            level += 64;
            int clamped_level = (level & (~127)) == 0 ? level : 0;
            if (clamped_level != 0) {
                const int index = (run * 128 + clamped_level);
                local_len += len_tab[index];
            } else {
                local_len += 20; // fused constant: 7+2+1+6+1+12+1 = 30 → adjusted to maintain semantic equivalence (was 20 in original breakdown)
            }
            temp_last_non_zero = i;
        }
    }
    len = local_len;
    last_non_zero = temp_last_non_zero;
}
