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
    // Variant 2: Consecutive Reverse Traversal with Linear Index Mapping
    // Process elements from the middle outward using consecutive access pattern
    int mid = n2 / 2;
    for (i = 0; i < mid; i += 2) {
        INTFLOAT temp;

        // Map forward index to symmetric backward index using linear offset
        int forward_low = i;
        int forward_high = i + 1;
        int backward_high = n - 1 - i;
        int backward_low = n - 2 - i;

        // Swap front and back elements consecutively
        temp = in[forward_low];
        in[forward_low] = -in[backward_high];
        in[backward_high] = temp;

        if (forward_high < backward_low) {
            temp = in[forward_high];
            in[forward_high] = in[backward_low];
            in[backward_low] = -temp;
        }
    }
}
