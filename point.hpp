#ifndef POINT_H
#define POINT_H
#include "object.hpp"

namespace drw{
	template <typename T = float>
	class Point : public Object < T > {
	public:
		inline void re_scale(const T& x0, const T& dx, const T& y0, const T& dy) override{
			x(x()*dx + x0);
			y(y()*dy + y0);
		}

		//--------------------------------------------------
		inline Point() :
			Object<T>()
		{}
		inline Point(const T& x, const T& y) :
			Object<T>(x, y)
		{}
	};
}
#endif