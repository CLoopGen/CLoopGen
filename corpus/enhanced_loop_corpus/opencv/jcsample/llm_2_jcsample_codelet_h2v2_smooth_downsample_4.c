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
extern JDIMENSION colctr;
extern JDIMENSION output_cols;
extern JSAMPROW inptr0;
extern JSAMPROW inptr1;
extern JSAMPROW above_ptr;
extern JSAMPROW below_ptr;
extern JSAMPROW outptr;
extern JLONG membersum;
extern JLONG neighsum;
extern JLONG memberscale;
extern JLONG neighscale;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (outrow = 0; outrow < compptr->v_samp_factor; outrow++) {
    outptr = output_data[outrow];
    inptr0 = input_data[inrow];
    inptr1 = input_data[inrow + 1];
    above_ptr = input_data[inrow - 1];
    below_ptr = input_data[inrow + 2];

    // Use consecutive memory reads by prefetching values into local arrays to improve spatial locality
    JSAMPLE row0[4], row1[4], arow[4], brow[4];
    for (int i = 0; i < 4; i++) {
        row0[i] = inptr0[i];
        row1[i] = inptr1[i];
        arow[i] = above_ptr[i];
        brow[i] = below_ptr[i];
    }

    membersum = row0[0] + row0[1] + row1[0] + row1[1];
    neighsum = arow[0] + arow[1] + brow[0] + brow[1] + row0[0] + row0[2] + row1[0] + row1[2];
    neighsum += neighsum;
    neighsum += arow[0] + arow[2] + brow[0] + brow[2];
    membersum = membersum * memberscale + neighsum * neighscale;
    *outptr++ = (JSAMPLE)((membersum + 32768) >> 16);

    for (colctr = output_cols - 2; colctr > 0; colctr--) {
        membersum = row0[2] + row0[3] + row1[2] + row1[3];
        neighsum = arow[2] + arow[3] + brow[2] + brow[3] + row0[1] + row0[4 % 4] + row1[1] + row1[4 % 4];
        neighsum += neighsum;
        neighsum += arow[1] + arow[4 % 4] + brow[1] + brow[4 % 4];

        membersum = membersum * memberscale + neighsum * neighscale;
        *outptr++ = (JSAMPLE)((membersum + 32768) >> 16);

        // Slide window forward
        for (int i = 0; i < 3; i++) {
            row0[i] = row0[i+1];
            row1[i] = row1[i+1];
            arow[i] = arow[i+1];
            brow[i] = brow[i+1];
        }
        row0[3] = inptr0[3];
        row1[3] = inptr1[3];
        arow[3] = above_ptr[3];
        brow[3] = below_ptr[3];
        inptr0++; inptr1++; above_ptr++; below_ptr++;
    }

    membersum = row0[2] + row0[3] + row1[2] + row1[3];
    neighsum = arow[2] + arow[3] + brow[2] + brow[3] + row0[1] + row0[3] + row1[1] + row1[3];
    neighsum += neighsum;
    neighsum += arow[1] + arow[3] + brow[1] + brow[3];
    membersum = membersum * memberscale + neighsum * neighscale;
    *outptr = (JSAMPLE)((membersum + 32768) >> 16);
    inrow += 2;
}
}
