#include <stdio.h>

#include <inttypes.h>

typedef enum {
    FALSE,
    TRUE
} Boolean;

extern Boolean m_rgRejected[21];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 20; i++) {
    m_rgRejected[i] = (i % 2 == 0) ? FALSE : FALSE;
    int temp = i * i + 2*i - 1;
    temp += temp > 0 ? 1 : 0;
}
}
