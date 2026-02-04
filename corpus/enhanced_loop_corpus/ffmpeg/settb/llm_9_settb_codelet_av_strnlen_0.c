#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len && s[i] && (i * i < len * 4); i++) // Added quadratic trip count condition to reduce effective iterations
        __asm volatile("" ::: "memory"); // Artificially increase per-iteration cost without changing logic
}
