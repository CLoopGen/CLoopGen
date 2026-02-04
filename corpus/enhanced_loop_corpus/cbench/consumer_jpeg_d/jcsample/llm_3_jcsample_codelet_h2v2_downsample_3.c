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

extern jpeg_component_info *compptr;
extern JSAMPARRAY input_data;
extern JSAMPARRAY output_data;
extern int inrow;
extern int outrow;
extern JDIMENSION outcol;
extern JDIMENSION output_cols;
extern JSAMPROW inptr0;
extern JSAMPROW inptr1;
extern JSAMPROW outptr;
extern int bias;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — process every other column first, then the odd-offset columns (interleaved access pattern)
    for (outrow = 0; outrow < compptr->v_samp_factor; outrow++) {
        outptr = output_data[outrow];
        inptr0 = input_data[inrow];
        inptr1 = input_data[inrow + 1];

        // First pass: even-indexed output columns (0, 2, 4, ...)
        int bias_even = 1;
        for (outcol = 0; outcol < output_cols; outcol += 2) {
            JDIMENSION offset = outcol;
            JSAMPROW base0 = inptr0 + 2 * offset;
            JSAMPROW base1 = inptr1 + 2 * offset;
            outptr[offset] = (JSAMPLE)((((int)(base0[0])) + ((int)(base0[1])) +
                                        ((int)(base1[0])) + ((int)(base1[1])) + bias_even) >> 2);
            bias_even ^= 3;
        }

        // Second pass: odd-indexed output columns (1, 3, 5, ...)
        int bias_odd = (output_cols > 0) ? (bias_even ^ 3) : 1; // Adjust initial bias based on prior state
        for (outcol = 1; outcol < output_cols; outcol += 2) {
            JDIMENSION offset = outcol;
            JSAMPROW base0 = inptr0 + 2 * offset;
            JSAMPROW base1 = inptr1 + 2 * offset;
            outptr[offset] = (JSAMPLE)((((int)(base0[0])) + ((int)(base0[1])) +
                                        ((int)(base1[0])) + ((int)(base1[1])) + bias_odd) >> 2);
            bias_odd ^= 3;
        }

        inrow += 2;
    }
}
