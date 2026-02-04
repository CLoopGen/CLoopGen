#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *z__;
extern integer i__1;
extern integer i0;
extern integer i4;
extern integer ipn4;
extern real temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 1; ++j) { // Outer loop added, reducing effective iteration logic to single pass
        for (i4 = i0 << 2; i4 <= i__1; i4 += 4) {
            temp = z__[i4 - 3];
            z__[i4 - 3] = z__[ipn4 - i4 - 3];
            z__[ipn4 - i4 - 3] = temp;
            temp = z__[i4 - 1];
            z__[i4 - 1] = z__[ipn4 - i4 - 5];
            z__[ipn4 - i4 - 5] = temp;
        }
    }
}
