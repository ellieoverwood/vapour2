#pragma once
#include <string>
#include "ecs.h"

namespace vapour {
	namespace math {
		struct vec3 {
			double x;
			double y;
			double z;

			vec3(double x, double y, double z);
			vec3();

			std::string string();

			static vec3 forward();
			static vec3 back();
			static vec3 up();
			static vec3 down();
			static vec3 left();
			static vec3 right();
			static vec3 zero();
			static vec3 one();

			bool operator==(const vec3& other) const;
			bool operator!=(const vec3& other) const;
			vec3 operator+(const vec3& other) const;
			vec3 operator-(const vec3& other) const;
			vec3 operator*(const double& other) const;
			vec3 operator/(const double& other) const;

			double length();
			vec3   normalize();

			static double dot(const vec3& a, const vec3& b);
			static vec3 cross(const vec3& a, const vec3& b);
			static vec3 lerp(const vec3& a, const vec3& b, double beta);

			double operator*(const vec3& other) const;
			vec3   operator^(const vec3& other) const;
		};

		struct quat;

		struct vec4 {
			double x;
			double y;
			double z;

			double w;

			vec4(double x, double y, double z);
			vec4(double x, double y, double z, double w);
			vec4(vec3 a, double w);
			vec4(vec3 a);
			vec4(quat a);
			vec4();

			std::string string();

			static vec4 forward();
			static vec4 back();
			static vec4 up();
			static vec4 down();
			static vec4 left();
			static vec4 right();
			static vec4 zero();
			static vec4 one();

			bool operator==(const vec4& other) const;
			bool operator!=(const vec4& other) const;
			vec4 operator+(const vec4& other) const;
			vec4 operator-(const vec4& other) const;
			vec4 operator*(const double& other) const;
			vec4 operator/(const double& other) const;

			double length();
			vec4   normalize();

			static double dot(const vec4& a, const vec4& b);
			static vec4 lerp(const vec4& a, const vec4& b, double beta);

			double operator*(const vec4& other) const;
		};

		struct mat3x3 {
			double matrix[3][3] = { 0 };

			std::string string() const;

			mat3x3();

			mat3x3  operator+ (const mat3x3& other) const;
			mat3x3  operator- (const mat3x3& other) const;
			mat3x3  operator* (const double& n) const;
			mat3x3  operator/ (const double& n) const;
			mat3x3  operator* (const mat3x3& other) const;
			vec3    operator* (const vec3& other) const;

			static mat3x3 zero();
			static mat3x3 identity();
		};

		struct mat4x4 {
			double matrix[4][4] = { 0 };

			std::string string() const;

			mat4x4();

			mat4x4  operator+ (const mat4x4& other) const;
			mat4x4  operator- (const mat4x4& other) const;
			mat4x4  operator* (const double& n) const;
			mat4x4  operator/ (const double& n) const;
			mat4x4  operator* (const mat4x4& other) const;
			vec4    operator* (const vec4& other) const;

			static mat4x4 zero();
			static mat4x4 identity();
			static mat4x4 scale(vec3 vec);
			static mat4x4 trans(vec3 vec);
			// TODO: add -- static mat4x4 perspective(double fov, double aspect, double near, double far);
		};

		using mat3 = mat3x3;
		using mat4 = mat4x4;

		struct quat {
			vec3   v;
			double s;

			quat();
			quat(vec3 _v, double _s);
			quat(vec4 _v);

			quat operator*(const quat& other) const;
			quat operator-() const;

			vec3 rotate(vec3 in) const;
			mat4 matrix() const;

			static quat lerp(const quat& a, const quat& b, double beta);
			static quat slerp(const quat& a, const quat& b, double beta);

			std::string string();
		};

		struct Transform {
			vec3 position;
			quat rotation;
			vec3 scale;

			Transform();
			Transform(vec3 position);
			Transform(vec3 position, quat rotation);
			Transform(vec3 position, quat rotation, vec3 scale);
			Transform(vec3 position, vec3 scale);
			Transform(quat rotation);

			mat4 matrix() const;
			std::string string();

			static void declare();
		};
	}
}