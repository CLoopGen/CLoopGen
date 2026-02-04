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
extern INT32 outvalue;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    JDIMENSION total_rows = compptr->v_samp_factor;
    JDIMENSION total_cols = output_cols;
    JDIMENSION row, col;
    for (row = 0; row < total_rows; row++) {
        JSAMPROW local_outptr = output_data[row];
        JDIMENSION input_base_row = inrow + row * v_expand;
        for (col = 0; col < total_cols; col++) {
            INT32 accumulator = 0;
            JDIMENSION in_h = col * h_expand;
            JDIMENSION in_v;
            for (in_v = 0; in_v < v_expand; in_v++) {
                JSAMPROW local_inptr = input_data[input_base_row + in_v] + in_h;
                int h_idx;
                for (h_idx = 0; h_idx < h_expand; h_idx++) {
                    accumulator += (INT32)(*(local_inptr + h_idx));
                }
            }
            *(local_outptr + col) = (JSAMPLE)((accumulator + numpix2) / numpix);
        }
    }
    inrow += total_rows * v_expand;
}
