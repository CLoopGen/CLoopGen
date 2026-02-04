#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *n;
extern real *c__;
extern real *s;
extern real *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern real temp;
extern real ctemp;
extern real stemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
real temp_prev, temp_curr;
for (j = 1; j <= i__1; ++j) {
    ctemp = c__[j];
    stemp = s[j];
    if (ctemp != 1.F || stemp != 0.F) {
        i__2 = *n;
        temp_prev = a[j + a_dim1]; // Initialize with first row
        for (i__ = 1; i__ <= i__2; ++i__) {
            temp_curr = a[j + 1 + i__ * a_dim1];
            a[j + 1 + i__ * a_dim1] = ctemp * temp_curr - stemp * temp_prev;
            a[j + i__ * a_dim1] = stemp * temp_curr + ctemp * temp_prev;
            temp_prev = a[j + i__ * a_dim1]; // Create WAW and WAR dependency via scalar
        }
        a[j + i__2 * a_dim1] = temp_prev; // Additional write to last element to close dependency chain
    }
}
}
