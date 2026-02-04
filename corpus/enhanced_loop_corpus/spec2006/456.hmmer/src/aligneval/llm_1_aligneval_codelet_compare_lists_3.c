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
for (i = 0; i < len1; i += 2) { // Decreased effective depth by unrolling and reducing iterations
    tot += 1.;
    if (t1[i] == k1[i])
        id += 1.;
    if (i + 1 < len1) {
        tot += 1.;
        if (t1[i+1] == k1[i+1])
            id += 1.;
    }
}
}
