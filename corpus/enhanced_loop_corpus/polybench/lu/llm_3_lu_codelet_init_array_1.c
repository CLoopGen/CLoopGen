#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int r;
extern int s;
extern double (*B)[2000][2000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (r = 0; r < n * n; ++r) {
    int i = r / n;
    int j = r % n;
    (*B)[i][j] = 0;
}
}
