#include "triangle3d.h"

namespace dt {

template<typename T>
Triangle3d<T>::Triangle3d(const VertexType &v1, const VertexType &v2, const VertexType &v3) :
	a(&v1), b(&v2), c(&v3), isBad(false)
{}

template<typename T>
bool
Triangle3d<T>::containsVertex(const VertexType &v) const
{
	// return p1 == v || p2 == v || p3 == v;
	return almost_equal(*a, v) || almost_equal(*b, v) || almost_equal(*c, v);
}

/*template<typename T>
void
Triangle3d<T>::dot(const VertexType &v) const
{


}*/



template<typename T>
bool
Triangle3d<T>::circumCircleContains(const VertexType &v) const
{
	const T ab = a->norm3();
    const T cd = b->norm3();
	const T ef = c->norm3();
    std::cout << " norm3 ab: " << ab << " norm3 cd: " << cd << " norm3 ef: " << ef << std::endl;

	const T ax = a->x;
	const T ay = a->y;
	const T az = a->z;

    const T bx = b->x;
	const T by = b->y;
	const T bz = b->z;

    const T cx = c->x;
	const T cy = c->y;
    const T cz = c->z;

    const T distSideAB = sqrt(pow(bx - ax, 2) + pow(by - ay, 2) + pow(bz - az, 2));
    const T distSideBC = sqrt(pow(cx - bx, 2) + pow(cy - by, 2) + pow(cz - bz, 2));
    const T distSideCA = sqrt(pow(ax - cx, 2) + pow(ay - cy, 2) + pow(az - cz, 2));

   /* const T circum_radius = (distSideAB * distSideBC * distSideCA) / sqrt((distSideAB + distSideBC + distSideCA) *
            (-distSideAB + distSideBC + distSideCA) + (distSideAB - distSideBC + distSideCA) *
            (distSideAB + distSideBC - distSideCA));

    std::cout << " circumRadius: " << circum_radius << std::endl;*/

	const T circum_x = (ab * (cy - by) + cd * (ay - cy) + ef * (by - ay)) / (ax * (cy - by) + bx * (ay - cy) + cx * (by - ay));
	const T circum_y = (ab * (cx - bx) + cd * (ax - cx) + ef * (bx - ax)) / (ay * (cx - bx) + by * (ax - cx) + cy * (bx - ax));
    //const T circum_Z = (ab              + cd             +ef            ) / (                                                );

	const VertexType circum(circum_x / 2, circum_y / 2, 0); // circum_z / 2);
	const T circum_radius = a->dist3d(circum);
	const T dist = v.dist3d(circum);
	return dist <= circum_radius;

    //const T dp = v.dot(v1.x,{b->x,b->y,b->z});
}

template<typename T>
bool
Triangle3d<T>::operator ==(const Triangle3d &t) const
{
	return	(*this->a == *t.a || *this->a == *t.b || *this->a == *t.c) &&
			(*this->b == *t.a || *this->b == *t.b || *this->b == *t.c) &&
			(*this->c == *t.a || *this->c == *t.b || *this->c == *t.c);
}

template<typename U>
std::ostream&
operator <<(std::ostream &str, const Triangle3d<U> &t)
{
	return str << "Triangle:" << "\n\t" <<
			*t.a << "\n\t" <<
			*t.b << "\n\t" <<
			*t.c << '\n';
}

template struct Triangle3d<float>;
template struct Triangle3d<double>;

} // namespace dt
