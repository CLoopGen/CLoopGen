#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *cdf;
extern unsigned int k;
extern unsigned int symbol;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    k = 0;
    uint16_t *cdf_ptr = cdf;
    for (; *cdf_ptr <= symbol; k++, cdf_ptr++)
        ;
}
