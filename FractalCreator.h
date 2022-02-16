#pragma once

#include<string>
#include<iostream>
#include <cstdint>
#include <vector>
#include <memory>
#include <math.h>
#include <vector>
#include "Bitmap.h"
#include "Mandelbrot.h"
#include "ZoomList.h"
#include "RGB.h"

using namespace std;

class FractalCreator{
private:
	int m_width{ 0 };
	int m_height{ 0 };
	unique_ptr<int[]> m_histogram;
	unique_ptr<int[]> m_fractal;
	ZoomList m_zoomList;
	Bitmap m_bitmap;
	int m_total{ 0 };

	vector<int> m_ranges;
	vector<RGB> m_colors;
	vector<int> m_rangeTotals;

	bool m_bGotFirstRange{ false };

	void calculateIteration();
	void calculateTotalIteration();
	void calculateRangeTotals();
	void drawFractal();
	void writeBitmap(string name);
	int getRange(int iterations) const;

public:
	FractalCreator(int width, int height);
	virtual ~FractalCreator();
	void addRange(double rangeEnd, const RGB& rgb);
	void addZoom(const Zoom& zoom);
	void run(string name);
};

