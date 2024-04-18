//
// Created by ASUS on 2024/4/8.
//

#include "Vector3D.h"

// 构造函数
Vector3D::Vector3D() : m_x(0.0), m_y(0.0), m_z(0.0) {}

Vector3D::Vector3D(double x, double y, double z) : m_x(x), m_y(y), m_z(z) {}

// 获取向量各分量的值
double Vector3D::getX() const { return m_x; }

double Vector3D::getY() const { return m_y; }

double Vector3D::getZ() const { return m_z; }

// 计算向量的模长
double Vector3D::magnitude() const {
    return std::sqrt(m_x * m_x + m_y * m_y + m_z * m_z);
}

// 返回向量的单位向量
Vector3D Vector3D::normalize() const {
    double mag = magnitude();
    if (mag != 0.0) {
        return Vector3D(m_x / mag, m_y / mag, m_z / mag);
    } else {
        return Vector3D();
    }
}

// 返回向量的反向
Vector3D Vector3D::negate() const {
    return Vector3D(-m_x, -m_y, -m_z);
}

// 向量加法
Vector3D Vector3D::operator+(const Vector3D& other) const {
    return Vector3D(m_x + other.m_x, m_y + other.m_y, m_z + other.m_z);
}

// 向量减法
Vector3D Vector3D::operator-(const Vector3D& other) const {
    return Vector3D(m_x - other.m_x, m_y - other.m_y, m_z - other.m_z);
}

// 向量与标量的乘法
Vector3D Vector3D::operator*(double scalar) const {
    return Vector3D(m_x * scalar, m_y * scalar, m_z * scalar);
}

// 向量点积
double Vector3D::dot(const Vector3D& other) const {
    return m_x * other.m_x + m_y * other.m_y + m_z * other.m_z;
}

// 向量叉积
Vector3D Vector3D::cross(const Vector3D& other) const {
    return Vector3D(m_y * other.m_z - m_z * other.m_y,
                    m_z * other.m_x - m_x * other.m_z,
                    m_x * other.m_y - m_y * other.m_x);
}

