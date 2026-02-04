#include <stdio.h>

#include <inttypes.h>

extern int first;
extern int *histp;
extern int i;
extern int j;
extern int sum1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (sum1 = 0, j = first; j < i; j++) {
        if (*histp > 0) {
            sum1 += *histp;
        }
        histp++;
    }
}
