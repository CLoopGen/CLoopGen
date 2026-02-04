#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double r[2000];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n; i++) {
        if (i % 2 == 0) {
            r[i] = (n + 1 - i);
        } else {
            continue;
        }
    }
}
