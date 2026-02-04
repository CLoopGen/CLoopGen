#include <stdio.h>

extern int i1[16384] __attribute__((aligned(16)));
extern int o[16384] __attribute__((aligned(16)));
extern int i;
extern const int MAX;

void loop(){
for (i = 0; i < 16384; i++) {
    int j = i1[i];
    o[i] = (j > MAX ? MAX : 0);
}

}
