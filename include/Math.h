#ifndef MATH_H // include guard
#define MATH_H

class V2 {
public:
    V2();
    V2(float, float);
    float norm();
    V2 direction();
    float x;
    float y;
};

#endif

