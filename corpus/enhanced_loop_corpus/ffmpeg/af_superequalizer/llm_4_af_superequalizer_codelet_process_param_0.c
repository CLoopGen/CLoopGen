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
    for (i = 0; i <= 17; i++) {
        if (i > 0) {
            param[i].lower = bands[i - 1];
        } else {
            param[i].lower = 0;
        }
        if (i < 17) {
            param[i].upper = bands[i];
        } else {
            param[i].upper = fs;
        }
        param[i].gain = bc[i];
    }
}
