#include <stdio.h>

extern int in[256] __attribute__((aligned(16)));
extern int res[256] __attribute__((aligned(16)));
extern int i;
extern const int MAX;

void loop(){
for (i = 0; i < 256; i++) {
    int j = in[i];
    res[i] = (j > MAX ? MAX : 0);
}

}
