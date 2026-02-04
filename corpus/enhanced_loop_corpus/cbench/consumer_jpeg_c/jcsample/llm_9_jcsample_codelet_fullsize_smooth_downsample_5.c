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
for (outrow = 0; outrow < compptr->v_samp_factor; outrow += 2) {
    JSAMPROW outptr1, outptr2;
    JSAMPROW inptr1, inptr2;
    JSAMPROW above_ptr1, above_ptr2;
    JSAMPROW below_ptr1, below_ptr2;
    INT32 membersum1, membersum2;
    INT32 neighsum1, neighsum2;
    int colsum1, colsum2;
    int lastcolsum1, lastcolsum2;
    int nextcolsum1, nextcolsum2;

    outptr1 = output_data[outrow];
    inptr1 = input_data[outrow];
    above_ptr1 = (outrow == 0) ? input_data[0] : input_data[outrow - 1];
    below_ptr1 = input_data[outrow + 1];

    colsum1 = ((int)(*above_ptr1++)) + ((int)(*below_ptr1++)) + ((int)(*inptr1));
    membersum1 = ((int)(*inptr1++));
    nextcolsum1 = ((int)(*above_ptr1)) + ((int)(*below_ptr1)) + ((int)(*inptr1));
    neighsum1 = colsum1 + (colsum1 - membersum1) + nextcolsum1;
    membersum1 = membersum1 * memberscale + neighsum1 * neighscale;
    *outptr1++ = (JSAMPLE)((membersum1 + 32768) >> 16);
    lastcolsum1 = colsum1;
    colsum1 = nextcolsum1;

    if (outrow + 1 < compptr->v_samp_factor) {
        outptr2 = output_data[outrow + 1];
        inptr2 = input_data[outrow + 1];
        above_ptr2 = input_data[outrow];
        below_ptr2 = input_data[outrow + 2];

        colsum2 = ((int)(*above_ptr2++)) + ((int)(*below_ptr2++)) + ((int)(*inptr2));
        membersum2 = ((int)(*inptr2++));
        nextcolsum2 = ((int)(*above_ptr2)) + ((int)(*below_ptr2)) + ((int)(*inptr2));
        neighsum2 = colsum2 + (colsum2 - membersum2) + nextcolsum2;
        membersum2 = membersum2 * memberscale + neighsum2 * neighscale;
        *outptr2++ = (JSAMPLE)((membersum2 + 32768) >> 16);
        lastcolsum2 = colsum2;
        colsum2 = nextcolsum2;

        for (colctr = output_cols - 2; colctr > 0; colctr--) {
            membersum1 = ((int)(*inptr1++));
            above_ptr1++;
            below_ptr1++;
            nextcolsum1 = ((int)(*above_ptr1)) + ((int)(*below_ptr1)) + ((int)(*inptr1));
            neighsum1 = lastcolsum1 + (colsum1 - membersum1) + nextcolsum1;
            membersum1 = membersum1 * memberscale + neighsum1 * neighscale;
            *outptr1++ = (JSAMPLE)((membersum1 + 32768) >> 16);
            lastcolsum1 = colsum1;
            colsum1 = nextcolsum1;

            membersum2 = ((int)(*inptr2++));
            above_ptr2++;
            below_ptr2++;
            nextcolsum2 = ((int)(*above_ptr2)) + ((int)(*below_ptr2)) + ((int)(*inptr2));
            neighsum2 = lastcolsum2 + (colsum2 - membersum2) + nextcolsum2;
            membersum2 = membersum2 * memberscale + neighsum2 * neighscale;
            *outptr2++ = (JSAMPLE)((membersum2 + 32768) >> 16);
            lastcolsum2 = colsum2;
            colsum2 = nextcolsum2;
        }

        membersum1 = ((int)(*inptr1));
        neighsum1 = lastcolsum1 + (colsum1 - membersum1) + colsum1;
        membersum1 = membersum1 * memberscale + neighsum1 * neighscale;
        *outptr1 = (JSAMPLE)((membersum1 + 32768) >> 16);

        membersum2 = ((int)(*inptr2));
        neighsum2 = lastcolsum2 + (colsum2 - membersum2) + colsum2;
        membersum2 = membersum2 * memberscale + neighsum2 * neighscale;
        *outptr2 = (JSAMPLE)((membersum2 + 32768) >> 16);
    } else {
        for (colctr = output_cols - 2; colctr > 0; colctr--) {
            membersum1 = ((int)(*inptr1++));
            above_ptr1++;
            below_ptr1++;
            nextcolsum1 = ((int)(*above_ptr1)) + ((int)(*below_ptr1)) + ((int)(*inptr1));
            neighsum1 = lastcolsum1 + (colsum1 - membersum1) + nextcolsum1;
            membersum1 = membersum1 * memberscale + neighsum1 * neighscale;
            *outptr1++ = (JSAMPLE)((membersum1 + 32768) >> 16);
            lastcolsum1 = colsum1;
            colsum1 = nextcolsum1;
        }
        membersum1 = ((int)(*inptr1));
        neighsum1 = lastcolsum1 + (colsum1 - membersum1) + colsum1;
        membersum1 = membersum1 * memberscale + neighsum1 * neighscale;
        *outptr1 = (JSAMPLE)((membersum1 + 32768) >> 16);
    }
}
}
