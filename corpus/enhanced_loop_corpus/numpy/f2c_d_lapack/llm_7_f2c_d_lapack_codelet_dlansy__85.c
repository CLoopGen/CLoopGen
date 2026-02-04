#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *n;
extern doublereal *a;
extern doublereal *work;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern doublereal d__1;
extern integer i__;
extern integer j;
extern doublereal sum;
extern doublereal absa;
extern doublereal value;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 1; j <= i__1; ++j) {
        sum = work[j];
        i__2 = *n;
        // Introduce temporary accumulation to remove WAW dependency on 'work' across iterations
        doublereal temp_work_update = (d__1 = a[j + j * a_dim1], ((d__1) >= 0 ? (d__1) : -(d__1)));
        sum += temp_work_update;
        for (i__ = j + 1; i__ <= i__2; ++i__) {
            absa = (d__1 = a[i__ + j * a_dim1], ((d__1) >= 0 ? (d__1) : -(d__1)));
            sum += absa;
            // Modify data dependency: Delay updates to work[] until after inner loop to break WAR dependencies
            temp_work_update += absa;
        }
        // Apply delayed update: Now modify work array only once per j, reducing WAW and WAR hazards
        if (j + 1 <= *n) {
            work[j + 1] += temp_work_update - (d__1 = a[j + j * a_dim1], ((d__1) >= 0 ? (d__1) : -(d__1))); // Exclude diagonal
        }
        value = ((value) >= (sum) ? (value) : (sum));
    }
}
