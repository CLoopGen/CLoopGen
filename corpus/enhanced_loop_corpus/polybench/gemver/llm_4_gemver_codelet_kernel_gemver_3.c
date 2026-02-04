#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double x[2000];
extern double z[2000];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; i++) {
    if (z[i] == 0.0) {
        continue;
    }
    x[i] = x[i] + z[i];
}
}
