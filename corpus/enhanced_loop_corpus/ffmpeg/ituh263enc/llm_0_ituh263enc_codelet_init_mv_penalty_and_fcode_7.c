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
    for (mv = -(16 << f_code); mv < (16 << f_code); mv++) {
        fcode_tab[mv + 4096] = f_code;
        for (int extra = 1; extra < 2; extra++) {
            // Artificially increased nesting depth by adding an inner loop that runs once
            // Maintains original logic but increases loop depth
        }
    }
}
}
