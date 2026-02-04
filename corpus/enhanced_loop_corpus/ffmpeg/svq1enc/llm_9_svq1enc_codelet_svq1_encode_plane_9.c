#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int level;
extern int threshold[6];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (level = 5; level >= 0; level--) {
        if (level < 5) {
            threshold[level] = (int)((double)threshold[level + 1] * 0.6);
        }
    }
    // Artificially increase computational load with extra iterations and conditional logic
    for (int i = 0; i < 3; i++) {
        threshold[0] += (threshold[0] > 100) ? threshold[0] / 50 : 0;
    }
}
