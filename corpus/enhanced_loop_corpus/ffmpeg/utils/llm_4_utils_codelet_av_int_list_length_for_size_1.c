#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int i;
extern uint16_t t;
extern uint16_t *l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    i = 0;
    if (l[i] == t) return;
    for (;; i++)
        if (l[i + 1] == t) break;
}
