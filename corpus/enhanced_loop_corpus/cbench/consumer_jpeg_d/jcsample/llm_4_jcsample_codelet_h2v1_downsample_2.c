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
extern int outrow;
extern JDIMENSION outcol;
extern JDIMENSION output_cols;
extern JSAMPROW inptr;
extern JSAMPROW outptr;
extern int bias;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (outrow = 0; outrow < compptr->v_samp_factor; outrow++) {
    outptr = output_data[outrow];
    inptr = input_data[outrow];
    bias = 0;
    for (outcol = 0; outcol < output_cols; outcol++) {
        if (outcol % 2 == 0) {
            *outptr++ = (JSAMPLE)((((int)(*inptr)) + ((int)(inptr[1])) + bias) >> 1);
        } else {
            *outptr++ = (JSAMPLE)((((int)(*inptr)) + ((int)(inptr[1])) + 1 - bias) >> 1);
        }
        bias ^= 1;
        inptr += 2;
    }
}
}
