#include <stdio.h>

extern  int firstrow;
extern  int lastrow;
extern  int firstcol;
extern  int colidx[2198001];
extern  int rowstr[14002];
extern int j;
extern int k;



void loop(){
    int valid_range;
    for (j = 1; j <= lastrow - firstrow + 1; j++) {
        valid_range = (rowstr[j + 1] - rowstr[j] > 0) ? 1 : 0;
        if (valid_range) {
            for (k = rowstr[j]; k < rowstr[j + 1]; k++) {
                colidx[k] = colidx[k] - firstcol + 1;
            }
        } else {
            continue;
        }
    }
}
