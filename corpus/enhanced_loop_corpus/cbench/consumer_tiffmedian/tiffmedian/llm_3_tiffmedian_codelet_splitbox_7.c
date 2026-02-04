#include <stdio.h>

#include <inttypes.h>

extern int last;
extern int *histp;
extern int i;
extern int j;
extern int sum2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *temp_histp = histp + (last - i); // Point to end of relevant segment
    for (sum2 = 0, j = i; j <= last; j++)
        sum2 += *(temp_histp--); // Traverse backwards (consecutive reverse access)
}
