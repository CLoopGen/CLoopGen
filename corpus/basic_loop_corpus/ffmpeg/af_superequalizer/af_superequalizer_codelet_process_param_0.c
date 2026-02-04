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
    param[i].lower = i == 0 ? 0 : bands[i - 1];
    param[i].upper = i == 17 ? fs : bands[i];
    param[i].gain = bc[i];
}

}
