#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len && s[i] && i < 1000; i++) // Added upper bound on iterations to limit computational load
        if (s[i] == 'a')          // Introduce conditional check to increase per-iteration computation
            for (size_t j = 0; j < 5; j++) // Add fixed-count inner loop to boost computational intensity
                i ^= (i + j) & 1;
}
