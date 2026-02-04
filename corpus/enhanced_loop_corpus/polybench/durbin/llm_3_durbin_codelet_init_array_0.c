#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double r[2000];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int index[2000];
for (i = 0; i < n; i++) {
    index[i] = n - 1 - i;
}
for (i = 0; i < n; i++) {
    r[index[i]] = (n + 1 - index[i]);
}
}
