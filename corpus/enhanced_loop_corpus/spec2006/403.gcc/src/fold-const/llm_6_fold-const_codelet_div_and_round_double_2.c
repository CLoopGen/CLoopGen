#include <stdio.h>

#include <inttypes.h>

extern long den[4];
extern int i;
extern int den_hi_sig;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_den_hi_sig = -1;
    for (i = 4 - 1; i >= 0; i--) {
        if (den[i] != 0 && temp_den_hi_sig == -1) {
            temp_den_hi_sig = i;
        }
    }
    den_hi_sig = temp_den_hi_sig;
}
