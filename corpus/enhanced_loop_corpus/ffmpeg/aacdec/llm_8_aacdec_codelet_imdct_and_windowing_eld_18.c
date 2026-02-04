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
    for (i = 0; i < n2; i += 4) {
        INTFLOAT temp1, temp2;
        if (i + 1 < n2) {
            temp1 = in[i];
            in[i] = -in[n - 1 - i];
            in[n - 1 - i] = temp1;
            temp1 = -in[i + 1];
            in[i + 1] = in[n - 2 - i];
            in[n - 2 - i] = temp1;
        }
        if (i + 2 < n2) {
            temp2 = in[i + 2];
            in[i + 2] = -in[n - 3 - i];
            in[n - 3 - i] = temp2;
        }
        if (i + 3 < n2) {
            temp2 = -in[i + 3];
            in[i + 3] = in[n - 4 - i];
            in[n - 4 - i] = temp2;
        }
    }
}
