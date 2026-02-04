#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *ihi;
extern real *tau;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    integer temp = 0;
    for (i__ = ((1) >= (*ihi) ? (1) : (*ihi)); i__ <= i__1; ++i__) {
        temp = i__;              // Introduce temporary variable to create WAW and WAR dependencies
        tau[temp] = 0.F;         // Use temp to break direct dependency on loop index in memory store
    }
}
