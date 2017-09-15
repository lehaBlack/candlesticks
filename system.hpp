#ifndef SYSTEM_H
#define SYSTEM_H

namespace drw{
	template<typename T>
	class System
	{
	public:
		T height() const;
		T width() const;
		T M_width() const;
		T m_width() const;
		T M_height() const;
		T m_height() const;

		T M_width(const T& w);
		T m_width(const T& w);
		T M_height(const T& h);
		T m_height(const T& h);
		inline System() :
			w_(T(0)),
			h_(T(0)),
			Mw_(T(0)),
			mw_(T(0)),
			Mh_(T(0)),
			mh_(T(0))
		{}
		inline System(
			const T& Mw, const T& mw,
			const T& Mh, const T& mh) :
			w_(Mw - mw),
			h_(Mh - mh),
			Mw_(Mw),
			mw_(mw),
			Mh_(Mh),
			mh_(mh)
		{}
		inline System(const System<T>& s) :
			w_(s.w_),
			h_(s.h_),
			Mw_(s.Mw_),
			mw_(s.mw_),
			Mh_(s.Mh_),
			mh_(s.mh_)
		{}
		inline System<T>& operator=(const System<T>& s){
			w_ = s.w_;
			h_ = s.h_;
			Mw_ = s.Mw_;
			mw_ = s.mw_;
			Mh_ = s.Mh_;
			mh_ = s.mh_;
			return *this;
		}
	private:
		T w_;
		T h_;

		T Mw_;
		T mw_;
		T Mh_;
		T mh_;
	};

	template<typename T> T System<T>::M_width(const T& w){ Mw_ = w; w_ = Mw_ - mw_; return w; }
	template<typename T> T System<T>::m_width(const T& w){ mw_ = w; w_ = Mw_ - mw_; return w; }
	template<typename T> T System<T>::M_height(const T& h){ Mh_ = h; h_ = Mh_ - mh_; return h; }
	template<typename T> T System<T>::m_height(const T& h){ mh_ = h; h_ = Mh_ - mh_; return h; }

	template<typename T> T System<T>::height() const { return h_; }
	template<typename T> T System<T>::width() const { return w_; }
	template<typename T> T System<T>::M_width() const { return Mw_; }
	template<typename T> T System<T>::m_width() const { return mw_; }
	template<typename T> T System<T>::M_height() const { return Mh_; }
	template<typename T> T System<T>::m_height() const { return mh_; }
}
#endif //SYSTEM_H