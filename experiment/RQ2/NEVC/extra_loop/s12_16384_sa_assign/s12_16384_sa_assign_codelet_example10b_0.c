#include <stdio.h>

extern short *restrict sa;
extern int *restrict assign;
extern int i;

void loop(){
for (i = 0; i < 16384; i++) {
    assign[i] = (int)sa[i];
}

}
