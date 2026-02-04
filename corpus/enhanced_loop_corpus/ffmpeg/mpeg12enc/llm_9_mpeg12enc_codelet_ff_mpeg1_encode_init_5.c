#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t fcode_tab[8193];
extern int f_code;
extern int mv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (f_code = 5; f_code > 0; f_code--) {
        int shift = 8 << f_code;
        int bound = shift * 2;
        for (mv = -shift; mv <= shift; mv++) {
            fcode_tab[mv + 4096] = f_code;
            fcode_tab[mv + 4096 + bound] = f_code;
            fcode_tab[mv + 4096 - bound] = f_code;
        }
    }
}
