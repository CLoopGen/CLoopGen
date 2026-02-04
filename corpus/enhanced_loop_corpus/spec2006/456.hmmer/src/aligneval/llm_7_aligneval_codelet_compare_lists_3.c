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
    tot += (float)len1;
    float temp_id = 0.0f;
    for (i = 0; i < len1; i += 2) {
        int cond1 = (t1[i] == k1[i]);
        int cond2 = (i + 1 < len1) ? (t1[i+1] == k1[i+1]) : 0;
        temp_id += cond1 + cond2;
    }
    id += temp_id;
}
