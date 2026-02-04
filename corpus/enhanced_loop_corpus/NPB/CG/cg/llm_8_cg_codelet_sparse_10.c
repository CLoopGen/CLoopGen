#include <stdio.h>

typedef int boolean;

extern int rowstr[];
extern int n;
extern boolean mark[];
extern int j;



void loop(){
    for (j = 1; j <= n; j += 2) {
        if (j + 1 <= n) {
            rowstr[j] = 0;
            mark[j] = 0;
            rowstr[j + 1] = 0;
            mark[j + 1] = 0;
        } else {
            rowstr[j] = 0;
            mark[j] = 0;
        }
    }
}
