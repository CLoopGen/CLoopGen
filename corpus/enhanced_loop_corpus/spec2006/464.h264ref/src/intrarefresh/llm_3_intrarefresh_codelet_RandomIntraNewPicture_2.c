#include <stdio.h>

#include <inttypes.h>

extern int *RefreshPattern;
extern int *IntraMBs;
extern int WalkAround;
extern int NumberOfMBs;
extern int NumberIntraPerPicture;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access with Indirect Indexing
    // Introduce an index array that defines a non-sequential, strided access pattern into RefreshPattern.
    // This simulates more complex memory behavior, such as accessing every k-th macroblock.
    int stride = (NumberOfMBs / NumberIntraPerPicture) | 1; // Ensure odd stride for variation
    for (j = 0; j < NumberIntraPerPicture; j++) {
        int index = (WalkAround + j * stride) % NumberOfMBs;
        if (index < 0) index += NumberOfMBs; // Handle negative mod if needed
        IntraMBs[j] = RefreshPattern[index];
    }
}
