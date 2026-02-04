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
    for (i = 0; i < n; i++) {
        sum += markers[i];
        // Introduce a temporary variable to break direct WAW on 'max'
        int temp_max = max;
        if (markers[temp_max] < markers[i]) {
            max = i;
        }
    }
}
