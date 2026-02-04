#include <stdio.h>

#include <inttypes.h>

extern int *r;
extern int size;
extern int i;
extern int max_r;
extern int min_r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < size; i++) {
        int val = r[i];
        if (val > max_r) {
            max_r = val;
        } else if (val < min_r) {
            min_r = val;
        }
    }
}
