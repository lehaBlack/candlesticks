#ifndef ARROW_H
#define ARROW_H
#include "object.hpp"
#include "procedures.hpp"
namespace drw{
	template <typename T = float>
	class Arrow :
		public Object < T > {
	public:
		inline Arrow(const T& startX, const T& startY, const T& finishX, const T& finishY)
		{
			T arrow0[2];
			T arrow1[2];

			arrow::pos(startX, startY, finishX, finishY, T(ALPHA), T(SHORT_LINE_LENGTH), arrow0);
			arrow::pos(startX, startY, finishX, finishY, -T(ALPHA), T(SHORT_LINE_LENGTH), arrow1);

			arrow_[0] = Point<T>(startX, startY);
			arrow_[1] = Point<T>(finishX, finishY);
			arrow_[2] = Point<T>(arrow0[0], arrow0[1]);
			arrow_[3] = Point<T>(arrow1[0], arrow1[1]);
		}
		inline virtual void draw() const override{
			ogl::color(1.0, 0.0, 0.0);
			ogl::begin::lines();

			ogl::vert(arrow_[0]);
			ogl::vert(arrow_[1]);

			ogl::vert(arrow_[1]);
			ogl::vert(arrow_[2]);

			ogl::vert(arrow_[1]);
			ogl::vert(arrow_[3]);

			ogl::end();
		}
		inline void re_scale(const T& x0, const T& dx, const T& y0, const T& dy) override{
			arrow_[0].re_scale(x0, dx, y0, dy);
			arrow_[1].re_scale(x0, dx, y0, dy);
			arrow_[2].re_scale(x0, dx, y0, dy);
			arrow_[3].re_scale(x0, dx, y0, dy);
			x(x()*dx + x0);
			y(y()*dy + y0);
		}
	private:
		Point<T> arrow_[4];
	};
}

#endif//ARROW_H