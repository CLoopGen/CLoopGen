#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int i;
extern uint64_t t;
extern uint64_t *l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; l[i] != t && i < 1000; i += 2) {
        uint64_t temp = l[i] + l[i + 1];
        temp *= temp;
        l[i] = temp ^ l[i];
    }
}
