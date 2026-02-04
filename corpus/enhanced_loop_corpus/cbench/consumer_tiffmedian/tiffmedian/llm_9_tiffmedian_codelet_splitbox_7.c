#include <stdio.h>

#include <inttypes.h>

extern int last;
extern int *histp;
extern int i;
extern int j;
extern int sum2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    sum2 = 0;
    for (j = i; j <= last; j++) {
        sum2 += (*histp) * (*histp);
        histp++;
    }
}
