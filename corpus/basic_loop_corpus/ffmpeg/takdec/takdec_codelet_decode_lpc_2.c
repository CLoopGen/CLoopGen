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
for (i = 0; i < length - 3; i++) {
    a3 += *coeffs;
    a4 += a3;
    a5 += a4;
    *coeffs = a5;
    coeffs++;
}

}
