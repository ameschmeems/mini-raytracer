#include "Vector3.hpp"
#include <iostream>
#include <cmath>

Vector3::Vector3() : _vector { 0.0, 0.0, 0.0 }
{
}

Vector3::Vector3(float x, float y, float z) : _vector { x, y, z }
{
}

Vector3::Vector3(const Vector3 &rhs) : _vector { rhs._vector }
{
}

Vector3::Vector3(Vector3 &&rhs) noexcept : _vector { std::move(rhs._vector) }
{
}

Vector3 &Vector3::operator=(const Vector3 &rhs)
{
	_vector = rhs._vector;
	return *this;
}

Vector3 &Vector3::operator=(Vector3 &&rhs) noexcept
{
	_vector = std::move(rhs._vector);
	return *this;
}

Vector3 Vector3::operator+(const Vector3 &rhs) const
{
	std::vector<float> temp {};
	
	for (int i = 0; i < _vector.size(); i++)
		temp.push_back(_vector[i] + rhs._vector[i]);
	return Vector3 { temp[0], temp[1], temp[2] };
}

Vector3 Vector3::operator-(const Vector3 &rhs) const
{
	std::vector<float> temp {};

	for (int i = 0; i < _vector.size(); i++)
		temp.push_back(_vector[i] - rhs._vector[i]);
	return Vector3 { temp[0], temp[1], temp[2] };
}

Vector3 Vector3::operator-() const
{
	return Vector3 { -_vector[0], -_vector[1], -_vector[2] };
}

Vector3 Vector3::operator*(float rhs) const
{
	std::vector<float> temp {};

	for (auto n : _vector)
		temp.push_back(n * rhs);
	return Vector3 { temp[0], temp[1], temp[2] };
}

Vector3 Vector3::operator*(const Vector3 &rhs) const
{
	std::vector<float> temp {};

	for (int i = 0; i < _vector.size(); i++)
		temp.push_back(_vector[i] * rhs._vector[i]);
	return Vector3 { temp[0], temp[1], temp[2] };
}

Vector3 Vector3::operator/(float rhs) const
{
	std::vector<float> temp {};

	for (auto n : _vector)
		temp.push_back(n / rhs);
	return Vector3 { temp[0], temp[1], temp[2] };
}

float &Vector3::operator[](int n)
{
	return _vector[n];
}

bool Vector3::operator==(const Vector3 &rhs) const
{
	for (int i = 0; i < 3; i++)
		if (_vector[i] != rhs._vector[i])
			return false;
	return true;
}

bool Vector3::operator!=(const Vector3 &rhs) const
{
	return !((*this) == rhs);
}

float Vector3::x() const
{
	return _vector[0];
}

float Vector3::y() const
{
	return _vector[1];
}

float Vector3::z() const
{
	return _vector[2];
}

float Vector3::length() const
{
	return sqrtf(powf(_vector[0], 2) + powf(_vector[1], 2) + powf(_vector[2], 2));
}

float Vector3::dot(const Vector3 &rhs) const
{
	return (_vector[0] * rhs._vector[0]) + (_vector[1] * rhs._vector[1]) + (_vector[2] * rhs._vector[2]);
}

Vector3 Vector3::cross(const Vector3 &rhs) const
{
	float x { _vector[1] * rhs._vector[2] - _vector[2] * rhs._vector[1] };
	float y { _vector[2] * rhs._vector[0] - _vector[0] * rhs._vector[2] };
	float z { _vector[0] * rhs._vector[1] - _vector[1] * rhs._vector[0] };

	return Vector3 { x, y, z };
}

Vector3 Vector3::normalized() const
{
	return *this / this->length();
}

Vector3 operator*(float i, const Vector3 &rhs)
{
	return rhs * i;
}
