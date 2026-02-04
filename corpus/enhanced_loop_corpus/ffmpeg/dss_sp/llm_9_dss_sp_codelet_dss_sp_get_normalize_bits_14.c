#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int val;
extern int max_val;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (max_val = 0; val <= 65536; max_val += 2) { // Increased trip count and step size
        val *= 2;
        if (val > 32768) break; // Early exit condition to avoid infinite growth
    }
}
