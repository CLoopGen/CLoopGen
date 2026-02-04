#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int temp[4][4];
for (j = 0; j < 4; ++j) {
    for (i = 0; i < 4; ++i) {
        temp[j][i] = j + i; // Introduce RAW dependency: use of 'j' and 'i' before assignment to temp[j][i]
    }
}
// Eliminate loop-carried dependencies by making all writes independent across iterations
// Each temp[j][i] is written once with no cross-iteration data flow
}
