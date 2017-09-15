#ifndef VIEW_H
#define VIEW_H
#include "scale.hpp"
#include "storage.hpp"
#include "arrow.hpp"

namespace drw{
	template <typename T>
	class View {
	public:
		inline virtual void add(Object<T>* o){
			if (initialized_){
				Scale<T> copy(scale_);
				if (copy.configure(*o)){
					copy.synchronize(storage_, scale_);
					scale_ = copy;
				}
			}
			else{
				scale_.rebuild(*o);
				initialized_ = true;
			}
			storage_.add(o);
		}
		inline Storage<T> &scene(){
			return storage_;
		}
		inline virtual void draw(){
			storage_.draw();
		}

		inline void clear(){
			storage_.clear();
		}

		inline View() :
			initialized_(false),
			scale_(),
			storage_()
		{}
	protected:
		bool initialized_;
		Scale<T> scale_;
		Storage<T> storage_;
	};

}
#endif//VIEW_H