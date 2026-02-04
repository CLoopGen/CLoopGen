#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double x[2000];
extern double z[2000];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; i++) {
    if (i % 2 == 0) {
        x[i] = x[i] + z[i];
    } else {
        x[i] = x[i];
    }
}
}
