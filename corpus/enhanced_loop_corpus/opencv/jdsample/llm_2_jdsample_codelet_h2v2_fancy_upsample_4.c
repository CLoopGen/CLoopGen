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
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of using separate pointers (inptr0, inptr1) that are updated via post-increment,
    // we precompute base indices and access input_data as a 2D array with consecutive column traversal.
    // This improves spatial locality by accessing memory in increasing order without pointer arithmetic side effects.

    for (v = 0; v < 2; v++) {
        JDIMENSION width = compptr->downsampled_width;
        int in_index = (v == 0) ? inrow - 1 : inrow + 1;
        JSAMPROW row0 = input_data[inrow];
        JSAMPROW row1 = input_data[in_index];
        outptr = output_data[outrow++];

        // First two samples using direct indexing
        thiscolsum = row0[0] * 3 + row1[0];
        nextcolsum = row0[1] * 3 + row1[1];
        *outptr++ = (JSAMPLE)((thiscolsum * 4 + 8) >> 4);
        *outptr++ = (JSAMPLE)((thiscolsum * 3 + nextcolsum + 7) >> 4);

        lastcolsum = thiscolsum;
        thiscolsum = nextcolsum;

        // Main loop: sequential index-based access
        for (colctr = width - 2; colctr > 0; colctr--) {
            nextcolsum = row0[(width - colctr) + 1] * 3 + row1[(width - colctr) + 1];
            *outptr++ = (JSAMPLE)((thiscolsum * 3 + lastcolsum + 8) >> 4);
            *outptr++ = (JSAMPLE)((thiscolsum * 3 + nextcolsum + 7) >> 4);
            lastcolsum = thiscolsum;
            thiscolsum = nextcolsum;
        }

        // Final two samples
        *outptr++ = (JSAMPLE)((thiscolsum * 3 + lastcolsum + 8) >> 4);
        *outptr++ = (JSAMPLE)((thiscolsum * 4 + 7) >> 4);
    }
}
