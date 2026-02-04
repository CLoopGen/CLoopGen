#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t fcode_tab[8193];
extern int f_code;
extern int mv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (f_code = 14; f_code > 0; f_code -= 2)
        for (mv = -(16 << (f_code >> 1)); mv < (16 << (f_code >> 1)); mv++)
            fcode_tab[mv + 4096] = f_code >> 1;
}
