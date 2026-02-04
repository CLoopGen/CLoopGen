#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *a;
extern int i;
extern int j;
extern int tmp;
extern int v;
extern int numswaps;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (;; ++i) {
        if (a[i + 1] >= v) {
            for (;; --j) {
                if (a[j - 1] <= v) {
                    if (i >= j)
                        break;
                    tmp = a[i];
                    a[i] = a[j];
                    a[j] = tmp;
                    numswaps++;
                    goto outer_continue;
                }
            }
            break;
        }
        continue;
    outer_continue:
        continue;
    }
}
