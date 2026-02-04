#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int r;
extern int s;
extern double (*B)[2000][2000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (r = 0; r < n; r += 2)
    for (s = 0; s < n; s += 2)
        if (r < n && s < n) {
            (*B)[r][s] = r + s;
            if (r+1 < n) (*B)[r+1][s] = r + s + 1;
            if (s+1 < n) (*B)[r][s+1] = r + s + 1;
            if (r+1 < n && s+1 < n) (*B)[r+1][s+1] = r + s + 2;
        }

}
