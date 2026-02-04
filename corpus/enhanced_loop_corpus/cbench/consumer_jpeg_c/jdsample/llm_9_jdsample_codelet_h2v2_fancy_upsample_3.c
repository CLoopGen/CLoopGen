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
extern JSAMPROW inptr0;
extern JSAMPROW inptr1;
extern JSAMPROW outptr;
extern int thiscolsum;
extern int lastcolsum;
extern int nextcolsum;
extern JDIMENSION colctr;
extern int inrow;
extern int outrow;
extern int v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (v = 0; v < 1; v++) {
    inptr0 = input_data[inrow];
    inptr1 = input_data[inrow + 1];
    outptr = output_data[outrow];
    thiscolsum = ((int)(*inptr0++)) * 4 + ((int)(*inptr1++));
    nextcolsum = ((int)(*inptr0++)) * 4 + ((int)(*inptr1++));
    *outptr++ = (JSAMPLE)((thiscolsum * 8 + 128) >> 8);
    *outptr++ = (JSAMPLE)((thiscolsum * 6 + nextcolsum * 2 + 127) >> 8);
    lastcolsum = thiscolsum;
    thiscolsum = nextcolsum;
    for (colctr = compptr->downsampled_width - 4; colctr > 0; colctr -= 2) {
        int temp1 = ((int)(*inptr0++)) * 4 + ((int)(*inptr1++));
        int temp2 = ((int)(*inptr0++)) * 4 + ((int)(*inptr1++));
        *outptr++ = (JSAMPLE)((thiscolsum * 5 + lastcolsum * 3 + 128) >> 8);
        *outptr++ = (JSAMPLE)((thiscolsum * 4 + temp1 * 4 + 127) >> 8);
        lastcolsum = thiscolsum;
        thiscolsum = temp1;
        *outptr++ = (JSAMPLE)((thiscolsum * 4 + temp1 * 4 + 128) >> 8);
        *outptr++ = (JSAMPLE)((thiscolsum * 3 + temp2 * 5 + 127) >> 8);
        lastcolsum = thiscolsum;
        thiscolsum = temp2;
    }
    *outptr++ = (JSAMPLE)((thiscolsum * 4 + lastcolsum * 4 + 128) >> 8);
    *outptr++ = (JSAMPLE)((thiscolsum * 8 + 127) >> 8);
    outrow++;
}
}
