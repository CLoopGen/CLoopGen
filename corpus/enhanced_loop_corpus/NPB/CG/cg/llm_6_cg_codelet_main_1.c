#include <stdio.h>

extern  int firstrow;
extern  int lastrow;
extern  int firstcol;
extern  int colidx[2198001];
extern  int rowstr[14002];
extern int j;
extern int k;



void loop(){
    for (j = 1; j <= lastrow - firstrow + 1; j++) {
        int base_offset = -firstcol + 1;
        for (k = rowstr[j]; k < rowstr[j + 1]; k++) {
            colidx[k] += base_offset;
        }
    }
}
