#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t K;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
size_t temp = 0;
for (i = 0; i < K; i++) {
    for (j = 0; j < i; j++) {
        temp += i * j; // Introduces RAW dependency: temp used and updated; loop-carried dependency through accumulation
    }
}
K = temp; // Eliminates direct mutation inside loops but preserves side effect
}
