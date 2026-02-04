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
        INTFLOAT temp_forward, temp_backward;
        temp_forward = in[i];
        temp_backward = in[n - 1 - i];

        in[i] = -temp_backward;
        in[n - 1 - i] = temp_forward;

        if (i + 1 < n2) {
            temp_forward = in[i + 1];
            temp_backward = in[n - 2 - i];

            in[i + 1] = temp_backward;
            in[n - 2 - i] = -temp_forward;
        }
    }
}
