#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer *iwork;
extern integer i__1;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 3; j <= i__1; j += 2) {
        if (j >= 2) {
            iwork[j] += iwork[j - 1];
        }
        if (j + 1 <= i__1) {
            iwork[j + 1] += iwork[j];
        }
    }
}
