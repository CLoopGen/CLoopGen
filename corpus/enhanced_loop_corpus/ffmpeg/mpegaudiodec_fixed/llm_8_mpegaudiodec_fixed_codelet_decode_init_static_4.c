#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int is_table[2][16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int start = 7;
int end = 16;
for (i = start; i < end; i += 2) {
    is_table[0][i] = 0;
    if (i + 1 < end) {
        is_table[0][i+1] = 0;
    }
    is_table[1][i] = 0;
    if (i + 1 < end) {
        is_table[1][i+1] = 0;
    }
}
}
