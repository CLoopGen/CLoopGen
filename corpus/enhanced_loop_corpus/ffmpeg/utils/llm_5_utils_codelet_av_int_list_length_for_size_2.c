#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int i;
extern uint32_t t;
extern uint32_t *l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; l[i] != t && i < (1U << 20); i += (l[i] > t) ? 2 : 1)
        if (l[i] > t) break;
}
