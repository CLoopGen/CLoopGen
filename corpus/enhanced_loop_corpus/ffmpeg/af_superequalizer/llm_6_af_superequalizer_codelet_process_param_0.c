#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct EqParameter {
    float lower;
    float upper;
    float gain;
} EqParameter;

extern  float bands[];
extern float *bc;
extern EqParameter *param;
extern float fs;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float prev_band = 0;
    for (i = 0; i <= 17; i++) {
        param[i].lower = prev_band;
        param[i].upper = bands[i];
        param[i].gain = bc[i];
        prev_band = bands[i];
    }
    param[17].upper = fs;
}
