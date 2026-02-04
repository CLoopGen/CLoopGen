#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int t1 = 0;
int t2 = 0;
for (x = 0; x < 8; x++) {
    t1 = x + 1;      // WAW dependency on t1 across iterations
    t2 = t1 * x;     // RAW dependency: t2 uses updated t1, loop-carried dependence via t1
}
// Final values of t1 and t2 depend on last iteration — creates loop-carried dependency
}
