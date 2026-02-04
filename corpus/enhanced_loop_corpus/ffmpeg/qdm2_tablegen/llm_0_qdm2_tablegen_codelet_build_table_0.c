#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int table_size;
extern int i;
extern volatile int16_t (*volatile table)[2];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = 0; i < table_size; i++) {
    for (j = 0; j < 1; j++) {
        if (table[i][1] == 0)
            table[i][0] = -1;
    }
}
}
