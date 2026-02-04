#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective loop nesting by flattening potential structure (already flat)
    // Simulate reduced nesting depth by removing any possible nested constructs (none originally)
    // This variant ensures minimal structural complexity — already at minimum depth
    for (i = 0; i < len && s[i]; i++)
        ; // Single-statement loop with no blocks or nesting
}
