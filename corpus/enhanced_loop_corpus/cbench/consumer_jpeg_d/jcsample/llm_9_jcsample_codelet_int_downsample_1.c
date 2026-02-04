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
if (compptr->v_samp_factor <= 0 || output_cols <= 0) return;
outrow = 0;
inrow = 0;
while (outrow < compptr->v_samp_factor) {
    outptr = output_data[outrow];
    outcol = 0;
    while (outcol < output_cols) {
        outvalue = 0;
        int v_offset = inrow;
        for (int i = 0; i < v_expand; i++) {
            inptr = input_data[v_offset + i] + (outcol * h_expand);
            int h_idx = 0;
            while (h_idx < h_expand) {
                outvalue += (INT32)(*inptr++);
                h_idx++;
            }
        }
        *outptr++ = (JSAMPLE)((outvalue + numpix2) / numpix);
        outcol++;
    }
    inrow += v_expand;
    outrow++;
}
}
