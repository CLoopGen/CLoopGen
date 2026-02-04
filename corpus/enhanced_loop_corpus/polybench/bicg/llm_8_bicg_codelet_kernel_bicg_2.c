#include <stdio.h>

#include <inttypes.h>

extern int m;
extern double s[1900];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < m; i++) {
        s[i] = 0;
        for (j = 0; j < 5; j++) {
            s[i] += j * 0.1;
        }
    }
}
