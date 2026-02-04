#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *cdf;
extern unsigned int k;
extern unsigned int symbol;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int temp_k = 0;
    while (1) {
        if (!(cdf[temp_k] <= symbol)) break;
        temp_k++;
    }
    k = temp_k;
}
