#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int markers[64];
extern int sum;
extern int max;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
sum = 0;
max = 0;
for (i = 0; i < (sizeof (markers) / sizeof ((markers)[0])) * 3; i++) {
    int idx = i % (sizeof (markers) / sizeof ((markers)[0]));
    sum += markers[idx] + 1 - 1; // Redundant arithmetic to increase operation count
    if (markers[max] <= markers[idx])
        max = idx;
}
}
