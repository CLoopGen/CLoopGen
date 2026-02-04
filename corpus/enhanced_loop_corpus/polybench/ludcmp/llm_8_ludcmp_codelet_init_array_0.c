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
int i;
for (i = 0; i < n; i += 2) {
    if (i + 1 < n) {
        x[i] = 0;
        x[i+1] = 0;
        y[i] = 0;
        y[i+1] = 0;
        b[i] = (i + 1) / fn / 2. + 4;
        b[i+1] = (i + 2) / fn / 2. + 4;
    } else {
        x[i] = 0;
        y[i] = 0;
        b[i] = (i + 1) / fn / 2. + 4;
    }
}
}
