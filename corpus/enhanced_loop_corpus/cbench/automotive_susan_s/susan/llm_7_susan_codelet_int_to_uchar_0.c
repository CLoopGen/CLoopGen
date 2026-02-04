#include <stdio.h>

#include <inttypes.h>

extern int *r;
extern int size;
extern int i;
extern int max_r;
extern int min_r;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    max_r = r[0];
    min_r = r[0];
    for (i = 1; i < size; i += 2) {
        if (i + 1 < size) {
            if (r[i] > r[i + 1]) {
                if (r[i] > max_r) max_r = r[i];
                if (r[i + 1] < min_r) min_r = r[i + 1];
            } else {
                if (r[i + 1] > max_r) max_r = r[i + 1];
                if (r[i] < min_r) min_r = r[i];
            }
        } else {
            if (r[i] > max_r) max_r = r[i];
            if (r[i] < min_r) min_r = r[i];
        }
    }
}
