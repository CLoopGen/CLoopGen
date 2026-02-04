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
    JSAMPROW local_outptr;
    JSAMPROW local_inptr;
    int local_bias;
    for (outrow = 0; outrow < compptr->v_samp_factor; outrow++) {
        local_outptr = output_data[outrow];
        local_inptr = input_data[outrow];
        local_bias = 0;
        for (outcol = 0; outcol < output_cols; outcol++) {
            *(local_outptr + outcol) = (JSAMPLE)((((int)(*(local_inptr + (outcol << 1))) + 
                                   ((int)(*(local_inptr + (outcol << 1) + 1)))) + local_bias) >> 1);
            local_bias ^= 1;
        }
    }
}
