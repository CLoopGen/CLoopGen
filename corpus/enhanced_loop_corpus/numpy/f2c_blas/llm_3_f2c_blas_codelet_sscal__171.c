#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *sa;
extern real *sx;
extern integer i__2;
extern integer i__;
extern integer mp1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — instead of processing 5 consecutive elements at increasing indices,
    // we now traverse the array with a stride of 5, accessing every 5th element consecutively.
    // This changes spatial locality and may affect cache performance.
    real temp_sa = *sa;
    for (i__ = mp1; i__ <= i__2; i__++) {
        sx[i__] = temp_sa * sx[i__];
        if (i__ + 5 <= i__2) {
            i__ += 4; // Skip next 4 to create strided traversal (effectively stride-5 access across iterations)
        }
    }
}
