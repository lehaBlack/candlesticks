#ifndef PROCEDURES_H
#define PROCEDURES_H
#define _USE_MATH_DEFINES
#include <math.h>
#define SHORT_LINE_LENGTH 	(0.05f)
#define ALPHA 				(M_PI*0.1)


namespace drw{
	namespace arrow{
		template <typename T>
		T angle(const T& startX, const T& startY, const T& finishX, const T& finishY){
			T y = finishY - startY;
			T x = finishX - startX;

			if ((!(x > T(0))) && (!(x < T(0))))
				return y > 0 ? M_PI_2 : -M_PI_2;

			if ((!(y > T(0))) && (!(y < T(0))))
				return x > 0 ? T(0) : M_PI;

			return x > 0 ? atan(y / x) : -atan(y / x);
		}

		template <typename T>
		T pos_x(const T& startX, const T& startY, const T& finishX, const T& finishY, const T& alpha, const T& l){
			T a = angle(startX, startY, finishX, finishY);
			return finishX + l*cos(a + alpha);
		}
		template <typename T>
		T pos_y(const T& startX, const T& startY, const T& finishX, const T& finishY, const T& alpha, const T& l){
			T a = angle(finishX, finishY, startX, startY);
			return finishY + l*sin(a + alpha);
		}

		template <typename T>
		void pos(const T& startX, const T& startY, const T& finishX, const T& finishY, const T& alpha, const T& l, T(&res)[2]){
			T a = angle(finishX, finishY, startX, startY);
			res[0] = finishX + l*cos(a + alpha);
			res[1] = finishY + l*sin(a + alpha);
		}
	}

	namespace scale{
		template<typename T>
		void rescale(const T& s0_v, const T& s0_dv, const T& s0_v_,
			const T& s1_v, const T& s1_dv, const T& s1_v_,
			T& dv, T& v0)
		{
			dv = s1_dv / s0_dv;
			v0 = s1_v - s1_dv * (s0_v / s0_dv + s0_v_ - s1_v_);
		}
	}
}
#endif //PROCEDURES_H