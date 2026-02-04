#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double a_work[8];
extern double alpha[7][7];
extern int k;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (k = 0; k < 7 - 1; k++) {
    if (a_work[k + 2] > a_work[k + 1] * alpha[k][k + 1])
        break;
}

}
