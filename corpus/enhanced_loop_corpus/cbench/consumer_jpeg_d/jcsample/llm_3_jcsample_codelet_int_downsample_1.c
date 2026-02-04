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
JDIMENSION total_outcols = output_cols;
JDIMENSION stride = h_expand;
for (outrow = 0; outrow < compptr->v_samp_factor; outrow++) {
    outptr = output_data[outrow];
    JDIMENSION linear_index = 0;
    for (outcol = 0; outcol < total_outcols; outcol++) {
        outvalue = 0;
        JDIMENSION base_incol = outcol * stride;
        for (v = 0; v < v_expand; v++) {
            inptr = input_data[inrow + v];
            JSAMPROW expanded_row = inptr + base_incol;
            for (h = 0; h < h_expand; h += 2) {
                if (h + 1 < h_expand) {
                    outvalue += (INT32)((int)expanded_row[h]) + (INT32)((int)expanded_row[h+1]);
                } else {
                    outvalue += (INT32)((int)expanded_row[h]);
                }
            }
        }
        outptr[linear_index++] = (JSAMPLE)((outvalue + numpix2) / numpix);
    }
    inrow += v_expand;
}
}
