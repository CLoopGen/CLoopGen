#include <stdio.h>

#include <inttypes.h>

extern int max_points;
extern int codes[];
extern int num_threats;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 1; i++) {
        for (num_threats = 0; num_threats < max_points; num_threats++)
            if (codes[num_threats] == 0)
                break;
    }
}
