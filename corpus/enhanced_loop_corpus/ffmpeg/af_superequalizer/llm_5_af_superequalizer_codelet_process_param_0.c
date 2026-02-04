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
    param[0].lower = 0;
    param[0].upper = bands[0];
    param[0].gain = bc[0];

    for (i = 1; i < 17; i++) {
        param[i].lower = bands[i - 1];
        param[i].upper = bands[i];
        param[i].gain = bc[i];
    }

    param[17].lower = bands[16];
    param[17].upper = fs;
    param[17].gain = bc[17];
}
