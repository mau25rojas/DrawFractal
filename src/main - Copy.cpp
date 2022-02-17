// // Name	: Fractal.cpp

// #include <iostream>
// #include <cstdint>
// #include <vector>
// #include <memory>
// #include <math.h>
// #include "Bitmap.h"
// #include "Mandelbrot.h"
// #include "ZoomList.h"
// #include "FractalCreator.h"

// using namespace std;

// int main() {

// 	int const WIDTH = 800;
// 	int const HEIGHT = 600;

// 	Bitmap bitmap(WIDTH, HEIGHT);

// 	double min = 999999;
// 	double max = -999999;

// 	ZoomList zoomList(WIDTH, HEIGHT);

// 	zoomList.add(Zoom(WIDTH / 2, HEIGHT / 2, 4.0 / HEIGHT));
// 	zoomList.add(Zoom(312, HEIGHT - 218, 0.1));
// 	zoomList.add(Zoom(395, HEIGHT - 392, 0.1));

// 	unique_ptr<int[]> histogram(new int[Mandelbrot::MAX_ITERATIONS]{ 0 });
// 	int temp = WIDTH * HEIGHT;
// 	unique_ptr<int[]> fractal(new int[temp]{ 0 });

// 	for (int y = 0; y < HEIGHT; y++) {
// 		for (int x = 0; x < WIDTH; x++) {
// 			pair<double, double> coords = zoomList.doZoom(x, y);

// 			int	iterations = Mandelbrot::getIterations(coords.first, coords.second);

// 			fractal[y * WIDTH + x] = iterations;

// 			if (iterations != Mandelbrot::MAX_ITERATIONS) {
// 				histogram[iterations]++;
// 			}
// 		}
// 	}

// 	int total = 0;
// 	for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
// 		total += histogram[i];
// 	}
// 	for (int y = 0; y < HEIGHT; y++) {
// 		for (int x = 0; x < WIDTH; x++) {

// 			uint8_t red = 0;
// 			uint8_t green = 0;
// 			uint8_t blue = 0;
			
// 			int iterations = fractal[y * WIDTH + x];

// 			if (iterations != Mandelbrot::MAX_ITERATIONS) {

// 				uint8_t color = (uint8_t)(256 * (double)iterations / Mandelbrot::MAX_ITERATIONS);

// 				double hue = 0.0;
// 				for (int i = 0; i <= iterations; i++) {
// 					hue += ((double)histogram[i]) / total;
// 				}
// 				green = pow(255, hue);
// 			}
			

// 			bitmap.setPixel(x, y, red, green, blue);
// 		}
// 	}

// 	//cout << min << ", " << max << endl;

// 	bitmap.write("test.bmp");

// 	cout << "finished" << endl;

// 	return 0;
// }