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
    for (i = 0; i < (sizeof (markers) / sizeof ((markers)[0])); i += 2) {
        int val1 = markers[i];
        sum += val1;
        if (val1 > markers[max])
            max = i;

        if (i + 1 < (sizeof (markers) / sizeof ((markers)[0]))) {
            int val2 = markers[i + 1];
            sum += val2;
            if (val2 > markers[max])
                max = i + 1;
        }
    }
}
