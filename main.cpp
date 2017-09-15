#include "scene.hpp"
#include "point.hpp"
//#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define DELTA 4
#define D_TIME 81


int randomV(int delta = DELTA){
	static int prev = (rand()%60);
	prev += (rand()%2>0?1:-1)*(rand()%delta);
	return prev;
}

int main(int argc, char *argv[])
  {
	int finish = randomV();
	int startTime =1000;
	drw::Candles condition;
	  
	drw::init(argc,argv);
	for(int i=0;i<10;i++)
	{
		drw::JCandle candle;
		int start = finish;
		int maximum = start;
		int minimum = start;
		for(int j=0;j<10;j++){
			finish = randomV();
			if(finish>maximum)
				maximum = finish;
			if(finish<minimum)
				minimum = finish;
		}
		candle.start = startTime;
		candle.finish = startTime + D_TIME;
		
		candle.openValue = start;
		candle.closeValue = finish;
		candle.minimum = minimum;
		candle.maximum = maximum;
		
		startTime += D_TIME;
		
		condition.push_back(candle);
	}
	drw::plot(condition);

	Sleep(10000);
	printf("finish\n");
	return 0;
  }
