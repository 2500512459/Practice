#pragma once
#pragma comment(lib, "MSIMG32.LIB")
#include <iostream>
#include <graphics.h>
#include <vector>

class Animation
{
public:
	Animation(LPCSTR path, int num, int interval);
	~Animation();

	void Play(int x, int y, int delta);
	inline void putimage_alpha(int x, int y, IMAGE* img)
	{
		int w = img->getwidth();
		int h = img->getheight();
		AlphaBlend(GetImageHDC(NULL), x, y, w, h, GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA });
	}
private:
	int idx_frame = 0;
	int timer = 0;
	int interval_ms = 0;
	std::vector<IMAGE*> frame_list;
};

