#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned int UINTFLOAT;

typedef int INTFLOAT;

extern UINTFLOAT *in;
extern int i;
extern  int n;
extern  int n2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < (n2 + 1) / 2; outer++) {
        i = 2 * outer;
        if (i >= n2) continue;
        INTFLOAT temp;
        temp = in[i];
        in[i] = -in[n - 1 - i];
        in[n - 1 - i] = temp;
        if (i + 1 < n2) {
            temp = -in[i + 1];
            in[i + 1] = in[n - 2 - i];
            in[n - 2 - i] = temp;
        }
    }
}
