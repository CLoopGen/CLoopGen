#include <stdio.h>

extern int in[2048] __attribute__((aligned(16)));
extern int res[2048] __attribute__((aligned(16)));
extern int i;
extern const int MAX;

void loop(){
for (i = 0; i < 2048 - 1; i += 2) {
    int j = in[i];
    res[i] = (j > MAX ? MAX : 0);
    res[i + 1] = j;
}

}
