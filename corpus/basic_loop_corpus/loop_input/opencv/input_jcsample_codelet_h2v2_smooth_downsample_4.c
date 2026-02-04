#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned int JDIMENSION;
typedef int boolean;
typedef unsigned short UINT16;
typedef unsigned char JSAMPLE;
typedef long JLONG;

typedef struct {
    UINT16 quantval[64];
    boolean sent_table;
} JQUANT_TBL;

typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;

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

static jpeg_component_info s_compptr;
static JQUANT_TBL s_quant_table;
static JSAMPARRAY s_input_data;
static JSAMPARRAY s_output_data;
static JSAMPLE* s_input_buffer;
static JSAMPLE* s_output_buffer;

void init_vars() {
    // Set sampling factor and dimensions to control loop iterations
    s_compptr.v_samp_factor = 8;
    s_compptr.h_samp_factor = 1;
    s_compptr.DCT_scaled_size = 8;
    s_compptr.downsampled_width = 256;
    s_compptr.width_in_blocks = 32;
    s_compptr.height_in_blocks = 32;
    
    output_cols = 128;
    memberscale = 4096;
    neighscale = 2048;

    // Allocate large enough image data to achieve ~0.01s runtime
    // Total pixels: rows * cols, aim for several megapixels
    int total_rows = 32 * 2 + 4;  // Add boundary rows for -1, +2 access
    int total_cols = output_cols * 2 + 4;  // Each step uses 2 columns, add padding

    s_input_buffer = (JSAMPLE*)calloc(total_rows * total_cols, sizeof(JSAMPLE));
    s_output_buffer = (JSAMPLE*)calloc(s_compptr.v_samp_factor * output_cols, sizeof(JSAMPLE));

    // Initialize input_data array of row pointers
    s_input_data = (JSAMPARRAY)calloc(total_rows, sizeof(JSAMPROW));
    for (int i = 0; i < total_rows; i++) {
        s_input_data[i] = &s_input_buffer[i * total_cols];
    }

    // Initialize output_data array of row pointers
    s_output_data = (JSAMPARRAY)calloc(s_compptr.v_samp_factor, sizeof(JSAMPROW));
    for (int i = 0; i < s_compptr.v_samp_factor; i++) {
        s_output_data[i] = &s_output_buffer[i * output_cols];
    }

    // Fill input with non-zero values for realistic computation
    for (int i = 0; i < total_rows; i++) {
        for (int j = 0; j < total_cols; j++) {
            s_input_buffer[i * total_cols + j] = (JSAMPLE)((i * 7 + j * 13 + 17) % 255);
        }
    }

    // Link global pointers
    compptr = &s_compptr;
    input_data = s_input_data;
    output_data = s_output_data;
    inrow = 1;  // Start at row 1 to allow inrow-1 access
    s_compptr.quant_table = &s_quant_table;
    s_compptr.last_col_width = 1;
    s_compptr.last_row_height = 1;
}

// Define extern variables
jpeg_component_info *compptr = NULL;
JSAMPARRAY input_data = NULL;
JSAMPARRAY output_data = NULL;
int inrow = 0;
int outrow = 0;
JDIMENSION colctr = 0;
JDIMENSION output_cols = 0;
JSAMPROW inptr0 = NULL;
JSAMPROW inptr1 = NULL;
JSAMPROW above_ptr = NULL;
JSAMPROW below_ptr = NULL;
JSAMPROW outptr = NULL;
JLONG membersum = 0;
JLONG neighsum = 0;
JLONG memberscale = 0;
JLONG neighscale = 0;