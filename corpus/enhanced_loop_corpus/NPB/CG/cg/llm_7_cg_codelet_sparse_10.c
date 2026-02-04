#include <stdio.h>

typedef int boolean;

extern int rowstr[];
extern int n;
extern boolean mark[];
extern int j;



void loop(){
    int temp_rowstr, temp_mark;
    for (j = 1; j <= n; j++) {
        temp_rowstr = 0;        // Local computation with no direct loop-carried dependence
        temp_mark = 0;
        rowstr[j] = temp_rowstr; // WAW hazard eliminated by using temporaries; no loop-carried dep
        mark[j] = temp_mark;
    }
}
