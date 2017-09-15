#include "storage.hpp"
#include "candle.hpp"
#include "scale.hpp"
#include "scene.hpp"
#include "ogl.hpp"
#include <thread>
#include <string.h>
namespace drw{

	drw::Scene<Float> scene;

	const char* menu = "some text";
	int len = strlen(menu);

	void printText(){
		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0, 1280, 0, 1024);

		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();
		glRasterPos2i(10, 1014);  // move in 10 pixels from the left and bottom edges
		for (int i = 0; i < len; ++i) {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, menu[i]);
		}
		glPopMatrix();

		glMatrixMode(GL_PROJECTION);
		glPopMatrix();
		glMatrixMode(GL_MODELVIEW);
	}

	float scaling(float dh, float absH){
		return 	WINDOW_Y_MINIMUM + absH * dh;
	}

	void setup() { glClearColor(1.0f, 1.0f, 1.0f, 1.0f); }


	void display()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		scene.draw();
		printText();
		glutSwapBuffers();

	}

	void keyboardFunc(unsigned char key, int x, int y){
		printf("keyboard %c %d %d %d\n", key, key, x, y);
	}

	void mouseFunc(int button, int state, int x, int y){
		printf("mouse %d %d %d %d\n", button, state, x, y);
	}

	void createWindow(int argc, char *argv[]){

		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
		glutInitWindowSize(800, 600);
		glutCreateWindow("Hello World");

		setup();
		glutDisplayFunc(display);
		glutKeyboardFunc(keyboardFunc);
		glutMouseFunc(mouseFunc);

		glutMainLoop();
	}

	void init(int argc, char *argv[])
	{
		std::thread windowMain(std::bind(createWindow, argc, argv));
		windowMain.detach();
	}


	void plot(const Candles& state){
		scene.plot(state);
	}
}