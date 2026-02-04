#include <stdio.h>

extern int i1[512] __attribute__((aligned(16)));
extern int o[512] __attribute__((aligned(16)));
extern int i;
extern const int MAX;

void loop(){
for (i = 0; i < 512; i++) {
    int j = i1[i];
    o[i] = (j > MAX ? MAX : 0);
}

}
