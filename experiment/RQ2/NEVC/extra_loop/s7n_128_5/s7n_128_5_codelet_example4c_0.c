#include <stdio.h>

extern int i1[128] __attribute__((aligned(16)));
extern int o[128] __attribute__((aligned(16)));
extern int i;
extern const int MAX;

void loop(){
for (i = 0; i < 128 - 1; i += 2) {
    int j = i1[i];
    o[i] = (j > MAX ? MAX : 0);
    o[i + 1] = j;
}

}
