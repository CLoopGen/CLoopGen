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
    // Variant 2: Reduced computational intensity with simplified indexing and increased trip count via padding
    // Simulate higher trip count by repeating the pattern twice within bounds
    int extendedCount = NumberIntraPerPicture * 2;
    int offset = WalkAround % NumberOfMBs;
    for (j = 0, i = 0; j < extendedCount; j++, i++) {
        int srcIndex = (offset + i) % NumberOfMBs;
        int destIndex = j / 2;  // Write every element twice, effectively halving unique writes
        if (destIndex < NumberIntraPerPicture) {
            IntraMBs[destIndex] = RefreshPattern[srcIndex];
        }
    }
}
