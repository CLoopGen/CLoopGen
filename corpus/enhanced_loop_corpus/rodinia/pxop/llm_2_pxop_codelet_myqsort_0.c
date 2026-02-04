#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *a;
extern int i;
extern int j;
extern int tmp;
extern int v;
extern int numswaps;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access with fixed increment/decrement steps (stride = 2)
    // This changes the access pattern to skip every other element, modifying the partitioning behavior.
    int stride = 2;
    for (;;) {
        i += stride;
        j -= stride;
        if (a[i] >= v && a[j] <= v) {
            if (i >= j) break;
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            numswaps++;
        } else {
            if (a[i] < v) {
                i -= stride - 1; // Adjust back toward dense scanning
            }
            if (a[j] > v) {
                j += stride - 1;
            }
        }
    }
}
