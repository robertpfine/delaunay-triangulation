#ifndef H_VECTOR3D
#define H_VECTOR3D

#include "numeric.h"

#include <iostream>
#include <cmath>
#include <type_traits>
#include <vector>

namespace dt {

    //template<typename T>


    struct Vector3d
{
	//using Type = T;
	Vector3d() = default;
	Vector3d(const Vector3d &v) = default;
	Vector3d(Vector3d&&) = default;
	Vector3d(const double vx, const double vy, const double vz);

	double dist3d(const Vector3d &v) const;
    double dist3dv2(const Vector3d &v) const;

    double dist(const Vector3d &v) const;
	double norm3() const;


    //Vector3d<T> &crossProdResult;
    //Vector3d<T> cross(const Vector3d<T> &u, const Vector3d<T> &v);


	Vector3d &operator=(const Vector3d&) = default;
	Vector3d &operator=(Vector3d&&) = default;
	bool operator ==(const Vector3d &v) const;
	//template<typename U>
	friend std::ostream &operator <<(std::ostream &str, const Vector3d &v);

	double x;
	double y;
    double z;

	//static_assert(std::is_floating_point<Vector3d>::value,
	//	"Type must be floating-point");
};

//template<typename T>
/*bool almost_equal(const Vector3d &v1, const Vector3d &v2)
{
	return almost_equal(v1.x, v2.x) && almost_equal(v1.y, v2.y) && almost_equal(v1.z, v2.z);
}*/

} // namespace dt

#endif
