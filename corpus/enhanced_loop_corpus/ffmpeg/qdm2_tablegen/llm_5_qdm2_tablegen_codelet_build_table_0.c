#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int table_size;
extern int i;
extern volatile int16_t (*volatile table)[2];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < table_size; i++) {
        if (table[i][1] != 0)
            continue;
        table[i][0] = -1;
    }
}
