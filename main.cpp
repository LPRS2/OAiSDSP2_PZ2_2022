
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

/*
const std::string aliceblue = "aliceblue"*/
namespace colors {
    const std::string aliceblue = "aliceblue";
    const std::string antiquewhite = "antiquewhite";
    const std::string aqua = "aqua";
    const std::string aquamarine = "aquamarine";
    const std::string azure = "azure";
    const std::string beige = "beige";
    const std::string bisqueblack = "bisqueblack";
    const std::string blanchedalmond = "blanchedalmond";
    const std::string blue = "blue";
    const std::string blueviolet = "blueviolet";
    const std::string brown = "brown";
    const std::string burlywood = "burlywood";
    const std::string cadetblue = "cadetblue";
    const std::string chartreuse = "chartreuse";
    const std::string chocolate = "chocolate";
    const std::string coral = "coral";
    const std::string cornflowerblue = "cornflowerblue";
    const std::string cornsilk = "cornsilk";
    const std::string crimson = "crimson";
    const std::string cyan = "cyan";
    const std::string darkblue = "darkblue";
    const std::string darkcyan = "darkcyan";
    const std::string darkgoldenrod = "darkgoldenrod";
    const std::string darkgray = "darkgray";
    const std::string darkgreen = "darkgreen";
    const std::string darkgrey = "darkgrey";
    const std::string darkkhaki = "darkkhaki";
    const std::string darkmagenta = "darkmagenta";
    const std::string darkolivegreen = "darkolivegreen";
    const std::string darkorange = "darkorange";
    const std::string darkorchid = "darkorchid";
    const std::string darkred = "darkred";
    const std::string darksalmon = "darksalmon";
    const std::string darkseagreen = "darkseagreen";
    const std::string darkslateblue = "darkslateblue";
    const std::string darkslategray = "darkslategray";
    const std::string darkslategrey = "darkslategrey";
    const std::string darkturquoise = "darkturquoise";
    const std::string darkviolet = "darkviolet";
    const std::string deeppink = "deeppink";
    const std::string deepskyblue = "deepskyblue";
    const std::string dimgray = "dimgray";
    const std::string dimgrey = "dimgrey";
    const std::string dodgerblue = "dodgerblue";
    const std::string firebrick = "firebrick";
    const std::string floralwhite = "floralwhite";
    const std::string forestgreen = "forestgreen";
    const std::string fuchsia = "fuchsia";
    const std::string gainsboro = "gainsboro";
    const std::string ghostwhite = "ghostwhite";
    const std::string gold = "gold";
    const std::string goldenrod = "goldenrod";
    const std::string gray = "gray";
    const std::string green = "green";
    const std::string greenyellow = "greenyellow";
    const std::string honeydew = "honeydew";
    const std::string hotpink = "hotpink";
    const std::string indianred = "indianred";
    const std::string indigo = "indigo";
    const std::string ivory = "ivory";
    const std::string khaki = "khaki";
    const std::string lavender = "lavender";
    const std::string lavenderblush = "lavenderblush";
    const std::string lawngreen = "lawngreen";
    const std::string lemonchiffon = "lemonchiffon";
    const std::string lightblue = "lightblue";
    const std::string lightcoral = "lightcoral";
    const std::string lightcyan = "lightcyan";
    const std::string lightgoldenrodyellow = "lightgoldenrodyellow";
    const std::string lightgray = "lightgray";
    const std::string lightgreen = "lightgreen";
    const std::string lightpink = "lightpink";
    const std::string lightsalmon = "lightsalmon";
    const std::string lightseagreen = "lightseagreen";
    const std::string lightskyblue = "lightskyblue";
    const std::string lightslategray = "lightslategray";
    const std::string lightslategrey = "lightslategrey";
    const std::string lightsteelblue = "lightsteelblue";
    const std::string lightyellow = "lightyellow";
    const std::string lime = "lime";
    const std::string limegreen = "limegreen";
    const std::string linen = "linen";
    const std::string magenta = "magenta";
    const std::string maroon = "maroon";
    const std::string mediumaquamarine = "mediumaquamarine";
    const std::string mediumblue = "mediumblue";
    const std::string mediumorchid = "mediumorchid";
    const std::string mediumpurple = "mediumpurple";
    const std::string mediumseagreen = "mediumseagreen";
    const std::string mediumslateblue = "mediumslateblue";
    const std::string mediumspringgreen = "mediumspringgreen";
    const std::string mediumturquoise = "mediumturquoise";
    const std::string mediumvioletred = "mediumvioletred";
    const std::string midnightblue = "midnightblue";
    const std::string mintcream = "mintcream";
    const std::string mistyrose = "mistyrose";
    const std::string moccasin = "moccasin";
    const std::string navajowhite = "navajowhite";
    const std::string navy = "navy";
    const std::string oldlace = "oldlace";
    const std::string olive = "olive";
    const std::string olivedrab = "olivedrab";
    const std::string orange = "orange";
    const std::string orangered = "orangered";
    const std::string orchid = "orchid";
    const std::string palegoldenrod = "palegoldenrod";
    const std::string palegreen = "palegreen";
    const std::string paleturquoise = "paleturquoise";
    const std::string palevioletred = "palevioletred";
    const std::string papayawhip = "papayawhip";
    const std::string peachpuff = "peachpuff";
    const std::string peru = "peru";
    const std::string pink = "pink";
    const std::string plum = "plum";
    const std::string powderblue = "powderblue";
    const std::string purple = "purple";
    const std::string red = "red";
    const std::string rosybrown = "rosybrown";
    const std::string royalblue = "royalblue";
    const std::string saddlebrown = "saddlebrown";
    const std::string salmon = "salmon";
    const std::string sandybrown = "sandybrown";
    const std::string seagreen = "seagreen";
    const std::string seashell = "seashell";
    const std::string sienna = "sienna";
    const std::string silver = "silver";
    const std::string skyblue = "skyblue";
    const std::string slateblue = "slateblue";
    const std::string slategray = "slategray";
    const std::string slategrey = "slategrey";
    const std::string snow = "snow";
    const std::string springgreen = "springgreen";
    const std::string steelblue = "steelblue";
    const std::string tan = "tan";
    const std::string teal = "teal";
    const std::string thistle = "thistle";
    const std::string tomato = "tomato";
    const std::string turquoise = "turquoise";
    const std::string violet = "violet";
    const std::string wheat = "wheat";
    const std::string white = "white";
    const std::string whitesmoke = "whitesmoke";
    const std::string yellow = "yellow";
    const std::string yellowgreen = "yellowgreen";
}

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
    std::vector<double> sinx;
    std::vector<double> siny;

    for (float i = 0; i < 100; i+=.01) {
        sinx.push_back(i);
        siny.push_back(5*sin(i));
    }

    PlotHelper plot1("test");   // partial path test
    
    // line formats in LineStyle enum
    // colors in colors namespace
    plot1.plot(sinx, siny, "test1", colors::red, LineStyle::impulse);
    plot1.plot(sinx, siny, "test2", colors::green, LineStyle::line);
    plot1.plot(sinx, siny, "test3", colors::gold, LineStyle::stepCenter);
    plot1.plot(sinx, siny, "test4", colors::cyan, LineStyle::stepRight);
   


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
