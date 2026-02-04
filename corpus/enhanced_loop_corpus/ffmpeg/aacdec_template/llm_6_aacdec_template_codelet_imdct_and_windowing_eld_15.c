#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern  int n2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp1 = 0, temp2 = 0;
    for (i = 0; i < n2; i += 2) {
        temp1 = i + 1;
        temp2 = temp1 * 2;  // RAW dependency: temp2 depends on temp1
        // No loop-carried dependency; all operations are local to the iteration
    }
}
