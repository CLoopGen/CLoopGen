#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned int JDIMENSION;

typedef int boolean;

typedef unsigned short UINT16;

typedef struct {
    UINT16 quantval[64];
    boolean sent_table;
} JQUANT_TBL;

typedef struct {
    int component_id;
    int component_index;
    int h_samp_factor;
    int v_samp_factor;
    int quant_tbl_no;
    int dc_tbl_no;
    int ac_tbl_no;
    JDIMENSION width_in_blocks;
    JDIMENSION height_in_blocks;
    int DCT_scaled_size;
    JDIMENSION downsampled_width;
    JDIMENSION downsampled_height;
    boolean component_needed;
    int MCU_width;
    int MCU_height;
    int MCU_blocks;
    int MCU_sample_width;
    int last_col_width;
    int last_row_height;
    JQUANT_TBL *quant_table;
    void *dct_table;
} jpeg_component_info;

typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef JSAMPROW *JSAMPARRAY;

typedef long JLONG;

extern jpeg_component_info *compptr;
extern JSAMPARRAY input_data;
extern JSAMPARRAY output_data;
extern JSAMPROW inptr0;
extern JSAMPROW inptr1;
extern JSAMPROW outptr;
extern JLONG thiscolsum;
extern JLONG lastcolsum;
extern JLONG nextcolsum;
extern JDIMENSION colctr;
extern int inrow;
extern int outrow;
extern int v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access Pattern
    // We modify the access pattern to use a fixed stride over a flattened view of the image data.
    // Assume input_data is treated as a large linear buffer with known row stride.
    // This variant simulates a strided access useful in tiled or padded image processing.

    JDIMENSION width = compptr->downsampled_width;
    JDIMENSION stride = width; // Effective stride (could be larger in real systems with padding)

    for (v = 0; v < 2; v++) {
        int offset0 = inrow * stride;
        int offset1 = (v == 0 ? (inrow - 1) : (inrow + 1)) * stride;
        outptr = output_data[outrow++];

        JSAMPROW full_input = &input_data[0][0]; // Flattened view assumption

        // First two pixels via strided access
        thiscolsum = full_input[offset0 + 0] * 3 + full_input[offset1 + 0];
        nextcolsum = full_input[offset0 + 1] * 3 + full_input[offset1 + 1];
        *outptr++ = (JSAMPLE)((thiscolsum * 4 + 8) >> 4);
        *outptr++ = (JSAMPLE)((thiscolsum * 3 + nextcolsum + 7) >> 4);

        lastcolsum = thiscolsum;
        thiscolsum = nextcolsum;

        // Inner loop using stride-indexed access
        for (colctr = width - 2; colctr > 0; colctr--) {
            int idx = (width - colctr + 1); // Increasing column index
            nextcolsum = full_input[offset0 + idx] * 3 + full_input[offset1 + idx];
            *outptr++ = (JSAMPLE)((thiscolsum * 3 + lastcolsum + 8) >> 4);
            *outptr++ = (JSAMPLE)((thiscolsum * 3 + nextcolsum + 7) >> 4);
            lastcolsum = thiscolsum;
            thiscolsum = nextcolsum;
        }

        // Last two outputs
        *outptr++ = (JSAMPLE)((thiscolsum * 3 + lastcolsum + 8) >> 4);
        *outptr++ = (JSAMPLE)((thiscolsum * 4 + 7) >> 4);
    }
}
