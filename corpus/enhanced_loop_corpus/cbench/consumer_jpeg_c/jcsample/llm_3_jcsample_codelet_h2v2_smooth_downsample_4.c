#include <stdio.h>

#include <inttypes.h>

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

typedef long INT32;

extern jpeg_component_info *compptr;
extern JSAMPARRAY input_data;
extern JSAMPARRAY output_data;
extern int inrow;
extern int outrow;
extern JDIMENSION colctr;
extern JDIMENSION output_cols;
extern JSAMPROW inptr0;
extern JSAMPROW inptr1;
extern JSAMPROW above_ptr;
extern JSAMPROW below_ptr;
extern JSAMPROW outptr;
extern INT32 membersum;
extern INT32 neighsum;
extern INT32 memberscale;
extern INT32 neighscale;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Consecutive memory access with array indices precomputed for coalesced access
for (outrow = 0; outrow < compptr->v_samp_factor; outrow++) {
    JDIMENSION row_offset = outrow;
    JDIMENSION in_center = inrow;
    JDIMENSION in_above = inrow - 1;
    JDIMENSION in_below = inrow + 2;

    outptr = output_data[row_offset];
    JSAMPROW data_center = input_data[in_center];
    JSAMPROW data_next = input_data[in_center + 1];
    JSAMPROW data_above = input_data[in_above];
    JSAMPROW data_below = input_data[in_below];

    // Precompute base pointers and use consecutive indexing
    for (colctr = 0; colctr < output_cols; colctr++) {
        int idx = colctr * 2; // Convert to byte-level index assuming 2-element blocks

        // Load current block values consecutively
        int val_c0 = (int)data_center[idx];
        int val_c1 = (int)data_center[idx + 1];
        int val_n0 = (int)data_next[idx];
        int val_n1 = (int)data_next[idx + 1];

        membersum = val_c0 + val_c1 + val_n0 + val_n1;

        // Neighboring values: include left, right, above, below
        int left_c = (colctr > 0) ? (int)data_center[idx - 1] : val_c0;
        int right_c = (colctr < output_cols - 1) ? (int)data_center[idx + 2] : val_c1;
        int left_n = (colctr > 0) ? (int)data_next[idx - 1] : val_n0;
        int right_n = (colctr < output_cols - 1) ? (int)data_next[idx + 2] : val_n1;

        int val_a0 = (int)data_above[idx];
        int val_a1 = (int)data_above[idx + 1];
        int val_b0 = (int)data_below[idx];
        int val_b1 = (int)data_below[idx + 1];

        int left_a = (colctr > 0) ? (int)data_above[idx - 1] : val_a0;
        int right_a = (colctr < output_cols - 1) ? (int)data_above[idx + 2] : val_a1;
        int left_b = (colctr > 0) ? (int)data_below[idx - 1] : val_b0;
        int right_b = (colctr < output_cols - 1) ? (int)data_below[idx + 2] : val_b1;

        neighsum = val_a0 + val_a1 + val_b0 + val_b1 + left_c + right_c + left_n + right_n;
        neighsum += neighsum; // Multiply by 2
        neighsum += left_a + right_a + left_b + right_b;

        membersum = membersum * memberscale + neighsum * neighscale;
        outptr[colctr] = (JSAMPLE)((membersum + 32768) >> 16);
    }
    inrow += 2;
}
}
