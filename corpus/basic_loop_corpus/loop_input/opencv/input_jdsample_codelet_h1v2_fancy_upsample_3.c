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

// Forward declarations of extern variables
extern jpeg_component_info *compptr;
extern JSAMPARRAY input_data;
extern JSAMPARRAY output_data;
extern JSAMPROW inptr0;
extern JSAMPROW inptr1;
extern JSAMPROW outptr;
extern JLONG thiscolsum;
extern JLONG bias;
extern JDIMENSION colctr;
extern int inrow;
extern int outrow;
extern int v;

// Static storage for data
static jpeg_component_info s_compptr;
static JSAMPROW s_input_rows[3];
static JSAMPROW s_output_rows[2];
static JSAMPLE *s_input_data_storage;
static JSAMPLE *s_output_data_storage;

// Define non-const pointers at file scope without initializers
jpeg_component_info *compptr;
JSAMPARRAY input_data;
JSAMPARRAY output_data;
JSAMPROW inptr0 = NULL;
JSAMPROW inptr1 = NULL;
JSAMPROW outptr = NULL;
JLONG thiscolsum = 0;
JLONG bias = 0;
JDIMENSION colctr = 0;
int inrow = 1;
int outrow = 0;
int v = 0;

void init_vars() {
    const size_t width = 16384;  // ~16KB per row, total input ~500KB, allows room for boundaries
    const size_t height = 3;
    
    // Allocate storage
    s_input_data_storage = (JSAMPLE*)calloc(width * height, sizeof(JSAMPLE));
    s_output_data_storage = (JSAMPLE*)calloc(width * 2, sizeof(JSAMPLE));
    
    if (!s_input_data_storage || !s_output_data_storage) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    
    // Set up row pointers
    for (int i = 0; i < 3; i++) {
        s_input_rows[i] = s_input_data_storage + i * width;
    }
    for (int i = 0; i < 2; i++) {
        s_output_rows[i] = s_output_data_storage + i * width;
    }
    
    // Initialize compptr
    compptr = &s_compptr;
    compptr->downsampled_width = width;
    compptr->downsampled_height = height;
    
    // Initialize input/output arrays
    input_data = s_input_rows;
    output_data = s_output_rows;
    
    // Ensure inrow is within valid range and has neighbor rows
    inrow = 1;  // middle row so we can access inrow-1 and inrow+1
    outrow = 0;
}