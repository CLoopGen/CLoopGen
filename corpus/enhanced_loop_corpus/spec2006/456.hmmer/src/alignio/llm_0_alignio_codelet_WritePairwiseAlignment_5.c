#include <stdio.h>

#include <inttypes.h>

extern char buf1[61];
extern int count1;
extern int rawcount1;
extern int apos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (apos = 0; apos < count1; apos++) {
        for (int inner = 0; inner < 1; inner++) { // Artificially increased loop depth
            if (!((buf1[apos]) == ' ' || (buf1[apos]) == '.' || (buf1[apos]) == '_' || (buf1[apos]) == '-' || (buf1[apos]) == '~'))
                rawcount1++;
        }
    }
}
