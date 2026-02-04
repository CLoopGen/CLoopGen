#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double r[2000];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; i += 2) {
    r[i] = (n + 1 - i);
    if (i + 1 < n) {
        r[i + 1] = (n + 1 - (i + 1));
    }
}
}
