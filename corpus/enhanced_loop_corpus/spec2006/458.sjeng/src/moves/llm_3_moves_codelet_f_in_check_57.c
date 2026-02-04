#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive access using an index remapping (indirect-like access via lookup table simulation)
    // Simulate consecutive iteration over a transformed index space by precomputing offsets.
    // We simulate a fixed offset list for consecutive access to diagonal positions.
    const int stride = -11;
    int offset = bking_loc + stride;
    for (int i = 0; board[offset + i * stride] == 13; ++i) {
        l = offset + i * stride;
    }
    // Final value of l matches last accessed location before condition fails
}
