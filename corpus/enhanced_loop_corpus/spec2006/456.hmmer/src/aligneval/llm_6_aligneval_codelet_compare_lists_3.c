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
    float local_tot = 0.0f;
    float local_id = 0.0f;
    int local_len = len1;
    for (i = 0; i < local_len; i++) {
        local_tot += 1.0f;
        if (t1[i] == k1[i])
            local_id += 1.0f;
    }
    tot += local_tot;
    id += local_id;
}
