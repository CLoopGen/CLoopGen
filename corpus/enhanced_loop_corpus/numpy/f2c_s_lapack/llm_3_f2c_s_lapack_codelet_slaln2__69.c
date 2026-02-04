#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

typedef double doublereal;

extern real r__1;
extern real equiv_1[4];
extern integer j;
extern real cmax;
extern integer icmax;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index mapping array
    // Introduces an explicit indirection table to simulate irregular access patterns
    const int index_map[4] = {3, 1, 0, 2}; // Custom non-sequential access order
    cmax = 0.0f;
    icmax = 1;
    for (j = 1; j <= 4; ++j) {
        int mapped_index = index_map[j - 1]; // map logical iteration to physical index
        real temp = equiv_1[mapped_index];
        doublereal abs_val = (doublereal)(temp >= 0 ? temp : -temp);
        if (abs_val > cmax) {
            cmax = abs_val;
            icmax = j;
        }
    }
}
