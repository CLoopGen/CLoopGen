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
    // Variant 1: Strided Memory Access with Increased Stride (simulating access to interleaved data)
    // Here, we assume the effective size is still n2 but accessed with a stride of 4 instead of 2.
    // This changes memory access pattern to non-consecutive, strided access.
    for (i = 0; i < n2; i += 4) {
        INTFLOAT temp;
        if (i + 1 < n2) {
            temp = in[i];
            in[i] = -in[n - 1 - i];
            in[n - 1 - i] = temp;
        }
        if (i + 3 < n2) {
            temp = -in[i + 1];
            in[i + 1] = in[n - 2 - i];
            in[n - 2 - i] = temp;
        }
    }
}
