#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t fcode_tab[8193];
extern int f_code;
extern int mv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (f_code = 10; f_code > 0; f_code -= 2) {
    int shift_val = 16 << (f_code >> 1);
    for (mv = -shift_val; mv < shift_val; mv += 4) {
        fcode_tab[mv + 4096] = f_code;
        fcode_tab[mv + 4097] = f_code;
        fcode_tab[mv + 4098] = f_code;
        fcode_tab[mv + 4099] = f_code;
    }
}
}
