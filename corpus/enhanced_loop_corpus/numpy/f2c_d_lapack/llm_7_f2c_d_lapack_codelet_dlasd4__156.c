#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *delta;
extern doublereal *work;
extern integer i__1;
extern integer j;
extern doublereal eta;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    doublereal temp_work, temp_delta;
    for (j = 1; j <= i__1; ++j) {
        temp_work = work[j] + eta;
        temp_delta = delta[j] - eta;
        work[j] = temp_work;   // Eliminates potential WAW or WAR hazards by using temporaries
        delta[j] = temp_delta;
    }
}
