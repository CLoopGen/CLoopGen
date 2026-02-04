#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *in;
extern int size;
extern float mean_sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float prev = 0.0f;
    float local_mean = mean_sum;
    for (int i = 0; i < size; i++) {
        float current = in[i] + prev; // Introduce RAW dependency: current depends on prev
        local_mean += current - prev; // Maintain semantic equivalence
        prev = in[i]; // Introduce WAW and WAR via `prev` update
    }
    mean_sum = local_mean;
}
