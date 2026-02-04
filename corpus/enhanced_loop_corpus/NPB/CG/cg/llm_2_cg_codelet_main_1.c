#include <stdio.h>

extern  int firstrow;
extern  int lastrow;
extern  int firstcol;
extern  int colidx[2198001];
extern  int rowstr[14002];
extern int j;
extern int k;



void loop(){
    // Variant 1: Consecutive Memory Access via Loop Interchange and Blocking
    // Instead of processing each row's sparse column indices immediately,
    // we restructure to access colidx in a more consecutive pattern by buffering indices.
    int buffer[1024];
    int buf_count = 0;
    
    for (j = 1; j <= lastrow - firstrow + 1; j++) {
        for (k = rowstr[j]; k < rowstr[j + 1]; k++) {
            buffer[buf_count++] = k;
            if (buf_count == 1024) {
                for (int b = 0; b < buf_count; b++) {
                    colidx[buffer[b]] = colidx[buffer[b]] - firstcol + 1;
                }
                buf_count = 0;
            }
        }
    }
    // Flush remaining elements in buffer
    for (int b = 0; b < buf_count; b++) {
        colidx[buffer[b]] = colidx[buffer[b]] - firstcol + 1;
    }
}
