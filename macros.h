#ifndef MACROS_H
#define MACROS_H

#define HDIM 225
#define VDIM 30
#define DIST 25
#define SCALE 50
#define ZP 5
#define YTRANS 0
#define RMOVE 80
#define DMOVE -95

#define X ((1/y) * sin(t))
#define Y (y)
#define Z ((1/y) * cos(t))
#define XR X
#define YR ( (Y * cos(p)) - (Z * sin(p)) )
#define ZR ( (Y * sin(p)) + (Z * cos(p)) + DIST)

#define LSUB1 (sin(p) * cos(t) * y * fabs(y))
#define LSUB2 (sin(t) * y * fabs(y))
#define LSUB3 (cos(p) * sign(y))
#define LIGHT ( ( sqrt(2) * fabs(LSUB1 + LSUB2 - LSUB3) ) / ( 2 * sqrt(y * y * y * y + 1) ) )

#endif