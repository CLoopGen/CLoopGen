#include <stdio.h>

#include <inttypes.h>

extern int max_points;
extern int codes[];
extern int num_threats;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 0; i < max_points && i < 1000; i++) {
        if (codes[i] == 0) {
            num_threats = i;
            break;
        }
    }
    if (i == max_points || i >= 1000) {
        num_threats = i < max_points ? i : max_points - 1;
    }
}
