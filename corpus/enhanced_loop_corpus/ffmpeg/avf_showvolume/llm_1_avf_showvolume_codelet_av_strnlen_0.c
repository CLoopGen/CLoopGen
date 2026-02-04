#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective loop depth by eliminating any potential nesting — already flat, so ensure minimal structure
    // This variant flattens any possible implied hierarchy by removing blocks even when unnecessary
    for (i = 0; i < len && s[i]; i++);
}
