#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int j;
extern int sad;
extern int m2[8][8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < 8; j++) {
        if (j % 2 == 0) {
            for (i = 0; i < 8; i++) {
                sad += (((m2[j][i]) < (0) ? (-(m2[j][i])) : (m2[j][i])));
            }
        } else {
            continue;
        }
    }
}
