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
for (outrow = 0; outrow < compptr->v_samp_factor; outrow++) {
    outptr = output_data[outrow];
    inptr0 = input_data[inrow];
    inptr1 = input_data[inrow + 1];
    above_ptr = input_data[inrow - 1];
    below_ptr = input_data[inrow + 2];

    // Use consecutive memory reads by prefetching values into local arrays
    JSAMPLE row0[4], row1[4], abv[4], blw[4];
    for (int i = 0; i < 4; i++) {
        row0[i] = inptr0[i];
        row1[i] = inptr1[i];
        abv[i] = above_ptr[i];
        blw[i] = below_ptr[i];
    }

    membersum = ((int)(row0[0])) + ((int)(row0[1])) + ((int)(row1[0])) + ((int)(row1[1]));
    neighsum = ((int)(abv[0])) + ((int)(abv[1])) + ((int)(blw[0])) + ((int)(blw[1])) +
               ((int)(row0[0])) + ((int)(row0[2])) + ((int)(row1[0])) + ((int)(row1[2]));
    neighsum += neighsum;
    neighsum += ((int)(abv[0])) + ((int)(abv[2])) + ((int)(blw[0])) + ((int)(blw[2]));
    membersum = membersum * memberscale + neighsum * neighscale;
    *outptr++ = (JSAMPLE)((membersum + 32768) >> 16);

    for (colctr = output_cols - 2; colctr > 0; colctr--) {
        membersum = ((int)(row0[2])) + ((int)(row0[3])) + ((int)(row1[2])) + ((int)(row1[3]));
        neighsum = ((int)(abv[2])) + ((int)(abv[3])) + ((int)(blw[2])) + ((int)(blw[3])) +
                   ((int)(row0[1])) + ((int)(row0[4 % 4])) + ((int)(row1[1])) + ((int)(row1[4 % 4]));
        neighsum += neighsum;
        neighsum += ((int)(abv[1])) + ((int)(abv[4 % 4])) + ((int)(blw[1])) + ((int)(blw[4 % 4]));
        membersum = membersum * memberscale + neighsum * neighscale;
        *outptr++ = (JSAMPLE)((membersum + 32768) >> 16);

        // Slide window: shift two elements forward in a circular buffer fashion
        row0[0] = row0[2]; row0[1] = row0[3]; 
        row1[0] = row1[2]; row1[1] = row1[3];
        abv[0] = abv[2]; abv[1] = abv[3];
        blw[0] = blw[2]; blw[1] = blw[3];

        row0[2] = inptr0[4]; row0[3] = inptr0[5];
        row1[2] = inptr1[4]; row1[3] = inptr1[5];
        abv[2] = above_ptr[4]; abv[3] = above_ptr[5];
        blw[2] = below_ptr[4]; blw[3] = below_ptr[5];

        inptr0 += 2; inptr1 += 2; above_ptr += 2; below_ptr += 2;
    }

    // Final column using last available data
    membersum = ((int)(row0[2])) + ((int)(row0[3])) + ((int)(row1[2])) + ((int)(row1[3]));
    neighsum = ((int)(abv[2])) + ((int)(abv[3])) + ((int)(blw[2])) + ((int)(blw[3])) +
               ((int)(row0[1])) + ((int)(row0[3])) + ((int)(row1[1])) + ((int)(row1[3]));
    neighsum += neighsum;
    neighsum += ((int)(abv[1])) + ((int)(abv[3])) + ((int)(blw[1])) + ((int)(blw[3]));
    membersum = membersum * memberscale + neighsum * neighscale;
    *outptr = (JSAMPLE)((membersum + 32768) >> 16);
    inrow += 2;
}
}
