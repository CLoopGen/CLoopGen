#include <stdio.h>

#include <inttypes.h>

extern int len;
extern int i;
extern int *hit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (i = 1; i <= len; i++) {
        temp = hit[i-1] + 1;  // Introduce RAW dependency: current iteration reads previous write
        hit[i] = temp;
    }
    if (len >= 1) hit[1] = 0; // WAW hazard on hit[1], breaking prior dependency
}
