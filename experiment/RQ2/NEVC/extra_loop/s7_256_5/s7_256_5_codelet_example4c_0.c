#include <stdio.h>

extern int i1[256] __attribute__((aligned(16)));
extern int o[256] __attribute__((aligned(16)));
extern int i;
extern const int MAX;

void loop(){
for (i = 0; i < 256; i++) {
    int j = i1[i];
    o[i] = (j > MAX ? MAX : 0);
}

}
