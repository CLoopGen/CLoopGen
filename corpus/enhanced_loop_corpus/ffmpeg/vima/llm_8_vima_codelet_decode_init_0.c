#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const int16_t ff_adpcm_step_table[89];
extern uint16_t predict_table[11572];
extern int start_pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (start_pos = 0; start_pos < 32; start_pos++) {
    unsigned int dest_pos, table_pos;
    for (table_pos = 0, dest_pos = start_pos; table_pos < (sizeof(ff_adpcm_step_table) / sizeof((ff_adpcm_step_table)[0])); table_pos++, dest_pos += 32) {
        int put = 0, count, table_value;
        table_value = ff_adpcm_step_table[table_pos];
        for (count = 16; count != 0; count >>= 1) {
            if (start_pos & count)
                put += table_value;
            table_value >>= 2;
        }
        predict_table[dest_pos] = put;
    }
}
}
