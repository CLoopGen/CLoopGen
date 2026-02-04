#include <stdio.h>

extern  int firstrow;
extern  int lastrow;
extern  int firstcol;
extern  int colidx[2198001];
extern  int rowstr[14002];
extern int j;
extern int k;



void loop(){
    int j;
    for (j = 1; j <= lastrow - firstrow + 1; j++) {
        int k_start = rowstr[j];
        int k_end = rowstr[j + 1];
        int k;
        for (k = k_start; k < k_end; k++) {
            colidx[k] = colidx[k] - firstcol + 1;
        }
    }
}
