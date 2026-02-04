#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int grouping;
extern int attacks[9];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    grouping = -1;
    for (i = 0; i < 9; i++) {
        int local_attack = attacks[i];
        if (local_attack && grouping == -1) {
            grouping = i;
        }
    }
}
