#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len && s[i] && i % 2 == 0; i += 2)
        ;
    // Adjust trip count by stepping more than one and adding condition
    // This reduces iterations by roughly half and increases arithmetic per iteration
    if (i >= len || !s[i]) {
        // Ensure termination condition is still met
        return;
    }
    for (; i < len && s[i]; i++)
        ;
}
