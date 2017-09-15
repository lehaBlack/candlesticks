#ifndef VIEW_ARROW_H
#define VIEW_ARROW_H
#include "arrow.hpp"
#include "scale.hpp"

namespace drw{
	template<typename T>
	class VArrows :public Arrow < T >
	{
	public:
		VArrow(const Scale<T>& s) :{

		}
		void draw() const override(){

		}
	private:
		Scale<T> scale_;
	};

}

#endif //VIEW_ARROW_H