#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int level;
extern int threshold[6];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (level = 4; level >= 0; level--) {
        if (threshold[level + 1] > 0) {
            threshold[level] = threshold[level + 1] * 0.59999999999999998;
        } else {
            threshold[level] = 0;
        }
    }
}
