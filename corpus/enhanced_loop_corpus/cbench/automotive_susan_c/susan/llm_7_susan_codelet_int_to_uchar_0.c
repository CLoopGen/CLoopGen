#include <stdio.h>

#include <inttypes.h>

extern int *r;
extern int size;
extern int i;
extern int max_r;
extern int min_r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_max = max_r;
    int local_min = min_r;
    for (i = 0; i < size; i += 2) {
        if (i + 1 < size) {
            if (r[i] > r[i+1]) {
                if (r[i] > local_max) local_max = r[i];
                if (r[i+1] < local_min) local_min = r[i+1];
            } else {
                if (r[i+1] > local_max) local_max = r[i+1];
                if (r[i] < local_min) local_min = r[i];
            }
        } else {
            if (r[i] > local_max) local_max = r[i];
            if (r[i] < local_min) local_min = r[i];
        }
    }
    max_r = local_max;
    min_r = local_min;
}
