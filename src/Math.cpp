#include "Math.h"

V2::V2() : V2(0,0) {}
V2::V2(float a, float b) : x(a), y(b) {}

float V2::get_x() { return x; }
float V2::get_y() { return y; }

