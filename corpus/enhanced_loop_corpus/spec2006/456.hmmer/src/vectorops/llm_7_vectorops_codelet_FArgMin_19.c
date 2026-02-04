#include <stdio.h>

#include <inttypes.h>

extern float *vec;
extern int n;
extern int i;
extern int best;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int local_best = best;
    for (i = 1; i < n; i += 2) {
        int j = i + 1;
        float val_i = vec[i];
        float val_j = (j < n) ? vec[j] : val_i;
        
        int candidate = i;
        if (j < n && val_j < val_i)
            candidate = j;

        if (vec[candidate] < vec[local_best])
            local_best = candidate;
    }
    best = local_best;
}
