#include "math.h"

using namespace vapour::core::math;

vec3::vec3(double _x, double _y, double _z) {
	x = _x;
	y = _y;
	z = _z;
}

vec3::vec3() {
	x = 0;
	y = 0;
	z = 0;
}

std::string vec3::string() {
	return "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")";
}

vec3 vec3::forward() {
	return vec3(0, 0, 1);
};

vec3 vec3::back() {
	return vec3(0, 0, -1);
};

vec3 vec3::up() {
	return vec3(0, 1, 0);
};

vec3 vec3::down() {
	return vec3(0, -1, 0);
};

vec3 vec3::left() {
	return vec3(-1, 0, 0);
};

vec3 vec3::right() {
	return vec3(1, 0, 0);
};

vec3 vec3::zero() {
	return vec3(0, 0, 0);
};

vec3 vec3::one() {
	return vec3(1, 1, 1);
};

bool vec3::operator==(const vec3& other) const {
	return (
		other.x == x &&
		other.y == y &&
		other.z == z
	);
};

bool vec3::operator!=(const vec3& other) const {
	return (
		other.x != x ||
		other.y != y ||
		other.z != z
	);
}


vec3 vec3::operator+(const vec3& other) const {
	return vec3(
		other.x + x,
		other.y + y,
		other.z + z
	);
};

vec3 vec3::operator-(const vec3& other) const {
	return vec3(
		x - other.x,
		y - other.y,
		z - other.z
	);
};

vec3 vec3::operator*(const double& other) const {
	return vec3(
		other * x,
		other * y,
		other * z
	);
}


vec3 vec3::operator/(const double& other) const {
	return vec3(
		x / other,
		y / other,
		z / other
	);
}

double vec3::length() {
	return sqrt(x*x + y*y + z*z);
}

vec3 vec3::normalize() {
	return (*this) / length();
}

vec3 vec3::lerp(const vec3& a, const vec3& b, double beta) {
	return (a * (1.0 - beta)) + (b * beta);
}

vec4 vec4::lerp(const vec4& a, const vec4& b, double beta) {
	return (a * (1.0 - beta)) + (b * beta);
}

double vec3::dot(const vec3& a, const vec3& b) {
	return (
		a.x * b.x +
		a.y * b.y +
		a.z * b.z
	);
}

vec3 vec3::cross(const vec3& a, const vec3& b) {
	return vec3(
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x
	);
}

double vec3::operator*(const vec3& other) const {
	return vec3::dot(*this, other);
}

vec3 vec3::operator^(const vec3& other) const {
	return vec3::cross(*this, other);
}

vec4::vec4(double _x, double _y, double _z) {
	x = _x;
	y = _y;
	z = _z;
	w = 0;
}

vec4::vec4(double _x, double _y, double _z, double _w) {
	x = _x;
	y = _y;
	z = _z;
	w = _w;
}

vec4::vec4(vec3 a, double _w) {
	x = a.x;
	y = a.y;
	z = a.z;
	w = _w;
}

vec4::vec4(vec3 a) {
	x = a.x;
	y = a.y;
	z = a.z;
	w = 0.0;
}

vec4::vec4(quat a) {
	x = a.v.x;
	y = a.v.y;
	z = a.v.z;
	w = a.s;
}

vec4::vec4() {
	x = 0;
	y = 0;
	z = 0;
	w = 0;
}

std::string vec4::string() {
	return "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ", " + std::to_string(w) + ")";
}

vec4 vec4::forward() {
	return vec4(0, 0, 1);
};

vec4 vec4::back() {
	return vec4(0, 0, -1);
};

vec4 vec4::up() {
	return vec4(0, 1, 0);
};

vec4 vec4::down() {
	return vec4(0, -1, 0);
};

vec4 vec4::left() {
	return vec4(-1, 0, 0);
};

vec4 vec4::right() {
	return vec4(1, 0, 0);
};

vec4 vec4::zero() {
	return vec4(0, 0, 0);
};

vec4 vec4::one() {
	return vec4(1, 1, 1);
};

bool vec4::operator==(const vec4& other) const {
	return (
		other.x == x &&
		other.y == y &&
		other.z == z &&
		other.w == w
	);
};

bool vec4::operator!=(const vec4& other) const {
	return (
		other.x != x ||
		other.y != y ||
		other.z != z ||
		other.w != w
	);
}

vec4 vec4::operator+(const vec4& other) const {
	return vec4(
		other.x + x,
		other.y + y,
		other.z + z,
		other.w + w
	);
};

vec4 vec4::operator-(const vec4& other) const {
	return vec4(
		x - other.x,
		y - other.y,
		z - other.y,
		w - other.w
	);
};

vec4 vec4::operator*(const double& other) const {
	return vec4(
		other * x,
		other * y,
		other * z,
		other * w
	);
}


vec4 vec4::operator/(const double& other) const {
	return vec4(
		x / other,
		y / other,
		z / other,
		w / other
	);
}

double vec4::length() {
	return sqrt(x * x + y * y + z * z + w * w);
}

vec4 vec4::normalize() {
	return (*this) / length();
}

double vec4::dot(const vec4& a, const vec4& b) {
	return (
		a.x * b.x +
		a.y * b.y +
		a.z * b.z +
		a.w * b.w
	);
}

double vec4::operator*(const vec4& other) const {
	return vec4::dot(*this, other);
}

std::string mat3x3::string() const {
	std::string out;
	out += "{\n";
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			out += std::to_string(matrix[x][y]) + " ";
		}
		out += "\n";
	}
	out += "}";

	return out;
}

mat3x3 mat3x3::zero() {
	return mat3x3();
}

mat3x3 mat3x3::identity() {
	mat3x3 mat;
	mat.matrix[0][0] = 1;
	mat.matrix[1][1] = 1;
	mat.matrix[2][2] = 1;

	return mat;
}

mat3x3 mat3x3::operator+(const mat3x3& other) const {
	mat3x3 sum;

	sum.matrix[0][0] = other.matrix[0][0] + matrix[0][0];
	sum.matrix[0][1] = other.matrix[0][1] + matrix[0][1];
	sum.matrix[0][2] = other.matrix[0][2] + matrix[0][2];

	sum.matrix[1][0] = other.matrix[1][0] + matrix[1][0];
	sum.matrix[1][1] = other.matrix[1][1] + matrix[1][1];
	sum.matrix[1][2] = other.matrix[1][2] + matrix[1][2];

	sum.matrix[2][0] = other.matrix[2][0] + matrix[2][0];
	sum.matrix[2][1] = other.matrix[2][1] + matrix[2][1];
	sum.matrix[2][2] = other.matrix[2][2] + matrix[2][2];

	return sum;
}

mat3x3 mat3x3::operator-(const mat3x3& other) const {
	mat3x3 sum;

	sum.matrix[0][0] = matrix[0][0] - other.matrix[0][0];
	sum.matrix[0][1] = matrix[0][1] - other.matrix[0][1];
	sum.matrix[0][2] = matrix[0][2] - other.matrix[0][2];

	sum.matrix[1][0] = matrix[1][0] - other.matrix[1][0];
	sum.matrix[1][1] = matrix[1][1] - other.matrix[1][1];
	sum.matrix[1][2] = matrix[1][2] - other.matrix[1][2];

	sum.matrix[2][0] = matrix[2][0] - other.matrix[2][0];
	sum.matrix[2][1] = matrix[2][1] - other.matrix[2][1];
	sum.matrix[2][2] = matrix[2][2] - other.matrix[2][2];

	return sum;
}

mat3x3 mat3x3::operator*(const double& n) const {
	mat3x3 sum;

	sum.matrix[0][0] = matrix[0][0] * n;
	sum.matrix[0][1] = matrix[0][1] * n;
	sum.matrix[0][2] = matrix[0][2] * n;

	sum.matrix[1][0] = matrix[1][0] * n;
	sum.matrix[1][1] = matrix[1][1] * n;
	sum.matrix[1][2] = matrix[1][2] * n;

	sum.matrix[2][0] = matrix[2][0] * n;
	sum.matrix[2][1] = matrix[2][1] * n;
	sum.matrix[2][2] = matrix[2][2] * n;

	return sum;
}

mat3x3 mat3x3::operator/(const double& n) const {
	mat3x3 sum;

	sum.matrix[0][0] = matrix[0][0] / n;
	sum.matrix[0][1] = matrix[0][1] / n;
	sum.matrix[0][2] = matrix[0][2] / n;

	sum.matrix[1][0] = matrix[1][0] / n;
	sum.matrix[1][1] = matrix[1][1] / n;
	sum.matrix[1][2] = matrix[1][2] / n;

	sum.matrix[2][0] = matrix[2][0] / n;
	sum.matrix[2][1] = matrix[2][1] / n;
	sum.matrix[2][2] = matrix[2][2] / n;

	return sum;
}

mat3x3 mat3x3::operator*(const mat3x3& other) const { // todo: strassens?
	mat3x3 product;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			double sum = 0;

			for (int k = 0; k < 3; k++) {
				sum += matrix[j][k] * other.matrix[k][i];
			}

			product.matrix[j][i] = sum;
		}
	}

	return product;
}

vec3 mat3x3::operator*(const vec3& other) const {
	vec3 out;

	out.x = (other.x * matrix[0][0]) + (other.y * matrix[1][0]) + (other.z * matrix[2][0]);
	out.y = (other.x * matrix[0][1]) + (other.y * matrix[1][1]) + (other.z * matrix[2][1]);
	out.z = (other.x * matrix[0][2]) + (other.y * matrix[1][2]) + (other.z * matrix[2][2]);

	return out;
}

mat3x3::mat3x3() {
}

std::string mat4x4::string() const {
	std::string out;
	out += "{\n";
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			out += std::to_string(matrix[x][y]) + " ";
		}
		out += "\n";
	}
	out += "}";

	return out;
}

mat4x4 mat4x4::zero() {
	return mat4x4();
}

mat4x4 mat4x4::identity() {
	mat4x4 mat;
	mat.matrix[0][0] = 1;
	mat.matrix[1][1] = 1;
	mat.matrix[2][2] = 1;
	mat.matrix[3][3] = 1;

	return mat;
}

mat4x4 mat4x4::operator+(const mat4x4& other) const {
	mat4x4 sum;

	sum.matrix[0][0] = other.matrix[0][0] + matrix[0][0];
	sum.matrix[0][1] = other.matrix[0][1] + matrix[0][1];
	sum.matrix[0][2] = other.matrix[0][2] + matrix[0][2];
	sum.matrix[0][3] = other.matrix[0][3] + matrix[0][3];

	sum.matrix[1][0] = other.matrix[1][0] + matrix[1][0];
	sum.matrix[1][1] = other.matrix[1][1] + matrix[1][1];
	sum.matrix[1][2] = other.matrix[1][2] + matrix[1][2];
	sum.matrix[1][3] = other.matrix[1][3] + matrix[1][3];

	sum.matrix[2][0] = other.matrix[2][0] + matrix[2][0];
	sum.matrix[2][1] = other.matrix[2][1] + matrix[2][1];
	sum.matrix[2][2] = other.matrix[2][2] + matrix[2][2];
	sum.matrix[2][3] = other.matrix[2][3] + matrix[2][3];

	sum.matrix[3][0] = other.matrix[3][0] + matrix[3][0];
	sum.matrix[3][1] = other.matrix[3][1] + matrix[3][1];
	sum.matrix[3][2] = other.matrix[3][2] + matrix[3][2];
	sum.matrix[3][3] = other.matrix[3][3] + matrix[3][3];

	return sum;
}

mat4x4 mat4x4::operator-(const mat4x4& other) const {
	mat4x4 sum;

	sum.matrix[0][0] = matrix[0][0] - other.matrix[0][0];
	sum.matrix[0][1] = matrix[0][1] - other.matrix[0][1];
	sum.matrix[0][2] = matrix[0][2] - other.matrix[0][2];
	sum.matrix[0][3] = matrix[0][3] - other.matrix[0][3];

	sum.matrix[1][0] = matrix[1][0] - other.matrix[1][0];
	sum.matrix[1][1] = matrix[1][1] - other.matrix[1][1];
	sum.matrix[1][2] = matrix[1][2] - other.matrix[1][2];
	sum.matrix[1][3] = matrix[1][3] - other.matrix[1][3];

	sum.matrix[2][0] = matrix[2][0] - other.matrix[2][0];
	sum.matrix[2][1] = matrix[2][1] - other.matrix[2][1];
	sum.matrix[2][2] = matrix[2][2] - other.matrix[2][2];
	sum.matrix[2][3] = matrix[2][3] - other.matrix[2][3];

	sum.matrix[3][0] = matrix[3][0] - other.matrix[3][0];
	sum.matrix[3][1] = matrix[3][1] - other.matrix[3][1];
	sum.matrix[3][2] = matrix[3][2] - other.matrix[3][2];
	sum.matrix[3][3] = matrix[3][3] - other.matrix[3][3];

	return sum;
}

mat4x4 mat4x4::operator*(const double& n) const {
	mat4x4 sum;

	sum.matrix[0][0] = matrix[0][0] * n;
	sum.matrix[0][1] = matrix[0][1] * n;
	sum.matrix[0][2] = matrix[0][2] * n;
	sum.matrix[0][3] = matrix[0][3] * n;
	sum.matrix[1][0] = matrix[1][0] * n;
	sum.matrix[1][1] = matrix[1][1] * n;
	sum.matrix[1][2] = matrix[1][2] * n;
	sum.matrix[1][3] = matrix[1][3] * n;
	sum.matrix[2][0] = matrix[2][0] * n;
	sum.matrix[2][1] = matrix[2][1] * n;
	sum.matrix[2][2] = matrix[2][2] * n;
	sum.matrix[2][3] = matrix[2][3] * n;
	sum.matrix[3][0] = matrix[3][0] * n;
	sum.matrix[3][1] = matrix[3][1] * n;
	sum.matrix[3][2] = matrix[3][2] * n;
	sum.matrix[3][3] = matrix[3][3] * n;

	return sum;
}

mat4x4 mat4x4::operator/(const double& n) const {
	mat4x4 sum;

	sum.matrix[0][0] = matrix[0][0] / n;
	sum.matrix[0][1] = matrix[0][1] / n;
	sum.matrix[0][2] = matrix[0][2] / n;
	sum.matrix[0][3] = matrix[0][3] / n;
	sum.matrix[1][0] = matrix[1][0] / n;
	sum.matrix[1][1] = matrix[1][1] / n;
	sum.matrix[1][2] = matrix[1][2] / n;
	sum.matrix[1][3] = matrix[1][3] / n;
	sum.matrix[2][0] = matrix[2][0] / n;
	sum.matrix[2][1] = matrix[2][1] / n;
	sum.matrix[2][2] = matrix[2][2] / n;
	sum.matrix[2][3] = matrix[2][3] / n;
	sum.matrix[3][0] = matrix[3][0] / n;
	sum.matrix[3][1] = matrix[3][1] / n;
	sum.matrix[3][2] = matrix[3][2] / n;
	sum.matrix[3][3] = matrix[3][3] / n;

	return sum;
}

mat4x4 mat4x4::operator*(const mat4x4& other) const { // todo: strassens?
	mat4x4 product;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			double sum = 0;

			for (int k = 0; k < 4; k++) {
				sum += matrix[j][k] * other.matrix[k][i];
			}

			product.matrix[j][i] = sum;
		}
	}

	return product;
}

vec4 mat4x4::operator*(const vec4& other) const {
	vec4 out;

	out.x = (other.x * matrix[0][0]) + (other.y * matrix[1][0]) + (other.z * matrix[2][0]) + (other.w * matrix[3][0]);
	out.y = (other.x * matrix[0][1]) + (other.y * matrix[1][1]) + (other.z * matrix[2][1]) + (other.w * matrix[3][1]);
	out.z = (other.x * matrix[0][2]) + (other.y * matrix[1][2]) + (other.z * matrix[2][2]) + (other.w * matrix[3][2]);
	out.w = (other.x * matrix[0][3]) + (other.y * matrix[1][3]) + (other.z * matrix[2][3]) + (other.w * matrix[3][3]);

	return out;
}

mat4x4::mat4x4() {
}

mat4x4 mat4x4::scale(vec3 size) {
	mat4x4 out;

	out.matrix[0][0] = size.x;
	out.matrix[1][1] = size.y;
	out.matrix[2][2] = size.z;
	out.matrix[3][3] = 1;

	return out;
}

mat4x4 mat4x4::trans(vec3 pos) {
	mat4x4 out = mat4x4::identity();
	out.matrix[3][0] = pos.x;
	out.matrix[3][1] = pos.y;
	out.matrix[3][2] = pos.z;

	return out;
}

quat::quat() {
	v = vec3::zero();
	s = 1;
};

quat::quat(vec3 _v, double _s) {
	v = _v;
	s = _s;
}
quat::quat(vec4 _v) {
	v = vec3(_v.x, _v.y, _v.z);
	s = _v.w;
}

quat quat::operator*(const quat& other) const { // grassman
	return quat(
		((other.v * s) + (v * other.s) + (v ^ other.v)),
		((s * other.s) - (v * other.v))
	);
}

quat quat::operator-() const {
	return quat(v * -1, s);
}

std::string quat::string() {
	return "(" + std::to_string(v.x) + ", " + std::to_string(v.y) + ", " + std::to_string(v.z) + " : " + std::to_string(s) + ")";
}

vec3 quat::rotate(vec3 in) const {
	return ((*this) * quat(in, 0) * -(*this)).v;
}

quat quat::lerp(const quat& a, const quat& b, double beta) {
	return quat(vec4::lerp(vec4(a), vec4(b), beta).normalize());
}

quat quat::slerp(const quat& a, const quat& b, double beta) {
	vec4 p = vec4(a);
	vec4 q = vec4(b);

	double theta = acos(p * q);
	double stheta = sin(theta);

	double wp = sin((1.0 - beta) * theta) / stheta;
	double wq = sin(beta * theta) / stheta;

	return quat((p * wp) + (q * wq));
}

mat4 quat::matrix() const {
	mat4 out = mat4::identity();

	out.matrix[0][0] = 1 - 2 * (v.y * v.y) - 2 * (v.z * v.z);
	out.matrix[1][0] = (2 * v.x * v.y) - (2 * v.z * s);
	out.matrix[2][0] = (2 * v.x * v.z) + (2 * v.y * s);
	
	out.matrix[0][1] = (2 * v.x * v.y) + (2 * v.z * s);
	out.matrix[1][1] = 1 - (2 * (v.x * v.x)) - (2 * (v.z * v.z));
	out.matrix[2][1] = (2 * v.y * v.z) - (2 * v.x - s);

	out.matrix[0][2] = (2 * v.x * v.z) - (2 * v.y * s);
	out.matrix[1][2] = (2 * v.y * v.z) + (2 * v.x * s);
	out.matrix[2][2] = 1 - (2 * (v.x * v.x)) - (2 * (v.y * v.y));

	return out;
}

mat4 Transform::matrix() const {
	mat4 m_trans  = mat4::trans(position);
	mat4 m_scale  = mat4::scale(scale);
	mat4 m_rotate = rotation.matrix();

	return m_trans * m_rotate * m_scale;
}

Transform::Transform() {
	position = vec3::zero();
	rotation = quat();
	scale = vec3::one();
}

Transform::Transform(vec3 _pos) {
	position = _pos;
	rotation = quat();
	scale = vec3::one();
}

Transform::Transform(vec3 _pos, quat _rot) {
	position = _pos;
	rotation = _rot;
	scale = vec3::one();
}

Transform::Transform(vec3 _pos, quat _rot, vec3 _sc) {
	position = _pos;
	rotation = _rot;
	scale = _sc;
}

Transform::Transform(vec3 _pos, vec3 _sc) {
	position = _pos;
	rotation = quat();
	scale = _sc;
}

Transform::Transform(quat rot) {
	rotation = rot;
}

std::string Transform::string() {
	return "[transform] {\n  position: " + position.string() + "\n  rotation: " + rotation.string() + "\n  scale:    " + scale.string() + "\n}";
}