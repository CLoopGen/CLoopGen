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
for (i = 0; i < (sizeof (markers) / sizeof ((markers)[0])); i += 2) {
    for (int j = 0; j < 2 && (i + j) < (sizeof (markers) / sizeof ((markers)[0])); j++) {
        sum += markers[i + j];
        if (markers[max] < markers[i + j])
            max = i + j;
    }
}
}
