#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int level;
extern int threshold[6];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (level = 4; level >= 0; level--) {
        threshold[level] = (int)(threshold[level + 1] * 0.6);
        threshold[level] -= (threshold[level] >> 4); // Additional bit shift to simulate fine adjustment
    }
}
