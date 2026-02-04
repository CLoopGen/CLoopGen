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
extern JDIMENSION colctr;
extern JDIMENSION output_cols;
extern JSAMPROW inptr0;
extern JSAMPROW inptr1;
extern JSAMPROW above_ptr;
extern JSAMPROW below_ptr;
extern JSAMPROW outptr;
extern INT32 membersum;
extern INT32 neighsum;
extern INT32 memberscale;
extern INT32 neighscale;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
INT32 local_membersum = 0, local_neighsum = 0;
for (outrow = 0; outrow < compptr->v_samp_factor; outrow++) {
    outptr = output_data[outrow];
    inptr0 = input_data[inrow];
    inptr1 = input_data[inrow + 1];
    above_ptr = input_data[inrow - 1];
    below_ptr = input_data[inrow + 2];

    // Eliminate loop-carried dependency on 'membersum' and 'neighsum' by using local accumulators
    // Introduce WAR-like pattern by deferring global write until end of row

    local_membersum = ((int)(*inptr0)) + ((int)(inptr0[1])) + ((int)(*inptr1)) + ((int)(inptr1[1]));
    local_neighsum = ((int)(*above_ptr)) + ((int)(above_ptr[1])) + ((int)(*below_ptr)) + ((int)(below_ptr[1])) +
                     ((int)(*inptr0)) + ((int)(inptr0[2])) + ((int)(*inptr1)) + ((int)(inptr1[2]));
    local_neighsum += local_neighsum;
    local_neighsum += ((int)(*above_ptr)) + ((int)(above_ptr[2])) + ((int)(*below_ptr)) + ((int)(below_ptr[2]));

    membersum = local_membersum * memberscale + local_neighsum * neighscale;
    *outptr++ = (JSAMPLE)((membersum + 32768) >> 16);

    inptr0 += 2;
    inptr1 += 2;
    above_ptr += 2;
    below_ptr += 2;

    for (colctr = output_cols - 2; colctr > 0; colctr--) {
        local_membersum = ((int)(*inptr0)) + ((int)(inptr0[1])) + ((int)(*inptr1)) + ((int)(inptr1[1]));
        local_neighsum = ((int)(*above_ptr)) + ((int)(above_ptr[1])) + ((int)(*below_ptr)) + ((int)(below_ptr[1])) +
                         ((int)(inptr0[-1])) + ((int)(inptr0[2])) + ((int)(inptr1[-1])) + ((int)(inptr1[2]));
        local_neighsum += local_neighsum;
        local_neighsum += ((int)(above_ptr[-1])) + ((int)(above_ptr[2])) + ((int)(below_ptr[-1])) + ((int)(below_ptr[2]));

        membersum = local_membersum * memberscale + local_neighsum * neighscale;
        *outptr++ = (JSAMPLE)((membersum + 32768) >> 16);

        inptr0 += 2;
        inptr1 += 2;
        above_ptr += 2;
        below_ptr += 2;
    }

    local_membersum = ((int)(*inptr0)) + ((int)(inptr0[1])) + ((int)(*inptr1)) + ((int)(inptr1[1]));
    local_neighsum = ((int)(*above_ptr)) + ((int)(above_ptr[1])) + ((int)(*below_ptr)) + ((int)(below_ptr[1])) +
                     ((int)(inptr0[-1])) + ((int)(inptr0[1])) + ((int)(inptr1[-1])) + ((int)(inptr1[1]));
    local_neighsum += local_neighsum;
    local_neighsum += ((int)(above_ptr[-1])) + ((int)(above_ptr[1])) + ((int)(below_ptr[-1])) + ((int)(below_ptr[1]));

    membersum = local_membersum * memberscale + local_neighsum * neighscale;
    *outptr = (JSAMPLE)((membersum + 32768) >> 16);

    inrow += 2;
}
}
