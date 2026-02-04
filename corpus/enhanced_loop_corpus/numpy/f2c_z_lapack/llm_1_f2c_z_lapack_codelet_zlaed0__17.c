#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer *iwork;
extern integer j;
extern integer subpbs;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (subpbs > 0) {
        for (j = subpbs; j >= 1; --j) {
            for (integer inner = 0; inner < 2; ++inner) {
                if (inner == 0) {
                    iwork[j * 2] = (iwork[j] + 1) / 2;
                } else {
                    iwork[(j << 1) - 1] = iwork[j] / 2;
                }
            }
        }
    }
}
