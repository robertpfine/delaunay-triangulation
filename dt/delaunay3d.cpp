#include "delaunay3d.h"

namespace dt {

//template<typename T>
//const std::vector<typename Delaunay3d::TriangleType>& Delaunay3d::triangulate(std::vector<VertexType> &vertices)
const std::vector<Triangle3d>& Delaunay3d::triangulate(std::vector<VertexType> &vertices)
{
	// Store the vertices locally
	_vertices = vertices;

	// Determinate the super triangle
	double minX = vertices[0].x;
	double minY = vertices[0].y;
    double minZ = vertices[0].z;

    double maxX = minX;
	double maxY = minY;
    double maxZ = minZ;

	for(std::size_t i = 0; i < vertices.size(); ++i)
	{
		if (vertices[i].x < minX) minX = vertices[i].x;
		if (vertices[i].y < minY) minY = vertices[i].y;
        if (vertices[i].z < minZ) minZ = vertices[i].z;
        if (vertices[i].x > maxX) maxX = vertices[i].x;
		if (vertices[i].y > maxY) maxY = vertices[i].y;
        if (vertices[i].z > maxZ) maxZ = vertices[i].z;
    }

	const double dx = maxX - minX;
	const double dy = maxY - minY;
    const double dz = maxZ - minZ;

    const double deltaMax = std::max({dx, dy, dz});

    const double midx = (minX + maxX) / 2;
	const double midy = (minY + maxY) / 2;
    const double midz = (minZ + maxZ) / 2;


	const VertexType p1(midx - 20 * deltaMax, midy - deltaMax, midz - deltaMax);
	const VertexType p2(midx, midy + 20 * deltaMax, midz - deltaMax);
	const VertexType p3(midx + 20 * deltaMax, midy - deltaMax, midz - deltaMax);

	// Create a list of triangles, and add the supertriangle in it
	_triangles.push_back(TriangleType(p1, p2, p3));

	for(auto p = begin(vertices); p != end(vertices); p++)
	{
		std::vector<EdgeType> polygon;

		for(auto & t : _triangles)
		{
			if(t.circumCircleContains(*p))
			{
				t.isBad = true;
				polygon.push_back(Edge3d{*t.a, *t.b});
				polygon.push_back(Edge3d{*t.b, *t.c});
				polygon.push_back(Edge3d{*t.c, *t.a});
			}
		}

		_triangles.erase(std::remove_if(begin(_triangles), end(_triangles), [](TriangleType &t){
			return t.isBad;
		}), end(_triangles));

		for(auto e1 = begin(polygon); e1 != end(polygon); ++e1)
		{
			for(auto e2 = e1 + 1; e2 != end(polygon); ++e2)
			{
				if(almost_equal(*e1, *e2))
				{
					e1->isBad = true;
					e2->isBad = true;
				}
			}
		}

		polygon.erase(std::remove_if(begin(polygon), end(polygon), [](EdgeType &e){
			return e.isBad;
		}), end(polygon));

		for(auto e : polygon)
			_triangles.push_back(Triangle3d(*e.v, *e.w, *p));

        //for(const auto e : polygon)
        //_triangles.push_back(Triangle3d(*e.v, *e.w, *p));

	}

	_triangles.erase(std::remove_if(begin(_triangles), end(_triangles), [p1, p2, p3](TriangleType &t){
		return t.containsVertex(p1) || t.containsVertex(p2) || t.containsVertex(p3);
	}), end(_triangles));

	for(const auto t : _triangles)
	{
		_edges.push_back(Edge3d{*t.a, *t.b});
		_edges.push_back(Edge3d{*t.b, *t.c});
		_edges.push_back(Edge3d{*t.c, *t.a});
	}

	return _triangles;
}

//template<typename T>
const std::vector<Triangle3d>& Delaunay3d::getTriangles() const
{
	return _triangles;
}

//template<typename T>
const std::vector<Edge3d>& Delaunay3d::getEdges() const
{
	return _edges;
}

//template<typename T>
//const std::vector<typename Delaunay3d::VertexType>& Delaunay3d::getVertices() const
const std::vector<Vector3d>& Delaunay3d::getVertices() const
{
	return _vertices;
}

//template class Delaunay3d<float>;
//template class Delaunay3d<double>;

} // namespace dt
