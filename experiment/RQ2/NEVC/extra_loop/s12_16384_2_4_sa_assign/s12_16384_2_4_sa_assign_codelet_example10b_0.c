#include <stdio.h>

extern short *restrict sa;
extern int *restrict assign;
extern int i;

void loop(){
for (i = 0; i < 16384 - 3; i += 4) {
    assign[i] = (int)sa[i];
    assign[i + 1] = (int)sa[i + 1];
    assign[i + 2] = (int)sa[i + 2];
    assign[i + 3] = (int)sa[i + 3];
}

}
