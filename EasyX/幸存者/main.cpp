#include <graphics.h>
#include <string>

int idx_anim = 0;
const int plyer_nums = 6;
IMAGE img_player_right[plyer_nums];
IMAGE img_player_left[plyer_nums];

void load_images()
{
	for (int i = 0; i < plyer_nums; i++)
	{
		std::wstring path = L"img/paimon_right_" + std::to_wstring(i) + L".png";
        loadimage(&img_player_right[i], path.c_str());
	}
    for (int i = 0; i < plyer_nums; i++)
	{
		std::wstring path = L"img/paimon_left_" + std::to_wstring(i) + L".png";
        loadimage(&img_player_left[i], path.c_str());
	}
}
#pragma comment(lib, "MSIMG32.LIB")
inline void putimage_alpha(int x, int y, IMAGE* img)
{
	int w  = img->getwidth();
    int h  = img->getheight();
    AlphaBlend(GetImageHDC(NULL), x, y, w, h, GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA });
}

int main()
{
	initgraph(640, 480);

	bool running = true;
	ExMessage msg;

	IMAGE background;
    loadimage(&background, L"img/background.png");

	load_images();
	BeginBatchDraw();
	while (running)
	{
		DWORD start_time = GetTickCount();

		while (peekmessage(&msg))
		{

		}

		static int count = 0;
		if (++count % 5 == 0)
			++idx_anim;
		idx_anim = idx_anim % plyer_nums;

		cleardevice();
		putimage(0, 0, &background);
		putimage_alpha(320, 240, &img_player_right[idx_anim]);
		FlushBatchDraw();

		DWORD end_time = GetTickCount();
		DWORD delet_time = end_time - start_time;
		if (delet_time < 1000 / 60)
		{
			Sleep(1000 / 60 - delet_time);
		}
	}
	EndBatchDraw();
}