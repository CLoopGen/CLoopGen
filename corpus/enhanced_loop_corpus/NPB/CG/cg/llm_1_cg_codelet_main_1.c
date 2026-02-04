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
    int total_rows = lastrow - firstrow + 1;
    int temp_rowstr[2];
    for (j = 1; j <= total_rows; j++) {
        temp_rowstr[0] = rowstr[j];
        temp_rowstr[1] = rowstr[j + 1];
        int k;
        for (k = temp_rowstr[0]; k < temp_rowstr[1]; k++) {
            colidx[k] = colidx[k] - firstcol + 1;
        }
    }
}
