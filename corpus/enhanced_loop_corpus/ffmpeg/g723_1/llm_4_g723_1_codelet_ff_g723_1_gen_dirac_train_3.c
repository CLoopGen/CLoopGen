#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *buf;
extern int pitch_lag;
extern int16_t vector[60];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (pitch_lag <= 0) return;
    for (i = pitch_lag; i < 60; i += pitch_lag) {
        int limit = 60 - i;
        for (j = 0; j < limit; j++) {
            if (vector[j] != 0) {
                buf[i + j] += vector[j];
            }
        }
    }
}
