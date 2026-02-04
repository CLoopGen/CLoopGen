#include <stdio.h>

extern short *restrict sa;
extern int *restrict assign;
extern int i;

void loop(){
for (i = 0; i < 8192 - 1; i += 2) {
    assign[i] = (int)sa[i];
    assign[i + 1] = (int)sa[i + 1];
}

}
