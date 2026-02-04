#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int grouping;
extern int attacks[9];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 9 && grouping == 0; i++) {
        grouping = i * !!attacks[i];
    }
}
