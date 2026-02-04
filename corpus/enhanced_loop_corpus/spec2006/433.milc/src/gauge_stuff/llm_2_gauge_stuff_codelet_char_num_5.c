#include <stdio.h>

#include <inttypes.h>

extern int length;
extern int j;
extern int bdig[6];
extern int old;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every second element in reverse, then handle remainder)
    old = 0;
    int step = 2;
    // First pass: strided access with step size 2
    for (j = length - 2; j >= 0; j -= step)
        old = old * 10 + bdig[j];
    // Second pass: handle elements at odd offsets if stride skipped them
    for (j = length - 3; j >= 0; j -= step)
        old = old * 10 + bdig[j];
}
