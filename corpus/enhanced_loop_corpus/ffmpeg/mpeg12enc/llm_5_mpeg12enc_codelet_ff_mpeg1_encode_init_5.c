#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t fcode_tab[8193];
extern int f_code;
extern int mv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (f_code = 7; f_code > 0; f_code--) {
        int range = 8 << f_code;
        int lower = -range;
        int upper = range;
        for (mv = lower; mv < upper; mv++) {
            if (f_code % 2 == 1) {
                fcode_tab[mv + 4096] = f_code;
            }
        }
    }
}
