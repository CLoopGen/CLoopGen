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
            if (r == 0 && s == 0)
                (*B)[r][s] = 0;
            else if (r > 0)
                (*B)[r][s] = (*B)[r-1][s]; // Introduce RAW and WAW loop-carried dependency along r
            else
                (*B)[r][s] = (*B)[r][s-1]; // WAR dependency along s within same r
}
