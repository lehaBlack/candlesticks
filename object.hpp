#ifndef PAINT_OBJECT_H
#define PAINT_OBJECT_H
#include <windows.h>
#include <GL/gl.h>

namespace drw{
	namespace ogl{
		template<typename T>
		inline void vert(const T(&v)[2]);
	}

	template<typename T = float>
	class Object{
	public:
		inline T x() const{
			return center_[0];
		}
		inline void x(const T& p){
			center_[0] = p;
		}
		inline T y() const{
			return center_[1];
		}
		inline void y(const T& p){
			center_[1] = p;
		}
		inline const T* v() const{
			return center_;
		}
		inline T width() const{
			return width_;
		}
		inline void width(const T& p){
			width_ = p;
		}
		inline T height() const{
			return height_;
		}
		inline void height(const T& p){
			height_ = p;
		}
		//--------------------------------------------------
		inline virtual T maxX() const{
			return x();
		}
		inline virtual T minX() const{
			return x();
		}
		inline virtual T maxY() const{
			return y();
		}
		inline virtual T minY() const{
			return y();
		}

		inline virtual void re_scale(const T& x0, const T& dx, const T& y0, const T& dy) = 0;

		//--------------------------------------------------
		inline Object() :
			height_(T(0)),
			width_(T(0))
		{
			center_[0] = T(0);
			center_[1] = T(0);
		}
		inline Object(const T& x, const T& y, const T& width = T(1), const T& height = T(1)) :
			height_(width),
			width_(height)
		{
			center_[0] = x;
			center_[1] = y;
		}
		//-------------------------------------------------
		inline virtual void draw() const{
			ogl::vert(center_);
		}
	private:

		T center_[2];
		T height_;
		T width_;
	};
}
#endif //PAINT_OBJECT_H