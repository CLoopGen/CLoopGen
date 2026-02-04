#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int grouping;
extern int attacks[9];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    grouping = 8;
    for (i = 8; i >= 0; i--) {
        if (attacks[i]) {
            grouping = i;
        }
    }
}
