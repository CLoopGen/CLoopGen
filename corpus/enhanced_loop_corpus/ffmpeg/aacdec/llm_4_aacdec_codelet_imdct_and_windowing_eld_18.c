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
    if (i >= n - 1 - i) continue;
    INTFLOAT temp;
    temp = in[i];
    in[i] = -in[n - 1 - i];
    in[n - 1 - i] = temp;
    if (i + 1 >= n - 2 - i) continue;
    temp = -in[i + 1];
    in[i + 1] = in[n - 2 - i];
    in[n - 2 - i] = temp;
}
}
