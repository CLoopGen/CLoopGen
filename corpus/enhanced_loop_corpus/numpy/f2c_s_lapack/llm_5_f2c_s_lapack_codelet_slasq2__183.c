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
    for (i4 = i0 << 2; i4 <= i__1; i4 += 4) {
        integer index1 = i4 - 3;
        integer index2 = ipn4 - i4 - 3;
        integer index3 = i4 - 1;
        integer index4 = ipn4 - i4 - 5;

        if (index1 >= 0 && index2 >= 0 && index3 >= 0 && index4 >= 0) {
            temp = z__[index1];
            z__[index1] = z__[index2];
            z__[index2] = temp;

            temp = z__[index3];
            z__[index3] = z__[index4];
            z__[index4] = temp;
        }
    }
}
