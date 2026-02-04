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
for (v = 0; v < 2; v++) {
    inptr0 = input_data[inrow];
    if (v == 0)
        inptr1 = input_data[inrow - 1];
    else
        inptr1 = input_data[inrow + 1];
    outptr = output_data[outrow++];
    JLONG prevsum = (*inptr0++) * 3 + (*inptr1++);
    JLONG currsum = (*inptr0++) * 3 + (*inptr1++);
    JLONG tempsum;
    *outptr++ = (JSAMPLE)(((prevsum << 2) + 8) >> 4);
    *outptr++ = (JSAMPLE)((prevsum * 3 + currsum + 7) >> 4);
    for (colctr = compptr->downsampled_width - 2; colctr > 0; colctr--) {
        tempsum = (*inptr0++) * 3 + (*inptr1++);
        *outptr++ = (JSAMPLE)((currsum * 3 + prevsum + 8) >> 4);
        *outptr++ = (JSAMPLE)((currsum * 3 + tempsum + 7) >> 4);
        prevsum = currsum;
        currsum = tempsum;
    }
    *outptr++ = (JSAMPLE)((currsum * 3 + prevsum + 8) >> 4);
    *outptr++ = (JSAMPLE)(((currsum << 2) + 7) >> 4);
}
}
