#include <stdio.h>

#include <inttypes.h>

extern int first;
extern int last;
extern int *histp;
extern int i;
extern int sum;
extern int sum2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = first; i <= last && (sum += *histp++) < sum2; ++i) {
        if (sum % 2 == 0) {
            continue;
        }
    }
}
