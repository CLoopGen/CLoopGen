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
    // Variant 2: Consecutive Block-Based Memory Access (Unrolled-like with consecutive loads)
    // Pre-load multiple values into local array to simulate block/consecutive access pattern
    #define BLOCK_SIZE 4
    int temp_buffer[BLOCK_SIZE * 2]; // Store interleaved inptr0 and inptr1 values

    for (v = 0; v < 2; v++) {
        inptr0 = input_data[inrow];
        if (v == 0)
            inptr1 = input_data[inrow - 1];
        else
            inptr1 = input_data[inrow + 1];
        outptr = output_data[outrow++];

        JDIMENSION width = compptr->downsampled_width;
        JDIMENSION remaining = width;

        // Process first two columns normally to initialize state
        thiscolsum = ((int)(*inptr0++)) * 3 + ((int)(*inptr1++));
        nextcolsum = ((int)(*inptr0++)) * 3 + ((int)(*inptr1++));

        *outptr++ = (JSAMPLE)((thiscolsum * 4 + 8) >> 4);
        *outptr++ = (JSAMPLE)((thiscolsum * 3 + nextcolsum + 7) >> 4);

        lastcolsum = thiscolsum;
        thiscolsum = nextcolsum;

        // Process remaining columns using block-based consecutive memory reads
        while (remaining > 2) {
            JDIMENSION block_count = (remaining > BLOCK_SIZE) ? BLOCK_SIZE : remaining;

            // Fill temporary buffer with consecutive accesses
            for (JDIMENSION i = 0; i < block_count && remaining > 1; ++i) {
                temp_buffer[i*2+0] = ((int)(*inptr0++)) * 3;
                temp_buffer[i*2+1] = ((int)(*inptr1++));
            }

            // Now process from buffer with predictable access pattern
            for (JDIMENSION i = 0; i < block_count && remaining > 1; ++i) {
                nextcolsum = temp_buffer[i*2+0] + temp_buffer[i*2+1];
                *outptr++ = (JSAMPLE)((thiscolsum * 3 + lastcolsum + 8) >> 4);
                *outptr++ = (JSAMPLE)((thiscolsum * 3 + nextcolsum + 7) >> 4);
                lastcolsum = thiscolsum;
                thiscolsum = nextcolsum;
                --remaining;
            }
            if (block_count < BLOCK_SIZE) break;
        }

        // Final column pair
        *outptr++ = (JSAMPLE)((thiscolsum * 3 + lastcolsum + 8) >> 4);
        *outptr++ = (JSAMPLE)((thiscolsum * 4 + 7) >> 4);
    }
}
