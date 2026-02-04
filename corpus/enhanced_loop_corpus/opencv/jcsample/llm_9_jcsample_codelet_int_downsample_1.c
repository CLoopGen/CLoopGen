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
extern JLONG outvalue;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int row_step = 2;
int limit_row = compptr->v_samp_factor - (compptr->v_samp_factor % row_step);
for (outrow = 0; outrow < limit_row; outrow += row_step) {
    JSAMPROW outptr0 = output_data[outrow];
    JSAMPROW outptr1 = output_data[outrow + 1];
    for (outcol = 0, outcol_h = 0; outcol < output_cols; outcol++, outcol_h += h_expand) {
        JLONG outvalue0 = 0, outvalue1 = 0;
        for (v = 0; v < v_expand; v++) {
            inptr = input_data[inrow + v] + outcol_h;
            for (h = 0; h < h_expand; h++) {
                outvalue0 += (JLONG)(inptr[h]);
            }
        }
        for (v = 0; v < v_expand; v++) {
            inptr = input_data[inrow + v + v_expand] + outcol_h;
            for (h = 0; h < h_expand; h++) {
                outvalue1 += (JLONG)(inptr[h]);
            }
        }
        *outptr0++ = (JSAMPLE)((outvalue0 + numpix2) / numpix);
        *outptr1++ = (JSAMPLE)((outvalue1 + numpix2) / numpix);
    }
    inrow += 2 * v_expand;
}
if (outrow < compptr->v_samp_factor) {
    outptr = output_data[outrow];
    for (outcol = 0, outcol_h = 0; outcol < output_cols; outcol++, outcol_h += h_expand) {
        outvalue = 0;
        for (v = 0; v < v_expand; v++) {
            inptr = input_data[inrow + v] + outcol_h;
            for (h = 0; h < h_expand; h++) {
                outvalue += (JLONG)(*inptr++);
            }
        }
        *outptr++ = (JSAMPLE)((outvalue + numpix2) / numpix);
    }
}
}
