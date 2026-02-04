#include <stdio.h>

#include <inttypes.h>

typedef double NV;

extern int freq[200];
extern int i;
extern int max;
extern NV sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    NV temp_sum = 0.0;
    for (int j = max; j > 0; j--) {
        temp_sum += freq[j] * j * j;
    }
    sum = temp_sum;
}
