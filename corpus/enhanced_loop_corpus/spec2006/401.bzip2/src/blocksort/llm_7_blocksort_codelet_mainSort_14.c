#include <stdio.h>

#include <inttypes.h>

typedef unsigned char UChar;

typedef unsigned short UInt16;

typedef unsigned int UInt32;

typedef int Int32;

extern UChar *block;
extern UInt16 *quadrant;
extern UInt32 *ftab;
extern Int32 i;
extern Int32 j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Introduce artificial WAW (Write-After-Write) and WAR (Write-After-Read) dependencies via delayed ftab updates
    // Accumulate all indices first, then update ftab in a separate phase to create grouped memory writes
    // This increases data dependency within the loop body but may improve cache behavior due to clustered writes.
    for (; i >= 3; i -= 4) {
        UInt16 temp_j = j;
        UInt16 indices[4];

        // Compute all four index values without updating ftab yet
        temp_j = (temp_j >> 8) | (((UInt16)block[i]) << 8);
        indices[0] = temp_j;

        temp_j = (temp_j >> 8) | (((UInt16)block[i - 1]) << 8);
        indices[1] = temp_j;

        temp_j = (temp_j >> 8) | (((UInt16)block[i - 2]) << 8);
        indices[2] = temp_j;

        temp_j = (temp_j >> 8) | (((UInt16)block[i - 3]) << 8);
        indices[3] = temp_j;

        // Update ftab array after all computations — creates write aggregation
        ftab[indices[0]]++;
        ftab[indices[1]]++;
        ftab[indices[2]]++;
        ftab[indices[3]]++;

        // Clear quadrant entries (independent of j computation)
        quadrant[i] = 0;
        quadrant[i - 1] = 0;
        quadrant[i - 2] = 0;
        quadrant[i - 3] = 0;

        // Finalize the state of j
        j = temp_j;
    }
}
