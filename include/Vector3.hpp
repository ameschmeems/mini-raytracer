#ifndef VECTOR3_HPP
# define VECTOR3_HPP

#include <vector>
#include <iostream>

class Vector3
{
public:

	Vector3();
	Vector3(float x, float y, float z);
	Vector3(const Vector3 &rhs);
	Vector3(Vector3 &&rhs) noexcept;
	~Vector3() = default;

	Vector3 &operator=(const Vector3 &rhs);
	Vector3 &operator=(Vector3 &&rhs) noexcept;
	Vector3 operator+(const Vector3 &rhs) const;
	Vector3 operator-(const Vector3 &rhs) const;
	Vector3 operator-() const;
	Vector3 operator*(float rhs) const;
	Vector3 operator/(float rhs) const;
	float &operator[](int n);
	bool operator==(const Vector3 &rhs) const;
	bool operator!=(const Vector3 &rhs) const;

	float x() const;
	float y() const;
	float z() const;
	float length() const;
	float dot(const Vector3 &rhs) const;
	Vector3 cross(const Vector3 &rhs) const;

private:

	std::vector<float> _vector {};
};

Vector3 operator*(float i, const Vector3 &rhs);

#endif