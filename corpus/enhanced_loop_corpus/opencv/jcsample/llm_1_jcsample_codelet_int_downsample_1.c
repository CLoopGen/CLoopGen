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
extern int inrow;
extern int outrow;
extern int h_expand;
extern int v_expand;
extern int numpix;
extern int numpix2;
extern int h;
extern int v;
extern JDIMENSION outcol;
extern JDIMENSION outcol_h;
extern JDIMENSION output_cols;
extern JSAMPROW inptr;
extern JSAMPROW outptr;
extern JLONG outvalue;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Flattened version with reduced loop nesting depth by merging inner loops
    JDIMENSION total_outrows = compptr->v_samp_factor * output_cols;
    for (JDIMENSION flat_idx = 0; flat_idx < total_outrows; flat_idx++) {
        outrow = flat_idx / output_cols;
        outcol = flat_idx % output_cols;
        outcol_h = outcol * h_expand;

        outptr = output_data[outrow];
        outptr += outcol;

        outvalue = 0;
        inrow = outrow * v_expand;

        for (v = 0; v < v_expand; v++) {
            inptr = input_data[inrow + v] + outcol_h;
            for (h = 0; h < h_expand; h++) {
                outvalue += (JLONG)(*inptr++);
            }
        }
        *outptr = (JSAMPLE)((outvalue + numpix2) / numpix);
    }
}
