#include <stdio.h>

extern  int firstrow;
extern  int lastrow;
extern  int firstcol;
extern  int colidx[2198001];
extern  int rowstr[14002];
extern int j;
extern int k;



void loop(){
    for (j = 1; j <= (lastrow - firstrow + 1) >> 1; j++) {
        int k_start = rowstr[2*j - 1];
        int k_end   = rowstr[2*j + 1];
        for (k = k_start; k < k_end; k++) {
            colidx[k] = colidx[k] - firstcol + 1;
        }
    }
}
