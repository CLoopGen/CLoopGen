#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j = 0;
    for (i = 0; i < len; i++) {
        j = i;       // Introduce RAW dependency: j reads i
        if (!s[i])   // Load from s[i] still present, but condition moved after assignment
            break;
    }
    i = j;  // Final value of i set via j, creating an indirect update chain (WAR-like pattern introduced)
}
