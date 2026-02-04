#include <stdio.h>

extern  int firstrow;
extern  int lastrow;
extern  int firstcol;
extern  int colidx[2198001];
extern  int rowstr[14002];
extern int j;
extern int k;



void loop(){
    int prev_k = rowstr[1];
    for (j = 1; j <= lastrow - firstrow + 1; j++) {
        int start = rowstr[j];
        int end = rowstr[j + 1];
        for (k = start; k < end; k++) {
            if (k > prev_k) {
                colidx[k] = colidx[k-1] + (colidx[k] - firstcol + 1);
            } else {
                colidx[k] = colidx[k] - firstcol + 1;
            }
        }
        prev_k = rowstr[j + 1] - 1;
    }
}
