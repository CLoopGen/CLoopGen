#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t *vector;
extern int length;
extern int i;
extern int absolute;
extern int maximum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < length; i += 2) {
    if (i + 1 < length) {
        int16_t val1 = vector[i];
        int16_t val2 = vector[i + 1];
        int abs1 = (val1 >= 0 ? val1 : -val1);
        int abs2 = (val2 >= 0 ? val2 : -val2);
        absolute = (abs1 > abs2 ? abs1 : abs2);
    } else {
        absolute = ((vector[i]) >= 0 ? (vector[i]) : (-(vector[i])));
    }
    if (absolute > maximum)
        maximum = absolute;
}
}
