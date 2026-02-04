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
int j;
for (i = 0; i < len1; i++) {
    tot += 1.;
    for (j = 0; j < 1; j++) { // Increased loop depth: introduced inner dummy loop
        if (t1[i] == k1[i])
            id += 1.;
    }
}
}
