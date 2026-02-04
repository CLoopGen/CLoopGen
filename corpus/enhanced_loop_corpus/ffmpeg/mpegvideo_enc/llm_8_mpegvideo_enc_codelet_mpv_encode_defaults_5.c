#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t default_fcode_tab[8193];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = -32; i < 32; i += 2) {
        default_fcode_tab[i + 4096] = 1;
        default_fcode_tab[i + 4097] = 1;
    }
}
