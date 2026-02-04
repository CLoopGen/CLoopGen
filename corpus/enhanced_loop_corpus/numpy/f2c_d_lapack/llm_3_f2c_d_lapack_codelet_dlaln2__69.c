#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal d__1;
extern doublereal equiv_1[4];
extern integer j;
extern doublereal cmax;
extern integer icmax;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect access via predefined index mapping (reversed order)
    int indices[4] = {3, 2, 1, 0}; // Access in reverse order: 4th, 3rd, 2nd, 1st element
    cmax = 0.0;
    icmax = 1;
    for (j = 1; j <= 4; ++j) {
        int mapped_index = indices[j - 1]; // Map loop iteration to actual array index
        doublereal temp = equiv_1[mapped_index];
        doublereal abs_val = temp >= 0 ? temp : -temp;
        if (abs_val > cmax) {
            cmax = abs_val;
            icmax = mapped_index + 1; // Maintain 1-based indexing
        }
    }
}
