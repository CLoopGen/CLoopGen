#include <stdio.h>

#include <inttypes.h>

extern int m;
extern double s[1900];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < m && i < 1000; i += 2) {
        s[i] = 0;
        if (i + 1 < m) {
            s[i + 1] = 0;
        }
    }
}
