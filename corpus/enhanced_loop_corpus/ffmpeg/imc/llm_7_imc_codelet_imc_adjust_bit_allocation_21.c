#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float workT[32];
extern int i;
extern float highest;
extern int found_indx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float local_highest = -__builtin_inff();
    int local_index = -1;
    for (i = 0; i < 32; i += 4) {
        float w0 = workT[i + 0];
        float w1 = workT[i + 1];
        float w2 = workT[i + 2];
        float w3 = workT[i + 3];

        if (w0 > local_highest) { local_highest = w0; local_index = i + 0; }
        if (w1 > local_highest) { local_highest = w1; local_index = i + 1; }
        if (w2 > local_highest) { local_highest = w2; local_index = i + 2; }
        if (w3 > local_highest) { local_highest = w3; local_index = i + 3; }
    }
    if (local_index != -1) {
        highest = local_highest;
        found_indx = local_index;
    }
}
