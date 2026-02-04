#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double b[2000];
extern double x[2000];
extern double y[2000];
extern int i;
extern double fn;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; i++) {
    x[i] = 0;
    y[i] = 0;
    if (i >= 0) {
        b[i] = (i + 1) / fn / 2. + 4;
    }
}
}
