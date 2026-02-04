#include <stdio.h>

#include <inttypes.h>

typedef unsigned int JDIMENSION;

typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef JSAMPROW *JSAMPARRAY;

extern JDIMENSION samplesperrow;
extern JSAMPARRAY result;
extern JSAMPROW workspace;
extern JDIMENSION rowsperchunk;
extern JDIMENSION currow;
extern JDIMENSION i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access pattern - write every second row first, then fill in the gaps (stride of 2)
    JDIMENSION total_rows = rowsperchunk;
    JSAMPROW temp_workspace = workspace;
    JDIMENSION start_row = currow;

    // First pass: even indices (0, 2, 4, ...)
    for (i = (total_rows + 1) / 2; i > 0; i--) {
        result[start_row + (i - 1) * 2] = temp_workspace;
        temp_workspace += samplesperrow * 2;
    }

    // Reset and second pass: odd indices (1, 3, 5, ...)
    temp_workspace = workspace + samplesperrow;
    for (i = total_rows / 2; i > 0; i--) {
        result[start_row + 1 + (i - 1) * 2] = temp_workspace;
        temp_workspace += samplesperrow * 2;
    }

    // Update global state
    currow += total_rows;
    workspace += samplesperrow * total_rows;
}
