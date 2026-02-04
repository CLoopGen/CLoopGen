#include <stdio.h>

#include <inttypes.h>

typedef double NV;

extern int freq[200];
extern int i;
extern int max;
extern NV sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (j = 1; j <= max; j++) {
    for (i = j; i > 0; i--) {
        sum += freq[i] * i * i;
    }
}
}
