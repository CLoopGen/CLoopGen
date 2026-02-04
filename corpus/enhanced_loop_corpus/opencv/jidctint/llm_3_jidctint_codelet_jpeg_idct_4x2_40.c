#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long INT32;

typedef short JCOEF;

typedef JCOEF *JCOEFPTR;

typedef int ISLOW_MULT_TYPE;

extern INT32 tmp0;
extern INT32 tmp10;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern INT32 *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access via Index Array
    // Use an index array to simulate non-sequential, indirect access pattern
    static const int indices[4] = {0, 2, 1, 3}; // arbitrary permutation to demonstrate indirect access
    INT32 temp0, temp1;
    for (ctr = 0; ctr < 4; ctr++) {
        int idx = indices[ctr]; // indirect indexing
        int in_offset = 8 * idx;
        int q_offset = 8 * idx;
        int ws_offset = 4 * idx;

        temp0 = (((ISLOW_MULT_TYPE)(inptr[in_offset])) * (quantptr[q_offset]));
        temp1 = (((ISLOW_MULT_TYPE)(inptr[in_offset + 8])) * (quantptr[q_offset + 8]));

        wsptr[ws_offset] = temp0 + temp1;
        wsptr[ws_offset + 4] = temp0 - temp1;
    }
}
