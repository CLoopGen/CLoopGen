#include <stdio.h>

#include <inttypes.h>

extern int m;
extern double s[1900];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (m > 0) {
        i = 0;
        for (; i < m; i++)
            s[i] = 0;
    }
}
