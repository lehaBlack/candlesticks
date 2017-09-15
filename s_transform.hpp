#ifndef S_TRANSFORM_H
#define S_TRANSFORM_H
#include "transform.hpp"
#include "object.hpp"

namespace drw{
	template <typename T>
	class STransform :
		public Transform < Object<T>* >
	{
	public:
		STransform(const T& x0, const T& dx, const T& y0, const T& dy) :
			x0(x0), dx(dx), y0(y0), dy(dy)
		{}

		inline void operator() (Object<T>*& object) override{
			object->re_scale(x0, dx, y0, dy);
		}
	private:
		T x0;
		T dx;
		T y0;
		T dy;
	};
}

#endif// S_TRANSFORM_H