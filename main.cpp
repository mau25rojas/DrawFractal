// Name	: Fractal.cpp

#include <iostream>
#include "FractalCreator.h"
#include "RGB.h"

using namespace std;

int main() {

	FractalCreator fractalCreator(800, 600);
	
	fractalCreator.addRange(0.0, RGB(0, 0, 255));
	fractalCreator.addRange(0.05, RGB(255, 99, 71));
	fractalCreator.addRange(0.08, RGB(255, 215, 0));
	fractalCreator.addRange(1.0, RGB(255, 255, 255));

	fractalCreator.addZoom(Zoom(312, 218, 0.1));
	fractalCreator.addZoom(Zoom(400, 398, 0.1));

	fractalCreator.run("fractal1.bmp");

	cout << "finished" << endl;

	return 0;
}