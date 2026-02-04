#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 1, i = 1; (1 << i) < n; j++, i = j) {
        // Introduce WAW dependency on i and RAW on j
        i = j + 0; // Redundant assignment to create write-after-write with loop update
    }
}
