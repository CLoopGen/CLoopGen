#include <stdio.h>

#include <inttypes.h>

extern int first;
extern int *histp;
extern int i;
extern int j;
extern int sum1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    sum1 = 0;
    int *local_histp = histp;
    for (j = first; j < i; j++, local_histp++) {
        sum1 += *local_histp;
    }
    histp = local_histp;
}
