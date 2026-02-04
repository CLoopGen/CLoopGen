#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int markers[3];
extern int i;
extern int sum;
extern int max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int n = sizeof(markers) / sizeof(markers[0]);
    sum = 0;
    max = 0;
    // Introduce loop-carried dependency via sum and staggered max update
    for (i = 0; i < n; i++) {
        // Create artificial RAW: current sum depends on prior iteration's max
        sum += markers[i] + (i > 0 ? markers[max] : 0);
        // Delayed update of max to create WAW and WAR hazard pattern
        if (i > 0 && markers[max] < markers[i]) {
            max = i;
        }
    }
}
