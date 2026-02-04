#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int table_size;
extern int i;
extern volatile int16_t (*volatile table)[2];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t prev_value = -1;
    for (i = 0; i < table_size; i++) {
        if (i > 0 && table[i][1] == table[i-1][0]) {
            table[i][0] = prev_value;
        }
        if (table[i][1] == 0) {
            table[i][0] = -1;
            prev_value = -1;
        }
    }
}
