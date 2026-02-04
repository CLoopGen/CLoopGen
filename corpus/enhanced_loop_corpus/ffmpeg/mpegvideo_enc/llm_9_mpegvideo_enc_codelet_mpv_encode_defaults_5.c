#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t default_fcode_tab[8193];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = -8; i < 8; i++) {
        default_fcode_tab[i + 4096] = 1;
        default_fcode_tab[i + 4104] = 1;
        default_fcode_tab[i + 4088] = 1;
        default_fcode_tab[i + 4112] = 1;
        default_fcode_tab[i + 4080] = 1;
    }
}
