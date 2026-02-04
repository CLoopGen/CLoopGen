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
    inptr0 = input_data[inrow];
    inptr1 = (v == 0) ? input_data[inrow - 1] : input_data[inrow + 1];
    outptr = output_data[outrow++];

    JDIMENSION width = compptr->downsampled_width;
    int* temp_buffer = (int*)__builtin_alloca(width * sizeof(int));

    for (JDIMENSION col = 0; col < width; col++) {
        temp_buffer[col] = ((int)inptr0[col]) * 3 + ((int)inptr1[col]);
    }

    *outptr++ = (JSAMPLE)((temp_buffer[0] * 4 + 8) >> 4);
    if (width > 1) {
        *outptr++ = (JSAMPLE)((temp_buffer[0] * 3 + temp_buffer[1] + 7) >> 4);
    }

    for (JDIMENSION col = 1; col < width - 1; col++) {
        *outptr++ = (JSAMPLE)((temp_buffer[col] * 3 + temp_buffer[col - 1] + 8) >> 4);
        *outptr++ = (JSAMPLE)((temp_buffer[col] * 3 + temp_buffer[col + 1] + 7) >> 4);
    }

    if (width > 1) {
        *outptr++ = (JSAMPLE)((temp_buffer[width - 1] * 3 + temp_buffer[width - 2] + 8) >> 4);
        *outptr++ = (JSAMPLE)((temp_buffer[width - 1] * 4 + 7) >> 4);
    }
}
}
