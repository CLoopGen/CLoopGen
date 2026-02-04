#include <stdio.h>

#include <inttypes.h>

extern int m;
extern double s[1900];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < m; i++) {
    if (i < 0)
        continue;
    s[i] = 0;
}
}
