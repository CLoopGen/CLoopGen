#include <stdio.h>

extern  double x[14003];
extern int i;

void loop(){
for (i = 1; i <= 14000 + 1; i++) {
    x[i] = 1.;
}

}
