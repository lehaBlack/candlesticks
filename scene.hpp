#ifndef SCENE_H
#define SCENE_H
#include "view.hpp"

namespace drw{
	template <typename T>
	class Scene :
		public View < T >
	{
	public:
		inline void plot(const Candles& state){
			if (initialized_){
				Scale<T> copy(scale_);
				if (copy.configure(state)){
					copy.synchronize(storage_, scale_);
					scale_ = copy;
				}
			}
			else{
				scale_.rebuild(state);
				initialized_ = true;
			}

			for (const auto& candle : state) {
				storage_.add(new Candle<T>(
					scale_.scl_w((candle.finish + candle.start) * T(0.5)),
					scale_.proportion_w((candle.finish - candle.start) * WIDTH_RATIO),
					scale_.scl_h(candle.openValue),
					scale_.scl_h(candle.closeValue),
					scale_.scl_h(candle.maximum),
					scale_.scl_h(candle.minimum)
					));
			}

			storage_.add(new drw::Arrow<T>(scale_.real().m_width(), scale_.real().m_height(), scale_.real().M_width(), scale_.real().m_height()));
			storage_.add(new drw::Arrow<T>(scale_.real().m_width(), scale_.real().m_height(), scale_.real().m_width(), scale_.real().M_height()));
		}
	};
	extern Scene<Float> scene;
}
#endif //SCENE_H