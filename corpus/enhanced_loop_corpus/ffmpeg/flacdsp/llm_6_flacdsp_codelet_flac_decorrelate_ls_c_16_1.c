#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t **in;
extern int len;
extern int shift;
extern int16_t *samples;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int prev_a = 0;
    for (i = 0; i < len; i++) {
        unsigned int a = in[0][i] + prev_a; // Introduce WAW and RAW dependency: current a depends on previous a
        unsigned int b = in[1][i];
        (*samples++) = a << shift;
        (*samples++) = (a - b) << shift;
        prev_a = a; // Loop-carried dependency (WAW) introduced
    }
}
