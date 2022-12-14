#include "triangle3d.h"

//#include <boost/geometry/arithmetic/cross_product.hpp>

namespace dt {

//template<typename T>
Triangle3d::Triangle3d(const VertexType &v1, const VertexType &v2, const VertexType &v3) :
	a(&v1), b(&v2), c(&v3), isBad(false)
{}

//template<typename T>
/*bool Triangle3d::containsVertex(const VertexType &v) const
{
	// return p1 == v || p2 == v || p3 == v;
	return almost_equal(*a, v) || almost_equal(*b, v) || almost_equal(*c, v);
}*/

/*template<typename T>
void
Triangle3d<T>::dot(const VertexType &v) const
{


}*/



//template<typename T>
bool Triangle3d::circumCircleContains(const VertexType &v) const
{
	const double ab = a->norm3();
    const double cd = b->norm3();
	const double ef = c->norm3();
    //std::cout << " norm3 ab: " << ab << " norm3 cd: " << cd << " norm3 ef: " << ef << std::endl;

	const double ax = a->x;
	const double ay = a->y;
	const double az = a->z;

    const double bx = b->x;
	const double by = b->y;
	const double bz = b->z;

    const double cx = c->x;
	const double cy = c->y;
    const double cz = c->z;

    const double xAC = ax - cx;
    const double yAC = ay - cy;
    const double zAC = az - cz;

    const double xBC = bx - cx;
    const double yBC = by - cy;
    const double zBC = bz - cz;



    const Vector3d AC = {ax - cx, ay - cy, az - cz};
    const Vector3d BC = {bx - cx, by - cy, bz - cz};



   //dt::Vector3d<T> crossProduct1;
   //crossProduct1.cross(AC, BC);
   //const Vector3d<T> test = crossProduct1.cross(AC, BC);
   //std::cout << " AC x BC PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP: " << test << std::endl;


   dt::Vector3d crossProduct2;
   const double normAC = crossProduct2.dist3dv2(AC);
   std::cout << " norm of AC xxxxxxxxxxxxxxxxxxxxxx: " << normAC << std::endl;

    //const T distSideAB = sqrt(pow(bx - ax, 2) + pow(by - ay, 2) + pow(bz - az, 2));
    //const T distSideBC = sqrt(pow(cx - bx, 2) + pow(cy - by, 2) + pow(cz - bz, 2));
    //const T distSideCA = sqrt(pow(ax - cx, 2) + pow(ay - cy, 2) + pow(az - cz, 2));

   /* const T circum_radius = (distSideAB * distSideBC * distSideCA) / sqrt((distSideAB + distSideBC + distSideCA) *
            (-distSideAB + distSideBC + distSideCA) + (distSideAB - distSideBC + distSideCA) *
            (distSideAB + distSideBC - distSideCA));

    std::cout << " circumRadius: " << circum_radius << std::endl;*/

	const double circum_x = (ab * (cy - by) + cd * (ay - cy) + ef * (by - ay)) / (ax * (cy - by) + bx * (ay - cy) + cx * (by - ay));
	const double circum_y = (ab * (cx - bx) + cd * (ax - cx) + ef * (bx - ax)) / (ay * (cx - bx) + by * (ax - cx) + cy * (bx - ax));
    //const double circum_Z = (ab              + cd             +ef            ) / (                                                );

	const VertexType circum(circum_x / 2, circum_y / 2, 0); // circum_z / 2);
	const double circum_radius = a->dist3d(circum);
	const double dist = v.dist3d(circum);
	return dist <= circum_radius;

    //const T dp = v.dot(v1.x,{b->x,b->y,b->z});
}

//template<typename T>
bool Triangle3d::operator ==(const Triangle3d &t) const
{
	return	(*this->a == *t.a || *this->a == *t.b || *this->a == *t.c) &&
			(*this->b == *t.a || *this->b == *t.b || *this->b == *t.c) &&
			(*this->c == *t.a || *this->c == *t.b || *this->c == *t.c);
}

//template<typename U>
std::ostream& operator <<(std::ostream &str, const Triangle3d &t)
{
	return str << "Triangle:" << "\n\t" <<
			*t.a << "\n\t" <<
			*t.b << "\n\t" <<
			*t.c << '\n';
}

//template struct Triangle3d<float>;
//template struct Triangle3d<double>;

} // namespace dt
