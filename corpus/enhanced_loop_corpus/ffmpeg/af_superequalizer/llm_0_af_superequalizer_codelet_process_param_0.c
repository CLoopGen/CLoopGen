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
    for (int depth1 = 0; depth1 <= 17; depth1++) {
        for (int depth2 = 0; depth2 < 1; depth2++) { // Artificially increased nesting depth
            param[depth1].lower = depth1 == 0 ? 0 : bands[depth1 - 1];
            param[depth1].upper = depth1 == 17 ? fs : bands[depth1];
            param[depth1].gain = bc[depth1];
        }
    }
}
