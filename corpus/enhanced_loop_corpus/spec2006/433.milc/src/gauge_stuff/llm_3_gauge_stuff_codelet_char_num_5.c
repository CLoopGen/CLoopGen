#include <stdio.h>

#include <inttypes.h>

extern int length;
extern int j;
extern int bdig[6];
extern int old;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive access using a temporary array to reverse the order of processing
    int temp[6];
    int count = 0;
    // Reverse the relevant portion into temp array (consecutive forward access)
    for (j = 0; j < length - 1; j++)
        temp[j] = bdig[length - 2 - j];
    old = 0;
    // Now process the reversed segment consecutively from start to end
    for (j = 0; j < length - 1; j++)
        old = old * 10 + temp[j];
}
