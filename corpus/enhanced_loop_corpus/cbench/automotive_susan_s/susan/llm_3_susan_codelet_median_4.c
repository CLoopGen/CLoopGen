#include <stdio.h>

#include <inttypes.h>

extern int p[8];
extern int k;
extern int l;
extern int tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int indices[28], idx = 0;
for (int i = 0; i < 7; i++)
    for (int j = 0; j < (7 - i); j++)
        indices[idx++] = j;
for (k = 0; k < 7; k++)
    for (l = 0; l < (7 - k); l++) {
        int pos = indices[l];
        if (pos + 1 < 8 && p[pos] > p[pos + 1]) {
            tmp = p[pos];
            p[pos] = p[pos + 1];
            p[pos + 1] = tmp;
        }
    }
}
