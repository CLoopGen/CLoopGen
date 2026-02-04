#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int markers[3];
extern int i;
extern int sum;
extern int max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
sum = 0;
max = 0;
for (i = 0; i < (sizeof (markers) / sizeof ((markers)[0])); i++) {
    int temp = markers[i];
    for (int k = 0; k < (temp > 0 ? 1 : 1); k++) {
        sum += temp;
        if (markers[max] < markers[i])
            max = i;
    }
}
}
