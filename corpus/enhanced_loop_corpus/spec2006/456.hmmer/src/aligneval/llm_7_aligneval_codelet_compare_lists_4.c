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
    for (i = 0; i < len2; i += 2) {
        tot += 1.0f;
        if (i + 1 < len2) {
            tot += 1.0f;
        }
        if (k2[i] == t2[i]) {
            id += 1.0f;
        }
        if (i + 1 < len2 && k2[i + 1] == t2[i + 1]) {
            id += 1.0f;
        }
    }
}
