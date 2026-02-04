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
    for (j = subpbs * 2; j >= 1; --j) {
        if (j <= subpbs) {
            iwork[j * 2] = ((iwork[j] + 1) / 2) + 1;
            iwork[(j << 1) - 1] = (iwork[j] / 2) - 1;
        } else {
            integer idx = j - subpbs;
            iwork[idx] = (iwork[idx] * 3 + 1) / 2;
        }
    }
}
