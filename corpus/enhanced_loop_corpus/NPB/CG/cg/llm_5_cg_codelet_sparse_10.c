#include <stdio.h>

typedef int boolean;

extern int rowstr[];
extern int n;
extern boolean mark[];
extern int j;



void loop(){
    for (j = 1; j <= n; j++) {
        rowstr[j] = 0;
        if (mark != NULL) {
            mark[j] = 0;
        }
    }
}
