#include <stdio.h>

#include <inttypes.h>

extern int first;
extern int last;
extern int *histp;
extern int i;
extern int sum;
extern int sum2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = first; i <= last; ++i) {
        if ((sum += *histp++) >= sum2) break;  // Condition moved inside loop body, reducing control complexity in for-statement
    }
}
