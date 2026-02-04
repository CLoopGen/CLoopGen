#include <stdio.h>

#include <inttypes.h>

typedef short word;

extern word *LARpp_j;
extern word *LARp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive write, reversed read access (processing array from end)
    word *temp_LARp = LARp;
    word *temp_LARpp_j = LARpp_j + 7;  // Point to the last element to be read
    for (i = 1; i <= 8; i++, temp_LARp++, temp_LARpp_j--)
        *temp_LARp = *temp_LARpp_j;
}
