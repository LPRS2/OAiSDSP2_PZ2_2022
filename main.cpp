
#include "Enums.hpp"
#include <visualizer.hpp>

#include <iostream>
#include <cstdlib>
using namespace std;

#include <unistd.h>

#define DEBUG(x) do{ std::cout << #x << " = " << x << std::endl; }while(0)

#include "opencv2/opencv.hpp"


using namespace cv;

// TODO sube gde ovo da stavimo?
class PlotHelper {
public:
    PlotHelper(
        const std::string& path
    ) {
        curr_index = 0;
        this->path = path;
    }

    void plot(
        const std::vector<double>& xCoo,
        const std::vector<double>& yCoo,
        const std::string& legendTitle,
        const std::string& color,
        const int& style
    ) {
        visualizer::plot::plot(
            this->path,
            this->curr_index++,
            xCoo,
            yCoo,
            legendTitle,
            color, 
            style
        );
    }

private:
    unsigned int curr_index;
    std::string path;
};

enum LineStyle {
    none, 
    line,
    stepLeft,
    stepRight, 
    stepCenter, 
    impulse
};

int main() {
	Mat src = cv::imread("data/stop_sign.jpg");
	Mat src2 = cv::imread("data/1l.jpg");
	if(src.empty()){
		throw runtime_error("Cannot open image!");
	}

	visualizer::load_cfg("data/main.visualizer.yaml");

	const uint16_t width = 10;
	const uint16_t height = 20;
	static uint8_t pix[width*height*3];
	for(uint16_t y = 0; y < height; y++){
		for(uint16_t x = 0; x < width; x++){
			uint32_t i = (y*width + x)*3;
			// Red.
			pix[i+0] = 0;
			pix[i+1] = 0;
			pix[i+2] = 255;
		}
	}

	for(uint16_t y = 3; y < height-3; y++){
		for(uint16_t x = 3; x < width-3; x++){
			uint32_t i = (y*width + x)*3;
			// Blue.
			pix[i+0] = 255;
			pix[i+1] = 0;
			pix[i+2] = 0;
		}
	}

	visualizer::img::show(
		"src",
		pix,
		width,
		height
	);


	visualizer::img::show(
		"h",
		src
	);

	visualizer::img::show(
		"r",
		src2
	);

	std::cout << "Testing plot function" << std::endl;

	const std::vector<double> xAx = {0, 1, 2, 3, 4};
	const std::vector<double> yAx = {0, 1, 2, 3, 4};

    const std::vector<double> xAx2 = {3, 5, 7, 9, 11};
	const std::vector<double> yAx2 = {0, 1, 2, 3, 4};

    const std::vector<double> xAx3 = {0, 5, 10, 15, 20};
	const std::vector<double> yAx3 = {0, 1, 2, 3, 4};

    const std::vector<double> xAx4 = {0, 1, 2, 3, 4};
	const std::vector<double> yAx4 = {8, 12, 16, 20, 24};

    std::vector<double> sinx;
    std::vector<double> siny;

    for (int i = 0; i < 100; i++) {
        sinx.push_back(i);
        siny.push_back(sin(i));
    }

    PlotHelper plot1("test");
    
    // line formats: none, line, stepLeft, stepRight, stepCenter, impulse 0-5
    plot1.plot(sinx, siny, "test1", "red", LineStyle::impulse);
    plot1.plot(sinx, siny, "test2", "green", LineStyle::line);
    plot1.plot(sinx, siny, "test3", "blue", LineStyle::stepCenter);
    plot1.plot(sinx, siny, "test4", "cyan", LineStyle::stepRight);
   


	int th_start_h0;

	while(true){
		th_start_h0 = 20;
		visualizer::slider::slider(
			"/win0/upper_half/upper_rigth_corner/th_start_h0",
			th_start_h0,
			[&](int& value){
				DEBUG(th_start_h0);
			}
		);

		for(int i = 0; i < 3; i++){
			visualizer::slider::update();
			DEBUG(th_start_h0);
			sleep(1);
		}
	}

	return 0;
}
