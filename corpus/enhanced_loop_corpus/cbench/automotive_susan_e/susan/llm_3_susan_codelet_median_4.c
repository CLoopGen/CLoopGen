#include <stdio.h>

#include <inttypes.h>

extern int p[8];
extern int k;
extern int l;
extern int tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int *base = &p[0];
for (k = 0; k < 7; k++)
    for (l = 0; l < (7 - k); l++) {
        int *current = base + l;
        int *next = current + 1;
        if (*current > *next) {
            tmp = *current;
            *current = *next;
            *next = tmp;
        }
    }
}
