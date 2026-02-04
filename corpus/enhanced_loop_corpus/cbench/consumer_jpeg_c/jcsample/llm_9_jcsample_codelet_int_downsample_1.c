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
for (outrow = 0; outrow < compptr->v_samp_factor; outrow += 2) {
    JSAMPROW outptr0 = output_data[outrow];
    JSAMPROW outptr1 = (outrow + 1 < compptr->v_samp_factor) ? output_data[outrow + 1] : NULL;
    for (outcol = 0, outcol_h = 0; outcol < output_cols; outcol++, outcol_h += h_expand) {
        INT32 outvalue0 = 0, outvalue1 = 0;
        int inrow1_0 = inrow, inrow1_1 = inrow + v_expand;
        for (v = 0; v < v_expand; v++) {
            JSAMPROW inptr0 = input_data[inrow1_0 + v] + outcol_h;
            JSAMPROW inptr1 = (inrow1_1 + v < numpix) ? input_data[inrow1_1 + v] + outcol_h : inptr0;
            for (h = 0; h < h_expand; h++) {
                outvalue0 += (INT32)((int)inptr0[h]);
                if (outptr1 != NULL)
                    outvalue1 += (INT32)((int)inptr1[h]);
            }
        }
        *outptr0++ = (JSAMPLE)((outvalue0 + numpix2) / numpix);
        if (outptr1 != NULL)
            *outptr1++ = (JSAMPLE)((outvalue1 + numpix2) / numpix);
    }
    inrow += 2 * v_expand;
}
}
