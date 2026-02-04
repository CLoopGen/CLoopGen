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
    ans = c[0];
    for (i = 2; i < len; i += 2) {
        if (i + 1 < len) {
            ans = c[i - 1] + x * (c[i] + x * ans);
        } else {
            ans = c[i - 1] + x * ans;
        }
    }
    if (len % 2 == 1 && len >= 3) {
        ans = c[len - 2] + x * ans;
    }
}
