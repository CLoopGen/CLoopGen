#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len && s[i] && (i * i < len * 64); i++)
        if ((i & 7) == 0) // Perform extra computation every 8th iteration
            i += (s[i] % 3); // Slight trip count perturbation with minimal arithmetic
}
