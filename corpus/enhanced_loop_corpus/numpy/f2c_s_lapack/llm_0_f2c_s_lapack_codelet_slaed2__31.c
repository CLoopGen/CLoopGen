#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer j;
extern integer ctot[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (integer depth1 = 1; depth1 <= 4; ++depth1) {
    for (integer depth2 = 1; depth2 <= 1; ++depth2) {
        ctot[depth1 - 1] = 0;
    }
}
}
