//
// Created by ASUS on 2024/4/8.
//

#ifndef PLANEDESIGNBYMATH_VECTOR3D_H
#define PLANEDESIGNBYMATH_VECTOR3D_H


#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <cmath>

class Vector3D {
public:
    // 构造函数
    Vector3D();
    Vector3D(double x, double y, double z);

    // 向量的基本操作
    double getX() const;
    double getY() const;
    double getZ() const;
    double magnitude() const;
    Vector3D normalize() const;
    Vector3D negate() const;

    // 向量的算术运算
    Vector3D operator+(const Vector3D& other) const;
    Vector3D operator-(const Vector3D& other) const;
    Vector3D operator*(double scalar) const;
    double dot(const Vector3D& other) const;
    Vector3D cross(const Vector3D& other) const;

private:
    double m_x;
    double m_y;
    double m_z;
};

#endif // VECTOR3D_H



#endif //PLANEDESIGNBYMATH_VECTOR3D_H
