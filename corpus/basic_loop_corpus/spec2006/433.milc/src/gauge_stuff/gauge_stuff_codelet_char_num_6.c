#include <stdio.h>

#include <inttypes.h>

extern int *chr;
extern int length;
extern int j;
extern int bdig[6];
extern int tenl;
extern int newv;
extern int old;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (j = length - 1; j >= 1; j--) {
    newv = old - tenl * bdig[j];
    newv = newv * 10 + bdig[j];
    if (newv < *chr)
        *chr = newv;
    old = newv;
}

}
