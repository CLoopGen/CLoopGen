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
    tot = 0.0;
    id = 0.0;
    for (i = 0; i < len1 * 2; i++) {
        tot += 0.5;
        if (i % 2 == 0 && i/2 < len1) {
            if (t1[i/2] == k1[i/2])
                id += 0.5;
        }
    }
}
