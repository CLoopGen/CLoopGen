#include <stdio.h>

#include <inttypes.h>

extern int max_points;
extern int codes[];
extern int num_threats;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_sum = 0;
    for (num_threats = 0; num_threats < max_points; num_threats++) {
        temp_sum += codes[num_threats];  // Introduce WAW and RAW dependencies via accumulation
        if (codes[num_threats] == 0)
            break;
    }
    // temp_sum is not used, but creates artificial data dependency within the loop
}
