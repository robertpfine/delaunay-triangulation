#ifndef H_DELAUNAY
#define H_DELAUNAY

#include "vector3d.h"
#include "edge3d.h"
#include "triangle3d.h"

#include <vector>
#include <algorithm>

namespace dt {

//template<typename T>
class Delaunay3d
{
	//using Type = T;
	using VertexType = Vector3d;
	using EdgeType = Edge3d;
	using TriangleType = Triangle3d;

	//static_assert(std::is_floating_point<Delaunay3d<T>::Type>::value,
	//	"Type must be floating-point");

	std::vector<TriangleType> _triangles;
	std::vector<EdgeType> _edges;
	std::vector<Vector3d> _vertices;

public:

	Delaunay3d() = default;
	Delaunay3d(const Delaunay3d&) = delete;
	Delaunay3d(Delaunay3d&&) = delete;

	const std::vector<TriangleType>& triangulate(std::vector<VertexType> &vertices);
	const std::vector<TriangleType>& getTriangles() const;
	const std::vector<EdgeType>& getEdges() const;
	const std::vector<Vector3d>& getVertices() const;
    //const std::vector<VertexType>& getVertices() const;

	Delaunay3d& operator=(const Delaunay3d&) = delete;
	Delaunay3d& operator=(Delaunay3d&&) = delete;
};

} // namespace dt

#endif
