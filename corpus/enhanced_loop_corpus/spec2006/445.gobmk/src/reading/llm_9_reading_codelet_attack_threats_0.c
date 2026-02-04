#include <stdio.h>

#include <inttypes.h>

extern int max_points;
extern int codes[];
extern int num_threats;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 2;
    num_threats = 0;
    for (; num_threats < max_points; num_threats += step) {
        if (num_threats + 1 < max_points) {
            if (codes[num_threats] == 0 || codes[num_threats + 1] == 0) {
                if (codes[num_threats] == 0)
                    break;
                else {
                    num_threats++;
                    break;
                }
            }
        } else {
            if (codes[num_threats] == 0)
                break;
        }
    }
}
