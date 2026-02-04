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
for (i = 0; i < (sizeof (markers) / sizeof ((markers)[0])); i++) {
    sum += markers[i];
    if (markers[max] < markers[i])
        max = i;
}

}
