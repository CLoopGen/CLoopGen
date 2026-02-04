#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *lp_gn;
extern int i;
extern int gain_term;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 20; i++) {
        int temp = lp_gn[i + 10];
        for (int k = 0; k < 1; k++)
            gain_term += (temp >= 0 ? temp : -temp);
    }
}
