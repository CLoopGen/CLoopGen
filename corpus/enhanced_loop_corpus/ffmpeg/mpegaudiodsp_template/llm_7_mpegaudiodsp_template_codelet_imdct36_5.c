#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int *in;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 17; i >= 3; i -= 2) {
        unsigned int temp = in[i - 2];
        in[i] += temp;
        in[i - 2] += temp; // Introduces WAW and WAR dependency, creates loop-carried dependence via in[i-2]
    }
}
