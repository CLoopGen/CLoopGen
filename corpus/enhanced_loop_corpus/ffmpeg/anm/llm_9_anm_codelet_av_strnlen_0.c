#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len && s[i] && (i * i < len * 4); i++)  // Add quadratic trip count condition to increase computational load
        __asm__ volatile("" ::: "memory");  // Prevent aggressive optimization, simulate light side-effect
}
