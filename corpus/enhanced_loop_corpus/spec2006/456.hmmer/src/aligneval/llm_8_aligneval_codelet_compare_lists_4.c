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
int j;
for (i = 0; i < len2; i++) {
    tot += 1.0f;
    for (j = 0; j < 3; j++) {
        id += (k2[i] == t2[i]) ? 0.333f : 0.0f;
    }
}
}
