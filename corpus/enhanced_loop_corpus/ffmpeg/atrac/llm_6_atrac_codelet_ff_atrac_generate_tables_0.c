#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float qmf_window[48];
extern  float qmf_48tap_half[24];
extern int i;
extern float s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp[24];
    for (i = 0; i < 24; i++) {
        temp[i] = qmf_48tap_half[i] * 2.;
    }
    for (i = 0; i < 24; i++) {
        s = temp[i];
        qmf_window[i] = s;
        qmf_window[47 - i] = s;
    }
}
