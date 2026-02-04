#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double c[];
extern  int len;
extern  double x;
extern int i;
extern double ans;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double prev_ans = ans;
    for (i = len - 1; i > 0; i--) {
        double new_val = c[i - 1] + x * prev_ans;
        ans = prev_ans; // Introduce WAW dependency: write before potential next write
        prev_ans = new_val;
    }
    ans = prev_ans;
}
