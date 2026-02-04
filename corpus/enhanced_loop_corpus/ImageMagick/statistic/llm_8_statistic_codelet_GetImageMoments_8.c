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
for (c = 0; c <= 64; c += 2) {
    double m20 = M20[c], m02 = M02[c], m11 = M11[c];
    double m30 = M30[c], m12 = M12[c], m21 = M21[c], m03 = M03[c];
    
    double t1 = m30 + m12;
    double t2 = m21 + m03;
    double t1_sq = t1 * t1;
    double t2_sq = t2 * t2;
    double diff_m30_m12 = m30 - 3.0 * m12;
    double diff_m21_m03 = 3.0 * m21 - m03;

    channel_moments[c].invariant[0] = m20 + m02;
    channel_moments[c].invariant[1] = (m20 - m02) * (m20 - m02) + 4.0 * m11 * m11;
    channel_moments[c].invariant[2] = diff_m30_m12 * diff_m30_m12 + diff_m21_m03 * diff_m21_m03;
    channel_moments[c].invariant[3] = t1_sq + t2_sq;
    
    double term1 = diff_m30_m12 * t1 * (t1_sq - 3.0 * t2_sq);
    double term2 = diff_m21_m03 * t2 * (3.0 * t1_sq - t2_sq);
    channel_moments[c].invariant[4] = term1 + term2;
    
    channel_moments[c].invariant[5] = (m20 - m02) * (t1_sq - t2_sq) + 4.0 * m11 * t1 * t2;
}
}
