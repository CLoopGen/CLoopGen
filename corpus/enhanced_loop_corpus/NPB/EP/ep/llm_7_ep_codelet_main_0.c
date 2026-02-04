#include <stdio.h>

extern int j;
extern char size[14];



void loop(){
    int temp[14];
    for (j = 13; j >= 1; j--) {
        temp[j] = (size[j] == '.') ? ' ' : size[j]; // Remove loop-carried dependency by using local temp storage
    }
    for (j = 13; j >= 1; j--) {
        size[j] = temp[j]; // Final write with no conditional logic in second pass
    }
}
