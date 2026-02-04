#include <stdio.h>

typedef int boolean;

extern int rowstr[];
extern int n;
extern boolean mark[];
extern int j;



void loop(){
    if (n >= 1) {
        for (j = 1; j <= n; j += 2) {
            rowstr[j] = 0;
            mark[j] = 0;
            if (j + 1 <= n) {
                rowstr[j + 1] = 0;
                mark[j + 1] = 0;
            }
        }
    }
}
