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
extern int outrow;
extern JDIMENSION colctr;
extern JDIMENSION output_cols;
extern JSAMPROW inptr;
extern JSAMPROW above_ptr;
extern JSAMPROW below_ptr;
extern JSAMPROW outptr;
extern INT32 membersum;
extern INT32 neighsum;
extern INT32 memberscale;
extern INT32 neighscale;
extern int colsum;
extern int lastcolsum;
extern int nextcolsum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (outrow = 0; outrow < compptr->v_samp_factor; outrow++) {
    outptr = output_data[outrow];
    inptr = input_data[outrow];
    above_ptr = input_data[outrow - 1];
    below_ptr = input_data[outrow + 1];

    colsum = ((int)(*above_ptr++)) + ((int)(*below_ptr++)) + ((int)(*inptr));
    membersum = ((int)(*inptr++));
    nextcolsum = ((int)(*above_ptr)) + ((int)(*below_ptr)) + ((int)(*inptr));
    neighsum = colsum + (colsum - membersum) + nextcolsum;
    membersum = membersum * memberscale + neighsum * neighscale;
    *outptr++ = (JSAMPLE)((membersum + 32768) >> 16);

    lastcolsum = colsum;
    colsum = nextcolsum;

    for (colctr = output_cols - 2; colctr > 0; colctr--) {
        if (membersum <= 0) {
            *outptr++ = 0;
            continue;
        }
        membersum = ((int)(*inptr++));
        above_ptr++;
        below_ptr++;
        nextcolsum = ((int)(*above_ptr)) + ((int)(*below_ptr)) + ((int)(*inptr));
        neighsum = lastcolsum + (colsum - membersum) + nextcolsum;
        membersum = membersum * memberscale + neighsum * neighscale;
        *outptr++ = (JSAMPLE)((membersum + 32768) >> 16);
        lastcolsum = colsum;
        colsum = nextcolsum;
    }

    membersum = ((int)(*inptr));
    neighsum = lastcolsum + (colsum - membersum) + colsum;
    membersum = membersum * memberscale + neighsum * neighscale;
    *outptr = (JSAMPLE)((membersum + 32768) >> 16);
}
}
