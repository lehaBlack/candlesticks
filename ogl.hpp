#ifndef OGL_H
#define OGL_H

#include <windows.h>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "object.hpp"

namespace drw{
	namespace ogl{
		namespace gl{
			template<typename T>
			inline void vertex2v(const T* v){
				glVertex2fv(v);
			}
			template<typename T>
			inline void vertex2(const T& x, const T& y){
				glVertex2f(x, y);
			}

			template<>
			inline void vertex2v<double>(const double* v){
				glVertex2dv(v);
			}

			template<>
			inline void vertex2v<float>(const float* v){
				glVertex2fv(v);
			}


			template<>
			inline void vertex2<double>(const double& x, const double& y){
				glVertex2d(x, y);
			}

			template<>
			inline void vertex2<float>(const float& x, const float& y){
				glVertex2f(x, y);
			}

			template<typename T>
			inline void vertex(const Object<T>& p){
				glVertex2v(p.v());
			}
			//**
			template<typename T>
			inline void color3v(const T* v){
				glColor3fv(v);
			}

			template<typename T>
			inline void color3(const T& r, const T& g, const T& b){
				glColor3f(r, g, b);
			}

			template<>
			inline void color3v<double>(const double* v){
				glColor3dv(v);
			}

			template<>
			inline void color3v<float>(const float* v){
				glColor3fv(v);
			}

			template<>
			inline void color3<double>(const double& r, const double& g, const double& b){
				glColor3d(r, g, b);
			}

			template<>
			inline void color3<float>(const float& r, const float& g, const float& b){
				glColor3f(r, g, b);
			}

		}

		template <typename T>
		inline void vert(const T(&v)[2]){
			gl::vertex2v(v);
		}

		template <typename T>
		inline void vert(const T& a0, const T& a1){
			gl::vertex2(a0, a1);
		}

		template <typename T>
		inline void vert(const Object<T>& p){
			gl::vertex2v(p.v());
		}

		template <typename T>
		inline void color(const T(&c)[3]){
			gl::color3v(v);
		}
		template <typename T>
		inline void color(const T& r, const T& g, const T& b){
			gl::color3(r, g, b);
		}

		namespace begin{
			inline void lines(){
				glBegin(GL_LINES);
			}

			inline void quads(){
				glBegin(GL_QUADS);
			}
		}

		void end(){
			glEnd();
		}
	}
}

#endif //OGL_H