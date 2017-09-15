#ifndef STORAGE_H
#define STORAGE_H
#include "object.hpp"
#include "j_candle.hpp"
#include "window.hpp"
#include "transform.hpp"
#include <vector>
#include <mutex>

namespace drw{
	template <typename T>
	class Storage
	{
	public:
		void draw();
		void add(Object<T>* object);
		const std::vector<Object<T>*> objects();
		void clear(); 
		void transform(Transform<Object<T>* >&transform);
	private:
		std::mutex mutex_;
		std::vector<Object<T>*> objects_;
	};

	template <typename T>
	inline void Storage<T>::draw(){
		std::lock_guard<std::mutex> lock(mutex_);
		for (const auto & o : objects_){
			o->draw();
		}
	}
	template <typename T>
	inline void Storage<T>::add(Object<T>* object){
		std::lock_guard<std::mutex> lock(mutex_);
		objects_.push_back(object);
	}
	template <typename T>
	inline const std::vector<Object<T>*> Storage<T>::objects(){
		return objects_;
	}
	template <typename T>
	inline void Storage<T>::clear(){
		std::lock_guard<std::mutex> lock(mutex_);
		for (Object<T>* o : objects_){
			delete o;
		}
		objects_.clear();
	}

	template <typename T>
	inline void Storage<T>::transform(Transform<Object<T>* >&transform){
		std::lock_guard<std::mutex> lock(mutex_);
		for (Object<T>* o : objects_){
			transform(o);
		}
	}
}
#endif //STORAGE_H
