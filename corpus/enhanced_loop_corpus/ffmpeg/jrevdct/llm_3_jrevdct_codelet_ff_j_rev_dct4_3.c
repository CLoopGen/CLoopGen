#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t tmp0;
extern int32_t tmp1;
extern int32_t tmp2;
extern int32_t tmp3;
extern int32_t tmp10;
extern int32_t tmp11;
extern int32_t tmp12;
extern int32_t tmp13;
extern int32_t z1;
extern int32_t d0;
extern int32_t d2;
extern int32_t d4;
extern int32_t d6;
extern int16_t *dataptr;
extern int rowctr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided Memory Access with Increased Stride and Index Array
    const int indices[] = {0, 8, 16, 24};  // Stride of 8 elements between each relevant data point
    int16_t *access_ptr = dataptr;

    for (rowctr = 4 - 1; rowctr >= 0; rowctr--) {
        // Use strided access through index array based on current row
        d0 = access_ptr[indices[rowctr]];
        d2 = access_ptr[indices[rowctr] + 1];
        d4 = access_ptr[indices[rowctr] + 2];
        d6 = access_ptr[indices[rowctr] + 3];

        if (d6) {
            if (d2) {
                z1 = ((d2 + d6) * 4433);
                tmp2 = z1 + ((-d6) * 15137);
                tmp3 = z1 + (d2 * 6270);
                tmp0 = (d0 + d4) << 13;
                tmp1 = (d0 - d4) << 13;
                tmp10 = tmp0 + tmp3;
                tmp13 = tmp0 - tmp3;
                tmp11 = tmp1 + tmp2;
                tmp12 = tmp1 - tmp2;
            } else {
                tmp2 = (-d6) * 10703;
                tmp3 = d6 * 4433;
                tmp0 = (d0 + d4) << 13;
                tmp1 = (d0 - d4) << 13;
                tmp10 = tmp0 + tmp3;
                tmp13 = tmp0 - tmp3;
                tmp11 = tmp1 + tmp2;
                tmp12 = tmp1 - tmp2;
            }
        } else {
            if (d2) {
                tmp2 = d2 * 4433;
                tmp3 = d2 * 10703;
                tmp0 = (d0 + d4) << 13;
                tmp1 = (d0 - d4) << 13;
                tmp10 = tmp0 + tmp3;
                tmp13 = tmp0 - tmp3;
                tmp11 = tmp1 + tmp2;
                tmp12 = tmp1 - tmp2;
            } else {
                tmp0 = (d0 + d4) << 13;
                tmp1 = (d0 - d4) << 13;
                tmp10 = tmp13 = tmp0;
                tmp11 = tmp12 = tmp1;
            }
        }

        // Write back using same strided pattern
        access_ptr[indices[rowctr]]     = tmp10 >> (13 + 2 + 3);
        access_ptr[indices[rowctr] + 1] = tmp11 >> (13 + 2 + 3);
        access_ptr[indices[rowctr] + 2] = tmp12 >> (13 + 2 + 3);
        access_ptr[indices[rowctr] + 3] = tmp13 >> (13 + 2 + 3);
    }
}
