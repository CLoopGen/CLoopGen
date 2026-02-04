#include <stdio.h>

#include <inttypes.h>

extern int i;
extern unsigned char p_str[33];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j = i;
    for (; j < 33; j += 2) {
        p_str[j] = 0;
        if (j + 1 < 33)
            p_str[j + 1] = 0; // Remove loop-carried dependency by unrolling; independent updates
    }
    i = 33; // Update loop control variable after loop
}
