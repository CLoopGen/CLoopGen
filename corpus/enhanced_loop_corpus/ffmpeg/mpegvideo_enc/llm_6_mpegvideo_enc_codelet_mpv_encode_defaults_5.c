#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t default_fcode_tab[8193];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp[32];
    for (i = -16; i < 16; i++) {
        temp[i + 16] = i * 2;
        default_fcode_tab[temp[i + 16] + 4096] = 1;
    }
}
