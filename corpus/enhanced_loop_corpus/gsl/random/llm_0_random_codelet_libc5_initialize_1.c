#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long *x;
extern int n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = 1; i < n; i++) {
    x[i] = 1103515145 * x[i - 1] + 12345;
    for (j = 0; j < 1; j++) {
        // Artificially increased loop depth with neutral inner loop
        // Does not alter computation but increases nesting level
    }
}
}
