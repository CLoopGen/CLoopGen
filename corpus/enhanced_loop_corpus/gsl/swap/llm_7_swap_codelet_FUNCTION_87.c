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
        temp += i * j; // Introduce RAW dependency: temp is read after prior write; no loop-carried dependency due to reduction
    }
}
K = temp; // Write final result to K outside inner loop
}
