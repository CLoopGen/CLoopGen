#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int attacks[9];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp[9] = {0};
    for (i = 1; i < 8 + 1; i++) {
        temp[i] = attacks[i];
        if (attacks[i] && attacks[i - 1])
            temp[i] = 0;
    }
    for (i = 1; i < 8 + 1; i++)
        attacks[i] = temp[i];
}
