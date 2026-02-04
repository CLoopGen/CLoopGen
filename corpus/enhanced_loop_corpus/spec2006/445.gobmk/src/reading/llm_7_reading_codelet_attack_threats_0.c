#include <stdio.h>

#include <inttypes.h>

extern int max_points;
extern int codes[];
extern int num_threats;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_code;
    for (num_threats = 0; num_threats < max_points; num_threats++) {
        local_code = codes[num_threats];  // Eliminate direct loop-carried dependency by using local copy
        if (local_code == 0) {
            codes[num_threats] = -1;  // Write after read (WAR) introduced with local effect
            break;
        }
    }
}
