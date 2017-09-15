#ifndef WINDOW_H
#define WINDOW_H
#include "storage.hpp"
namespace drw{
	void init(int argc, char* argv[]);

	void plot(const Candles& state);
}
#endif//WINDOW_H