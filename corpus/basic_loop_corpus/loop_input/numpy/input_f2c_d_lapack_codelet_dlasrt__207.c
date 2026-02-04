#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <stdint.h>

typedef double doublereal;
typedef int integer;

doublereal *d__ = NULL;
integer i__1;
integer i__2;
integer i__;
integer j;
doublereal dmnmx;
integer start;

void init_vars() {
    const int data_size = 1 << 20; // Approximately 8MB of data (1M doubles)
    
    d__ = (doublereal*)calloc(data_size, sizeof(doublereal));
    if (!d__) {
        exit(1);
    }
    
    // Initialize with descending order to ensure comparisons happen
    for (int idx = 0; idx < data_size; ++idx) {
        d__[idx] = (doublereal)(data_size - idx);
    }
    
    // Set loop bounds to valid range within allocated memory
    start = 1;
    i__1 = data_size - 1;
}