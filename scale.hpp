#ifndef SCALE_H
#define SCALE_H
#include "candle.hpp"
#include "storage.hpp"
#include "j_candle.hpp"
#include "s_transform.hpp"
#include "system.hpp"

#define WINDOW_X_MINIMUM (-0.75f)
#define WINDOW_X_MAXIMUM ( 0.75f)
#define WINDOW_Y_MINIMUM (-0.75f)
#define WINDOW_Y_MAXIMUM ( 0.75f)
#define WIDTH_RATIO      (0.8f)

namespace drw{
	template<typename T>
	class Scale{
	public:
		inline const System<T>& absolute() const;
		inline const System<T>& real() const;
	public:
		inline System<T>& absolute();
		inline System<T>& real();
	public:
		inline T scl_h(const T& absValue) const;
		inline T scl_w(const T& absValue) const;

		inline T proportion_h(const T& absValue) const;
		inline T proportion_w(const T& absValue) const;

		inline bool configure(const Candles& candles);
		inline bool configure(const Object<T>& object);
		inline void synchronize(Storage<T>& objects, const Scale<T>& scale);
		inline void rebuild(const Candles& candles);
		inline void rebuild(const Object<T>& object);
	public:
		inline Scale() :
			abs_(WINDOW_X_MAXIMUM, WINDOW_X_MINIMUM, WINDOW_Y_MAXIMUM, WINDOW_Y_MINIMUM),
			real_(WINDOW_X_MAXIMUM, WINDOW_X_MINIMUM, WINDOW_Y_MAXIMUM, WINDOW_Y_MINIMUM),
			scaleWidth_(T(1)),
			scaleHeight_(T(1))
		{}

		inline Scale(const Scale<T>& s) :
			abs_(s.abs_),
			real_(s.real_),
			scaleWidth_(s.scaleWidth_),
			scaleHeight_(s.scaleHeight_)
		{}
		inline const Scale<T>& operator= (const Scale<T>& s){
			abs_ = s.abs_;
			real_ = s.real_;
			scaleWidth_ = s.scaleWidth_;
			scaleHeight_ = s.scaleHeight_;
			return *this;
		}
	private:
		System<T> abs_;
		System<T> real_;

		T scaleWidth_;
		T scaleHeight_;
	};

	template<typename T>
	inline System<T>& Scale<T>::absolute(){ return abs_; }
	
	template<typename T>
	inline System<T>& Scale<T>::real(){ return real_; }

	template<typename T>
	inline const System<T>& Scale<T>::absolute() const { return abs_; }

	template<typename T>
	inline const System<T>& Scale<T>::real() const { return real_; }
	
	template<typename T>
	inline T Scale<T>::scl_w(const T& absValue) const{
		return real().m_width() + (absValue - absolute().m_width()) * scaleWidth_;
	}

	template<typename T>
	inline T Scale<T>::scl_h(const T& absValue) const{
		return real().m_height() + (absValue - absolute().m_height()) * scaleHeight_;
	}
	template<typename T>
	inline T Scale<T>::proportion_h(const T& absValue) const{ return absValue * scaleHeight_; }
	template<typename T>
	inline T Scale<T>::proportion_w(const T& absValue) const{ return absValue * scaleWidth_; }

	template<typename T>
	void Scale<T>::rebuild(const Candles& state){
		if (state.empty())
			return;

		absolute().m_width(state[0].start);
		absolute().M_width(state[0].finish);
		absolute().m_height(state[0].minimum);
		absolute().M_height(state[0].maximum);

		configure(state);
	}

	template<typename T>
	void Scale<T>::rebuild(const Object<T>& object){
		absolute().m_width(object.minX());
		absolute().M_width(object.maxX());
		absolute().m_height(object.minY());
		absolute().M_height(object.maxY());
	}

	template<typename T>
	bool Scale<T>::configure(const Candles& state){
		if (state.empty())
			return false;

		bool resize = false;

		for (const auto& candle : state){
			if (absolute().M_height() < candle.maximum){
				absolute().M_height(candle.maximum);
				resize = true;
			}

			if (absolute().m_height() > candle.minimum){
				absolute().m_height(candle.minimum);
				resize = true;
			}

			if (absolute().m_width() > candle.start){
				absolute().m_width(candle.start);
				resize = true;
			}

			if (absolute().M_width() < candle.finish){
				absolute().M_width(candle.finish);
				resize = true;
			}
		}
		if (resize){
			scaleWidth_ = real().width() / absolute().width();
			scaleHeight_ = real().height() / absolute().height();
		}
		return resize;
	}

	template<typename T>
	inline bool Scale<T>::configure(const Object<T>& object){
		bool resize = false;

		if (absolute().M_height() < object.maxY()){
			absolute().M_height(object.maxY());
			resize = true;
		}

		if (absolute().m_height() > object.minY()){
			absolute().m_height(object.minY());
			resize = true;
		}

		if (absolute().m_width() > object.maxX()){
			absolute().m_width(object.maxX());
			resize = true;
		}

		if (absolute().M_width() < object.minX()){
			absolute().M_width(object.minX());
			resize = true;
		}
		if (resize) {
			scaleWidth_ = real().width() / absolute().width();
			scaleHeight_ = real().height() / absolute().height();
		}
		return resize;
	}
	template<typename T>
	inline void Scale<T>::synchronize(Storage<T>& objects, const Scale<T>& scale){
		T dw, w0;
		T dh, h0;

		scale::rescale(
			scale.real().m_width(), scale.absolute().m_width(), scale.scaleWidth_,
			this->real().m_width(), this->absolute().m_width(), this->scaleWidth_,
			dw, w0);
		scale::rescale(
			scale.real().m_height(), scale.absolute().m_height(), scale.scaleHeight_,
			this->real().m_height(), this->absolute().m_height(), this->scaleHeight_,
			dh, h0);
		STransform<T> transform(w0, dw, h0, dh);
		objects.transform(transform);
	}
}
#endif //SCALE_H