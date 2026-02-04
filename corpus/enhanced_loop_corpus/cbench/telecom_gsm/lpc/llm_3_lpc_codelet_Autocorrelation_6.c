#include <stdio.h>

#include <inttypes.h>

typedef long longword;

typedef short word;

extern longword *L_ACF;
extern int i;
extern word *sp;
extern word sl;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const int indices[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    for (i = 8; i <= 159; i++) {
        sl = *(++sp);
        longword temp_sl = (longword)sl;
        word *access_ptr = sp - 8;
        for (int j = 0; j < 9; j++) {
            int idx = indices[j]; 
            L_ACF[idx] += temp_sl * access_ptr[idx];
        }
    }
}
