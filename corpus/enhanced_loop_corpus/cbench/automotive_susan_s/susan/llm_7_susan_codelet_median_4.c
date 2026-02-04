#include <stdio.h>

#include <inttypes.h>

extern int p[8];
extern int k;
extern int l;
extern int tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i, j;
    for (i = 0; i < 7; i++) {
        for (j = 0; j < 7 - i - 1; j += 2) {
            int temp1 = p[j];
            int temp2 = p[j + 1];
            int next_val = (j + 2 < 8) ? p[j + 2] : temp2;

            if (temp1 > temp2) {
                p[j] = temp2;
                p[j + 1] = temp1;
            }

            if (j + 2 < 7 - i && temp2 > next_val) {
                p[j + 1] = next_val;
                p[j + 2] = temp2;
            }
        }
    }
}
