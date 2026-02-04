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
for (i = 0; i < n2; i += 2) {
    INTFLOAT temp;
    int idx1 = n - 1 - i;
    int idx2 = n - 2 - i;
    if (idx1 >= 0 && i != idx1) {
        temp = in[i];
        in[i] = -in[idx1];
        in[idx1] = temp;
    }
    if (idx2 >= 0 && (i + 1) != idx2) {
        temp = -in[i + 1];
        in[i + 1] = in[idx2];
        in[idx2] = temp;
    }
}
}
