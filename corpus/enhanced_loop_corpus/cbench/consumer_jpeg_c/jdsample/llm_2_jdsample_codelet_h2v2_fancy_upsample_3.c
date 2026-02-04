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
for (int v = 0; v < 2; v++) {
    JSAMPROW inptr0_base = input_data[inrow];
    JSAMPROW inptr1_base = (v == 0) ? input_data[inrow - 1] : input_data[inrow + 1];
    JSAMPROW outptr_base = output_data[outrow++];
    int width = compptr->downsampled_width;

    for (JDIMENSION col = 0; col < width; col += 2) {
        int val0_0 = (int)inptr0_base[col];
        int val0_1 = (col + 1 < width) ? (int)inptr0_base[col + 1] : val0_0;
        int val1_0 = (int)inptr1_base[col];
        int val1_1 = (col + 1 < width) ? (int)inptr1_base[col + 1] : val1_0;

        int thissum = val0_0 * 3 + val1_0;
        int nextsum = val0_1 * 3 + val1_1;

        if (col == 0) {
            outptr_base[0] = (JSAMPLE)((thissum * 4 + 8) >> 4);
            if (width > 1)
                outptr_base[1] = (JSAMPLE)((thissum * 3 + nextsum + 7) >> 4);
        } else {
            outptr_base[col * 2 - 2] = (JSAMPLE)((thissum * 3 + ((int)outptr_base[col * 2 - 4]) * 16 / 4 - 8 + 8) >> 4);
            if (col + 1 < width)
                outptr_base[col * 2 - 1] = (JSAMPLE)((thissum * 3 + nextsum + 7) >> 4);
        }

        if (col + 2 >= width && width > 1) {
            outptr_base[width * 2 - 2] = (JSAMPLE)((nextsum * 3 + thissum + 8) >> 4);
            outptr_base[width * 2 - 1] = (JSAMPLE)((nextsum * 4 + 7) >> 4);
        }
    }
}
}
