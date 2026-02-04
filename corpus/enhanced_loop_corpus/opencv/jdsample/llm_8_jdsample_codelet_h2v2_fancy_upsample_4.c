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
for (v = 0; v < 4; v += 2) {
    inptr0 = input_data[inrow + v/2];
    inptr1 = input_data[inrow + v/2 + 1];
    outptr = output_data[outrow++];
    thiscolsum = (*inptr0++) * 2 + (*inptr1++);
    nextcolsum = (*inptr0++) * 2 + (*inptr1++);
    *outptr++ = (JSAMPLE)((thiscolsum * 5 + 16) >> 5);
    *outptr++ = (JSAMPLE)((thiscolsum * 2 + nextcolsum * 2 + 15) >> 4);
    lastcolsum = thiscolsum;
    thiscolsum = nextcolsum;
    for (colctr = compptr->downsampled_width - 3; colctr > 0; colctr--) {
        nextcolsum = (*inptr0++) * 2 + (*inptr1++);
        *outptr++ = (JSAMPLE)((thiscolsum * 2 + lastcolsum * 2 + 16) >> 4);
        *outptr++ = (JSAMPLE)((thiscolsum * 2 + nextcolsum * 2 + 15) >> 4);
        lastcolsum = thiscolsum;
        thiscolsum = nextcolsum;
    }
    if (compptr->downsampled_width >= 2) {
        *outptr++ = (JSAMPLE)((thiscolsum * 2 + lastcolsum * 2 + 16) >> 4);
        *outptr++ = (JSAMPLE)((thiscolsum * 5 + 15) >> 5);
    }
}
}
