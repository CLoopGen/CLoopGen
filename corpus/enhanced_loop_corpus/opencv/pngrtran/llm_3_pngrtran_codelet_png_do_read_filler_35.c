#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned int png_uint_32;

typedef unsigned char png_byte;

typedef png_byte *png_bytep;

extern png_uint_32 i;
extern png_uint_32 row_width;
extern png_byte hi_filler;
extern png_byte lo_filler;
extern png_bytep sp;
extern png_bytep dp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access pattern – process every second element first, then fill the rest (unroll-like striding)
    // Simulates a non-unit stride access to create different cache behavior
    png_bytep temp_sp = sp;
    png_bytep temp_dp = dp;

    // First pass: strided access by processing elements at even logical positions (conceptually), stepping by 2 in effective width
    for (i = 0; i < row_width; i += 2) {
        if (i + 1 < row_width) {
            // Handle two iterations at once with strided write pattern to encourage spatial locality changes

            *(--temp_dp) = hi_filler;
            *(--temp_dp) = lo_filler;
            *(--temp_dp) = *(--temp_sp);
            *(--temp_dp) = *(--temp_sp);
            *(--temp_dp) = *(--temp_sp);
            *(--temp_dp) = *(--temp_sp);
            *(--temp_dp) = *(--temp_sp);
            *(--temp_dp) = *(--temp_sp);

            *(--temp_dp) = hi_filler;
            *(--temp_dp) = lo_filler;
            *(--temp_dp) = *(--temp_sp);
            *(--temp_dp) = *(--temp_sp);
            *(--temp_dp) = *(--temp_sp);
            *(--temp_dp) = *(--temp_sp);
            *(--temp_dp) = *(--temp_sp);
            *(--temp_dp) = *(--temp_sp);
        } else {
            // Handle leftover odd element
            *(--temp_dp) = hi_filler;
            *(--temp_dp) = lo_filler;
            *(--temp_dp) = *(--temp_sp);
            *(--temp_dp) = *(--temp_sp);
            *(--temp_dp) = *(--temp_sp);
            *(--temp_dp) = *(--temp_sp);
            *(--temp_dp) = *(--temp_sp);
            *(--temp_dp) = *(--temp_sp);
        }
    }

    // Restore original semantics via final assignment (though side effects on global pointers remain)
    dp = temp_dp;
    sp = temp_sp;
}
