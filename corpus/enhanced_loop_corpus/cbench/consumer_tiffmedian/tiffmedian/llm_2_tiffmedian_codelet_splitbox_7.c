#include <stdio.h>

#include <inttypes.h>

extern int last;
extern int *histp;
extern int i;
extern int j;
extern int sum2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (sum2 = 0, j = i; j <= last; j += 2)
        sum2 += *(histp++) + (j + 1 <= last ? *histp++ : 0);
}
