#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int table_size;
extern int i;
extern volatile int16_t (*volatile table)[2];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (table_size > 0) {
    for (i = 0; i < table_size; i += 2) {
        if (table[i][1] == 0)
            table[i][0] = -1;
        if (i + 1 < table_size && table[i + 1][1] == 0)
            table[i + 1][0] = -1;
    }
}
}
