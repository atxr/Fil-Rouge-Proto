#ifndef MATH_H // include guard
#define MATH_H

class V2 {
public:
    V2();
    V2(float, float);

    float get_x();
    float get_y();

    float norm();
    V2 direction();

private:
    float x;
    float y;
};

#endif

