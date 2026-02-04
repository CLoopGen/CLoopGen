#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef unsigned char UChar;

typedef int Int32;

typedef unsigned short UInt16;

extern UInt32 *ptr;
extern UChar *block;
extern UInt32 *ftab;
extern Int32 i;
extern Int32 j;
extern UInt16 s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index mapping array (simulated via arithmetic)
    // Introduce indirect addressing by using a fixed offset table to access 'block' elements non-sequentially
    const int offsets[4] = {0, -3, -1, -2}; // Custom access order: i, i-3, i-1, i-2
    for (; i >= 3; i -= 4) {
        for (int k = 0; k < 4; ++k) {
            int idx = i + offsets[k];
            s = (s >> 8) | (block[idx] << 8);
            j = ftab[s] - 1;
            ftab[s] = j;
            ptr[j] = idx;
        }
        // Update s for next iteration assuming block[i-3] was last used
        s = (s >> 8) | (block[i - 3] << 8);
    }
}
