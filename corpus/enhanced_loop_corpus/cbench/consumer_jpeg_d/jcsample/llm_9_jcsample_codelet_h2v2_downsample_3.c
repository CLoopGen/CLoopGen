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
for (outrow = 0; outrow < (compptr->v_samp_factor >> 1); outrow++) {
    outptr = output_data[outrow * 2];
    inptr0 = input_data[inrow];
    inptr1 = input_data[inrow + 1];
    bias = 1;
    for (outcol = 0; outcol < (output_cols >> 1); outcol++) {
        JSAMPLE val0 = (JSAMPLE)((((int)(*inptr0)) + ((int)(inptr0[1])) + ((int)(*inptr1)) + ((int)(inptr1[1])) + bias) >> 2);
        *outptr++ = val0;
        bias ^= 3;
        inptr0 += 2;
        inptr1 += 2;
    }
    inrow += 2;

    if (outrow * 2 + 1 < compptr->v_samp_factor) {
        JSAMPROW outptr2 = output_data[outrow * 2 + 1];
        JSAMPROW inptr2 = input_data[inrow];
        JSAMPROW inptr3 = input_data[inrow + 1];
        int local_bias = 1;
        JDIMENSION col;
        for (col = 0; col < output_cols; col++) {
            *outptr2++ = (JSAMPLE)((((int)(*inptr2)) + ((int)(inptr2[1])) + ((int)(*inptr3)) + ((int)(inptr3[1])) + local_bias) >> 2);
            local_bias ^= 3;
            inptr2 += 2;
            inptr3 += 2;
        }
        inrow += 2;
    }
}
}
