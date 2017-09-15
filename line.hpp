#ifndef LINE_H
#define LINE_H
#include "point.hpp"
#include "procedures.hpp"
namespace drw{
	template<typename T>
	class Line :public Object < T > {
	public:
		Line(const T& x0, const T& y0, const T& x1, const T& y1){
			points_[0] = Point<T>(x0, y0);
			points_[1] = Point<T>(x1, y1);
		}
		inline void draw() const override{
			ogl::color(0.0, 0.0, 0.0);
			ogl::begin::lines();
			ogl::vert(points_[0]);
			ogl::vert(points_[1]);
			ogl::end();
		}
		inline void re_scale(const T& x0, const T& dx, const T& y0, const T& dy) override{
			points_[0].re_scale(x0, dx, y0, dy); 
			points_[1].re_scale(x0, dx, y0, dy);
		}
	private:
		Point<T> points_[2];
	};
}
#endif