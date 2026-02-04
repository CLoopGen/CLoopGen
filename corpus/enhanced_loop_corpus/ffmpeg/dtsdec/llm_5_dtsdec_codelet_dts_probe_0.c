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
    for (i = 0; i < (sizeof (markers) / sizeof ((markers)[0])); i++) {
        if (i % 2 == 0) {
            sum += markers[i];
        }
        if (markers[i] > markers[max]) {
            max = i;
        }
    }
}
