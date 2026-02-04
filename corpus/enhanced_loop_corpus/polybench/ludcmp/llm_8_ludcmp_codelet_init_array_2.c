#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int r;
extern int s;
extern double (*B)[2000][2000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (r = 0; r < n; ++r)
    for (s = 0; s < n; ++s)
        for (int t = 0; t < n; ++t)
            (*B)[r][s] += 1.0 / (r + s + t + 1);

}
