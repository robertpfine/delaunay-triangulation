#include "edge3d.h"

namespace dt {

//template<typename T>
Edge3d::Edge3d(const VertexType &v1, const VertexType &v2) :
        v(reinterpret_cast<const Edge3d *>(&v1)), w(reinterpret_cast<const Edge3d *>(&v2))
{}

//template<typename T>
//bool
bool Edge3d::operator ==(const Edge3d &e) const
{
	return (*(this->v) == *e.v && *(this->w) == *e.w) ||
			(*(this->v) == *e.w && *(this->w) == *e.v);
}

//template<typename U>
std::ostream&
operator <<(std::ostream &str, const Edge3d &e)
{
	return str << "Edge3d " << *e.v << ", " << *e.w;
}

//template struct Edge3d<float>;
//template struct Edge3d<double>;

} // namespace dt
