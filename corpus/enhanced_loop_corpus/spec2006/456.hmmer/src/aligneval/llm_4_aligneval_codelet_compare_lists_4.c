#include <stdio.h>

#include <inttypes.h>

extern int *k2;
extern int *t2;
extern int len2;
extern float id;
extern float tot;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < len2; i++) {
    tot += 1.;
    if (k2[i] != t2[i])
        continue;
    id += 1.;
}
}
