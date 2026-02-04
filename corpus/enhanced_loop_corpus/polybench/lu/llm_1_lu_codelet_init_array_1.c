#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int r;
extern int s;
extern double (*B)[2000][2000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int rs = 0; rs < n * n; ++rs) { // Decreased nesting depth: collapsed two loops into one
    int r = rs / n;
    int s = rs % n;
    (*B)[r][s] = 0;
}
}
