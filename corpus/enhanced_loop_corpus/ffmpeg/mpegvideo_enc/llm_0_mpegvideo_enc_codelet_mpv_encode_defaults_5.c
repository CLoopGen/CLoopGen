#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t default_fcode_tab[8193];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int j = 0; j < 2; j++) {
    for (i = -16; i < 16; i++) {
        default_fcode_tab[i + 4096] = 1;
    }
}
}
