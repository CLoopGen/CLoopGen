#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int table_size;
extern int i;
extern volatile int16_t (*volatile table)[2];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t temp[2];
    for (i = 0; i < table_size; i++) {
        temp[0] = table[i][0];
        temp[1] = table[i][1];
        if (temp[1] == 0) {
            temp[0] = -1;
        }
        table[i][0] = temp[0];
    }
}
