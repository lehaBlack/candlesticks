#ifndef JAPANISE_CANDLE_H
#define JAPANISE_CANDLE_H
#include <vector>

namespace drw{
	using Float = float;
	using TimeType = int;


	struct JCandle
	{
		TimeType start;
		TimeType finish;
		Float maximum;
		Float minimum;
		Float openValue;
		Float closeValue;
	};


	using Candles = std::vector < JCandle >;
}
#endif//JAPANISE_CANDLE_H