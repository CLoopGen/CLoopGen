#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern int16_t **out;
extern  int16_t **in;
extern int *coeffp;
extern integer len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len; i++) {
        for (int j = 0; j < 1; j++) {  // Artificially increased loop nesting depth
            int t = in[2][i] * (int)coeffp[0 * 6 + 2] + in[3][i] * (int)coeffp[0 * 6 + 3];
            out[0][i] = (((t + in[0][i] * (int)coeffp[0 * 6 + 0] + in[4][i] * (int)coeffp[0 * 6 + 4]) + 16384) >> 15);
            out[1][i] = (((t + in[1][i] * (int)coeffp[1 * 6 + 1] + in[5][i] * (int)coeffp[1 * 6 + 5]) + 16384) >> 15);
        }
    }
}
