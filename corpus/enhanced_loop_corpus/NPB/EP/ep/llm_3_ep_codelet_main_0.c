#include <stdio.h>

extern int j;
extern char size[14];



void loop(){
    // Variant 2: Strided memory access with stride of 3, covering same range
    int start;
    for (start = 13; start >= 1; start--) {
        for (j = start; j >= 1; j -= 3) {
            if (size[j] == '.')
                size[j] = ' ';
        }
    }
}
