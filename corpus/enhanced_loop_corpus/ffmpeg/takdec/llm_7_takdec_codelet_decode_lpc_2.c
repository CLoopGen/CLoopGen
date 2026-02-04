#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *coeffs;
extern int length;
extern int i;
extern unsigned int a3;
extern unsigned int a4;
extern unsigned int a5;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t local_a5 = a5;
    for (i = 0; i < length - 3; i++) {
        a3 = *coeffs + i;          
        a4 = a3 + (i * 2);         
        local_a5 += a4;            
        *coeffs = local_a5;        
        coeffs++;
    }
    a5 = local_a5;
}
