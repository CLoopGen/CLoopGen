#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *histogram1;
extern float *histogram2;
extern unsigned int *cchange;
extern size_t hsize;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < hsize; i++) {
    int j = 0;
    int found = 0;
    for (; j < hsize && !found; j++) {
        if (histogram2[j] >= histogram1[i]) {
            j--; // Adjust since increment happens after condition
            found = 1;
        }
    }
    if (!found) j = hsize; // In case no element satisfies the condition
    cchange[i] = (i + j) / 2;
}
}
