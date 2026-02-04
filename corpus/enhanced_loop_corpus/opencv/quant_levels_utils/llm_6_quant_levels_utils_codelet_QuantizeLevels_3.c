#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int q_level[256];
extern int min_s;
extern int max_s;
extern int s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (s = min_s; s <= max_s; ++s) {
        const int slot = q_level[s];
        temp += slot; // Introduce loop-carried dependency (WAW on temp)
    }
    q_level[0] = temp; // Break potential independence by writing to shared array
}
