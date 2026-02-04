#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint64_t histdb[92];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= 91; i++) {
        if (histdb[i]) break;
    }
}
