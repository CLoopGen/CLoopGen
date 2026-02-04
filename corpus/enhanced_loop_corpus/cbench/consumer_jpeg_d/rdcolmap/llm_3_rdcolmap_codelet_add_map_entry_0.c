#include <stdio.h>

#include <inttypes.h>

typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

extern int R;
extern int G;
extern int B;
extern JSAMPROW colormap0;
extern JSAMPROW colormap1;
extern JSAMPROW colormap2;
extern int ncolors;
extern int _usr_index;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
    // Variant 2: Indirect memory access using an index mapping array (simulated via arithmetic)
    // Simulate indirect access by reversing the traversal order (ncolors-1-index), creating a reverse sequential access pattern
    for (index = 0; index < ncolors; index++) {
        int rev_index = ncolors - 1 - index;  // Reverse indexing for indirect-like access
        if (((int)(colormap0[rev_index])) == R && ((int)(colormap1[rev_index])) == G && ((int)(colormap2[rev_index])) == B)
            return;
    }
}
