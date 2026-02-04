#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct _PointInfo {
    double x;
    double y;
} PointInfo;

PointInfo extent[4] = {
    {10.5, 20.3},
    {5.2,  15.7},
    {8.9,  12.1},
    {3.4,  18.9}
};

PointInfo min;
PointInfo max;
ssize_t i;

void init_vars() {
    min.x = 100.0;
    min.y = 100.0;
    max.x = -100.0;
    max.y = -100.0;
    i = 0;
}