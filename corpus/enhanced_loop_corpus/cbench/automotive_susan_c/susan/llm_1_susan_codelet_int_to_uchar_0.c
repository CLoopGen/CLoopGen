#include <stdio.h>

#include <inttypes.h>

extern int *r;
extern int size;
extern int i;
extern int max_r;
extern int min_r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < size; i += 2) {
    if (r[i] > max_r)
        max_r = r[i];
    if (r[i] < min_r)
        min_r = r[i];
    if (i + 1 < size) {
        if (r[i+1] > max_r)
            max_r = r[i+1];
        if (r[i+1] < min_r)
            min_r = r[i+1];
    }
}
}
