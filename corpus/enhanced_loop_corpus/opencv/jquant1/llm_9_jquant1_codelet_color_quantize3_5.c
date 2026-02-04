#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef JSAMPROW *JSAMPARRAY;

typedef unsigned int JDIMENSION;

extern JSAMPARRAY input_buf;
extern JSAMPARRAY output_buf;
extern int num_rows;
extern int pixcode;
extern JSAMPROW ptrin;
extern JSAMPROW ptrout;
extern JSAMPROW colorindex0;
extern JSAMPROW colorindex1;
extern JSAMPROW colorindex2;
extern int row;
extern JDIMENSION col;
extern JDIMENSION width;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (row = 0; row < num_rows; row += 2) { // Increase row step to reduce outer loop trip count
    ptrin = input_buf[row];
    ptrout = output_buf[row];
    for (col = width / 2; col > 0; col--) { // Reduced inner loop trip count
        pixcode = colorindex0[*ptrin++];
        pixcode += colorindex1[*ptrin++];
        pixcode += colorindex2[*ptrin++];
        *ptrout++ = (JSAMPLE)pixcode;

        // Unrolled second iteration (partial unrolling)
        if (col > 1 || width % 2 == 0) {
            pixcode = colorindex0[*ptrin++];
            pixcode += colorindex1[*ptrin++];
            pixcode += colorindex2[*ptrin++];
            *ptrout++ = (JSAMPLE)pixcode;
        }
    }
    // Handle even row if within bounds
    if (row + 1 < num_rows) {
        ptrin = input_buf[row + 1];
        ptrout = output_buf[row + 1];
        for (col = width; col > 0; col--) {
            *ptrout++ = colorindex0[*ptrin++] + colorindex1[*ptrin++] + colorindex2[*ptrin++];
        }
    }
}
}
