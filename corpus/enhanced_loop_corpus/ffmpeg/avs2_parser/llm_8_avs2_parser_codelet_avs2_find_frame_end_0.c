#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int buf_size;
extern int pic_found;
extern uint32_t state;
extern int cur;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; cur < buf_size - 3; cur += 4) {
        state = (state << 8) | buf[cur];
        if ((buf[cur] >= 176 && buf[cur] <= 179) || buf[cur] == 182) {
            cur++;
            pic_found = 1;
            break;
        }
        state = (state << 8) | buf[cur + 1];
        if ((buf[cur + 1] >= 176 && buf[cur + 1] <= 179) || buf[cur + 1] == 182) {
            cur += 2;
            pic_found = 1;
            break;
        }
        state = (state << 8) | buf[cur + 2];
        if ((buf[cur + 2] >= 176 && buf[cur + 2] <= 179) || buf[cur + 2] == 182) {
            cur += 3;
            pic_found = 1;
            break;
        }
        state = (state << 8) | buf[cur + 3];
        if ((buf[cur + 3] >= 176 && buf[cur + 3] <= 179) || buf[cur + 3] == 182) {
            cur += 4;
            pic_found = 1;
            break;
        }
    }
}
