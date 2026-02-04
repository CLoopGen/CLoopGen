#include <stdio.h>

#include <inttypes.h>

extern int *r;
extern int size;
extern int i;
extern int max_r;
extern int min_r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int temp_max = max_r;
int temp_min = min_r;
for (i = 0; i < size; i += 2) {
    if (i + 1 < size) {
        if (r[i] > r[i + 1]) {
            if (r[i] > temp_max)
                temp_max = r[i];
            if (r[i + 1] < temp_min)
                temp_min = r[i + 1];
        } else {
            if (r[i + 1] > temp_max)
                temp_max = r[i + 1];
            if (r[i] < temp_min)
                temp_min = r[i];
        }
    } else {
        if (r[i] > temp_max)
            temp_max = r[i];
        if (r[i] < temp_min)
            temp_min = r[i];
    }
}
max_r = temp_max;
min_r = temp_min;
}
