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
    // Variant 2: Indirect memory access using an index array
    int indices[32];
    for (int j = 0; j < 32; j++) {
        indices[j] = j;
    }
    // Access workT in reverse order through the index array
    for (i = 31; i >= 0; i--) {
        int idx = indices[i]; // Indirect access
        if (workT[idx] > highest) {
            highest = workT[idx];
            found_indx = idx;
        }
    }
}
