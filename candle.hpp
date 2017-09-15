#ifndef CANDLE_H
#define CANDLE_H
#include <algorithm>
#include "point.hpp"
#undef max
#undef min

namespace drw{
	template<typename T>
	class Candle :
		public Object < T > {
	public:
		inline Candle() :
			Object<T>()
		{}

		inline Candle(const T& x, const T& delta, const T& open, const T& close, const T& minimum, const T& maximum) :
			Object<T>(x, 0),
			minimum_(minimum),
			maximum_(maximum)
		{

			height(std::max(open, close) - std::min(open, close));
			T half_height_ = height() * 0.5;
			width(delta);
			T half_width_ = width()*0.5;
			y((open + close)*0.5);

			points_[0].x(this->x() - half_width_); points_[0].y(this->y() - half_height_);
			points_[1].x(this->x() - half_width_); points_[1].y(this->y() + half_height_);
			points_[2].x(this->x() + half_width_); points_[2].y(this->y() + half_height_);
			points_[3].x(this->x() + half_width_); points_[3].y(this->y() - half_height_);
		}

		inline void draw() const override{

			ogl::begin::lines();

			ogl::color(0.0, 0.0, 1.0);
			ogl::vert(x(), minimum_);
			ogl::vert(x(), maximum_);
			ogl::end();

			ogl::begin::quads();
			ogl::color(1.0, 1.0, 0.0);
			for (int i = 0; i < 4; i++)
			{
				points_[i].draw();
			}
			ogl::end();
		}
		inline void re_scale(const T& x0, const T& dx, const T& y0, const T& dy) override{
			points_[0].re_scale(x0, dx, y0, dy);
			points_[1].re_scale(x0, dx, y0, dy);
			points_[2].re_scale(x0, dx, y0, dy);
			points_[3].re_scale(x0, dx, y0, dy);
			x(x()*dx + x0);
			y(y()*dy + y0);

			minimum_ = minimum_*dy + y0;
			maximum_ = maximum_*dy + y0;
		}
	private:
		Point<T> points_[4];
		T minimum_;
		T maximum_;
	};
}
#endif// CANDLE_H