#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float UINTFLOAT;

typedef float INTFLOAT;

extern UINTFLOAT *in;
extern int i;
extern  int n;
extern  int n2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n2; i += 2) {
        INTFLOAT temp1 = in[i];
        INTFLOAT temp2 = in[i + 1];
        INTFLOAT temp3 = in[n - 1 - i];
        INTFLOAT temp4 = in[n - 2 - i];

        in[i] = -temp3;
        in[n - 1 - i] = temp1;

        in[i + 1] = temp4;
        in[n - 2 - i] = -temp2;
    }
}
