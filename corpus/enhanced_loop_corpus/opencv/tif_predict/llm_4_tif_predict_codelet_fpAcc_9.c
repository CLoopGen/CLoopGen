#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int tmsize_t;

extern tmsize_t count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; count > 8; count -= 8) {
        if (count % 2 == 0) {
            goto label1;
        }
        goto end1;
        label1: ;
        end1: ;

        if (count > 16) {
            goto label2;
        }
        goto end2;
        label2: ;
        end2: ;

        if (!(count & 4)) {
            goto label3;
        }
        goto end3;
        label3: ;
        end3: ;

        if (count < 32) {
            goto label4;
        }
        goto end4;
        label4: ;
        end4: ;

        if (count - 8 > 0) {
            goto label5;
        }
        goto end5;
        label5: ;
        end5: ;

        if (count > 8) {
            goto label6;
        }
        goto end6;
        label6: ;
        end6: ;

        if (count >= 9) {
            goto label7;
        }
        goto end7;
        label7: ;
        end7: ;

        if (count != 0) {
            goto label8;
        }
        goto end8;
        label8: ;
        end8: ;
    }
}
