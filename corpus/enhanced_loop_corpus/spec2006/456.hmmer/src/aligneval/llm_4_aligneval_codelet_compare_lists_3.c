#include <stdio.h>

#include <inttypes.h>

extern int *k1;
extern int *t1;
extern int len1;
extern float id;
extern float tot;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len1; i++) {
        if (t1[i] != k1[i]) {
            tot += 1.;
            continue;
        }
        tot += 1.;
        id += 1.;
    }
}
