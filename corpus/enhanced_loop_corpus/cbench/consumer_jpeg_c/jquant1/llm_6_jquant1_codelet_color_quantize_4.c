#include <stdio.h>

#include <inttypes.h>

typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef JSAMPROW *JSAMPARRAY;

typedef unsigned int JDIMENSION;

extern JSAMPARRAY input_buf;
extern JSAMPARRAY output_buf;
extern int num_rows;
extern JSAMPARRAY colorindex;
extern int pixcode;
extern int ci;
extern JSAMPROW ptrin;
extern JSAMPROW ptrout;
extern int row;
extern JDIMENSION col;
extern JDIMENSION width;
extern int nc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (row = 0; row < num_rows; row++) {
        ptrin = input_buf[row];
        ptrout = output_buf[row];
        for (col = width; col > 0; col--) {
            pixcode = 0;
            // Eliminate read-after-write (RAW) dependency by unrolling and reordering operations
            // Introduce temporary variables to break artificial dependencies
            int temp_sum = 0;
            JSAMPROW local_ptrin = ptrin;
            for (ci = 0; ci < nc; ci++) {
                temp_sum += ((int)(colorindex[ci][((int)(*local_ptrin))]));
                local_ptrin++; // Decouple pointer update from memory read in accumulation
            }
            ptrin = local_ptrin; // Update original pointer only after all reads
            *ptrout++ = (JSAMPLE)temp_sum;
        }
    }
}
