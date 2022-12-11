#ifndef H_Triangle3d
#define H_Triangle3d

#include "numeric.h"
#include "vector3d.h"
#include "edge3d.h"

namespace dt {

template<typename T>
struct Triangle3d
{
	using Type = T;
	using VertexType = Vector3d<Type>;
	using EdgeType = Edge3d<Type>;

	Triangle3d() = default;
	Triangle3d(const Triangle3d&) = default;
	Triangle3d(Triangle3d&&) = default;
	Triangle3d(const VertexType &v1, const VertexType &v2, const VertexType &v3);


    //void dot(const VertexType &v) const;


    //T cross(const Vector3d<T> &vertexA, const Vector3d<T> &vertexB)
    //{
     //   return Point( a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x );
   // }



    bool containsVertex(const VertexType &v) const;
	bool circumCircleContains(const VertexType &v) const;

	Triangle3d &operator=(const Triangle3d&) = default;
	Triangle3d &operator=(Triangle3d&&) = default;
	bool operator ==(const Triangle3d &t) const;

	template<typename U>
	friend std::ostream &operator <<(std::ostream &str, const Triangle3d<U> &t);

	const VertexType *a;
	const VertexType *b;
	const VertexType *c;
	bool isBad = false;

	static_assert(std::is_floating_point<Triangle3d<T>::Type>::value,
		"Type must be floating-point");
};

template<typename T>
bool almost_equal(const Triangle3d<T> &t1, const Triangle3d<T> &t2)
{
	return	(almost_equal(*t1.a , *t2.a) || almost_equal(*t1.a , *t2.b) || almost_equal(*t1.a , *t2.c)) &&
			(almost_equal(*t1.b , *t2.a) || almost_equal(*t1.b , *t2.b) || almost_equal(*t1.b , *t2.c)) &&
			(almost_equal(*t1.c , *t2.a) || almost_equal(*t1.c , *t2.b) || almost_equal(*t1.c , *t2.c));
}

} // namespace dt

#endif
