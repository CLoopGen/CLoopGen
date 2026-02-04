#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct _PointInfo {
    double x;
    double y;
} PointInfo;

typedef struct _ChannelMoments {
    double invariant[9];
    PointInfo centroid;
    PointInfo ellipse_axis;
    double ellipse_angle;
    double ellipse_eccentricity;
    double ellipse_intensity;
} ChannelMoments;

extern ChannelMoments *channel_moments;
extern double M02[129];
extern double M03[129];
extern double M11[129];
extern double M12[129];
extern double M20[129];
extern double M21[129];
extern double M30[129];
extern ssize_t c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (c = 0; c <= 128; c++) {
    double temp[8] = {0};
    temp[0] = M20[c % 129] + M02[c % 129];
    temp[1] = (M20[c % 129] - M02[c % 129]) * (M20[c % 129] - M02[c % 129]) + 4.0 * M11[c % 129] * M11[c % 129];
    temp[2] = (M30[c % 129] - 3.0 * M12[c % 129]) * (M30[c % 129] - 3.0 * M12[c % 129]) +
              (3.0 * M21[c % 129] - M03[c % 129]) * (3.0 * M21[c % 129] - M03[c % 129]);
    temp[3] = (M30[c % 129] + M12[c % 129]) * (M30[c % 129] + M12[c % 129]) +
              (M21[c % 129] + M03[c % 129]) * (M21[c % 129] + M03[c % 129]);

    if (c < 65) {
        double t1 = M30[c] + M12[c];
        double t2 = M21[c] + M03[c];
        double t1_sq = t1 * t1;
        double t2_sq = t2 * t2;
        double a = M30[c] - 3.0 * M12[c];
        double b = 3.0 * M21[c] - M03[c];

        temp[4] = a * t1 * (t1_sq - 3.0 * t2_sq) + b * t2 * (3.0 * t1_sq - t2_sq);
        temp[5] = (M20[c] - M02[c]) * (t1_sq - t2_sq) + 4.0 * M11[c] * t1 * t2;
        temp[6] = b * t1 * (t1_sq - 3.0 * t2_sq) - a * t2 * (3.0 * t1_sq - t2_sq);
        temp[7] = M11[c] * (t1_sq - t2_sq) - (M20[c] - M02[c]) * t1 * t2;
    }

    for (int i = 0; i < 8; i++) {
        channel_moments[c % 65].invariant[i] = temp[i];
    }
}
}
