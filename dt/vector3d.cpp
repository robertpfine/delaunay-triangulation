#include "vector3d.h"

namespace dt {

//template<typename T>
Vector3d::Vector3d(const double vx, const double vy, const double vz) :
	x(vx), y(vy), z(vz)
{}

//template<typename T>
//T
/*double Vector3d::dist3d(const Vector3d &v) const
{
	const double dx = x - v.x;
	const double dy = y - v.y;
    const double dz = z - v.z;
	return sqrt(dx * dx + dy * dy + dz * dz);
}*/

    //template<typename T>
    //T
  double  Vector3d::dist3dv2(const Vector3d &v) const
    {
        const double dx = v.x;
        const double dy = v.y;
        const double dz = v.z;
        return sqrt(dx * dx + dy * dy + dz * dz);
    }


//template<>
//float
double Vector3d::dist3d(const Vector3d &v) const
{
	//return hypot(x - v.x, y - v.y, z - v.z);
    return sqrt(pow(x - v.x, 2) + pow(y - v.y, 2) + pow(z - v.z, 2));
}

//template<>
//double
double Vector3d::dist(const Vector3d &v) const
{
	//return hypot(x - v.x, y - v.y);
    return sqrt(pow(x - v.x, 2) + pow(y - v.y, 2) + pow(z - v.z, 2));
}

//template<typename T>
//T
double Vector3d::norm3() const
{
	return x * x + y * y + z * z;
}


/*template<typename T>
T
Vector3d<T>::cross(const Vector3d<T> &u, const Vector3d<T> &v)
{

    //crossProdResult[0] = u.y * v.z - u.z * v.y;
    //crossProdResult[1] =
    //crossProdResult[2]

    return Vector3d( u.y * v.z - u.z * v.y, u.z * v.x - u.x * v.z, u.x * v.y - u.y * v.x );

}*/

// Point cross(const Point a, const Point b)


/*template<>
[[maybe_unused]] double
Vector3d<double>::dot(const Vector3d<double> &vertexA, const Vector3d<double> &vertexB)
{
    std::cout << " dot Product: " << (vertexA.x * vertexB.x + vertexA.y * vertexB.y + vertexA.z * vertexB.z) << std::endl;
    return (vertexA.x * vertexB.x + vertexA.y * vertexB.y + vertexA.z * vertexB.z);
}*/





//template<typename T>

bool Vector3d::operator ==(const Vector3d &v) const
{
	return (this->x == v.x) && (this->y == v.y) && (this->z == v.z);
}

//template<typename U>
std::ostream &
operator <<(std::ostream &str, const Vector3d &v)
{
	return str << "Point x: " << v.x << " y: " << v.y << " z " << v.z;
}

//template struct Vector3d<float>;
//template struct Vector3d<double>;

} // namespace dt
