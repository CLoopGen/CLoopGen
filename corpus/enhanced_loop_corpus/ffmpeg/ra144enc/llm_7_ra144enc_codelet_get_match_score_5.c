#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *work;
extern  float *data;
extern float c;
extern float g;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float prev_work = 0.0f;
    for (i = 0; i < 40; i++) {
        float current_work = work[i] + prev_work; // Introduce WAW and RAW dependency: current depends on previous iteration
        g += current_work * current_work;
        c += data[i] * current_work;
        prev_work = current_work; // Loop-carried dependency (WAW via prev_work)
    }
}
