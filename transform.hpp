#ifndef TRANSFORM_H
#define TRANSFORM_H

namespace drw{
	template <typename T>
	class Transform{
	public:
		inline virtual void operator() (T& object){}
	};
}
#endif