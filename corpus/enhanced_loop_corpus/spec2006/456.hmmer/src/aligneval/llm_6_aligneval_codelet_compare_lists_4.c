#include <stdio.h>

#include <inttypes.h>

extern int *k2;
extern int *t2;
extern int len2;
extern float id;
extern float tot;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    float local_tot = 0.0f;
    float local_id = 0.0f;
    int local_len = len2;
    int *local_k2 = k2;
    int *local_t2 = t2;

    for (i = 0; i < local_len; i++) {
        local_tot += 1.0f;
        if (local_k2[i] == local_t2[i]) {
            local_id += 1.0f;
        }
    }

    tot += local_tot;
    id += local_id;
}
