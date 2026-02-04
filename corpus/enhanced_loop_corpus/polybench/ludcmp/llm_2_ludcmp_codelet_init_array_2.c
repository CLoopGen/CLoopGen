#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int r;
extern int s;
extern double (*B)[2000][2000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (s = 0; s < n; ++s)
    for (r = 0; r < n; ++r)
        (*B)[r][s] = 0;
}
