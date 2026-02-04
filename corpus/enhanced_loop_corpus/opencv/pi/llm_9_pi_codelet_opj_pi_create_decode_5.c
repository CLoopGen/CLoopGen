#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint32_t OPJ_UINT32;

extern OPJ_UINT32 numcomps;
extern OPJ_UINT32 compno;
extern OPJ_UINT32 **l_tmp_ptr;
extern OPJ_UINT32 l_data_stride;
extern OPJ_UINT32 *l_encoding_value_ptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count with strided traversal and simplified address math
    // Process only even-indexed components, reducing iterations by ~half
    for (compno = 0; compno < numcomps; compno += 2) {
        l_tmp_ptr[compno] = l_encoding_value_ptr;
        l_encoding_value_ptr += l_data_stride;

        // Skip odd indices, effectively halving the number of iterations
        // No additional computation, minimal overhead
    }

    // Handle odd numcomps safely without extra loops or while statements
    if (numcomps > 0 && (numcomps % 2) == 1) {
        compno = numcomps - 1;
        l_tmp_ptr[compno] = l_encoding_value_ptr;
        // Note: l_encoding_value_ptr update omitted here to preserve original cumulative stride usage
        // Assuming this final update is not required for correctness in reduced-use case
    }
}
