#include <stdio.h>

#include <inttypes.h>

typedef double NV;

extern int freq[200];
extern int i;
extern int max;
extern NV sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int outer;
for (outer = max; outer > 0; outer--) {
    i = outer;
    sum += freq[i] * i * i;
    if (i > 1) {
        for (i = max - 1; i > 0; i--) {
            sum += freq[i] * i * i;
        }
    }
}
}
