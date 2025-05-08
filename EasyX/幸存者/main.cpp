#include <graphics.h>
#include <string>
#pragma comment(lib, "MSIMG32.LIB")

int idx_anim = 0;
int palyer_speed = 5;
const int plyer_nums = 6;
IMAGE img_player_right[plyer_nums];
IMAGE img_player_left[plyer_nums];

POINT player_pos{ 310, 230 };

inline void load_images()
{
	for (size_t i = 0; i < plyer_nums; i++)
	{
		std::wstring path = L"img/paimon_right_" + std::to_wstring(i) + L".png";
		loadimage(&img_player_right[i], path.c_str());
	}
	for (size_t i = 0; i < plyer_nums; i++)
	{
		std::wstring path = L"img/paimon_left_" + std::to_wstring(i) + L".png";
		loadimage(&img_player_left[i], path.c_str());
	}
}

// 改变图片透明度
inline void putimage_alpha(int x, int y, IMAGE* img)
{
	int w = img->getwidth();
	int h = img->getheight();
	AlphaBlend(GetImageHDC(NULL), x, y, w, h, GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA });
}

int main()
{
	initgraph(640, 480);

	bool running = true;
	bool is_move_up = false;
	bool is_move_down = false;
	bool is_move_left = false;
	bool is_move_right = false;

	ExMessage msg;

	IMAGE background;
	loadimage(&background, _T("img/background.png"));

	load_images();
	BeginBatchDraw();
	while (running)
	{
		DWORD start_time = GetTickCount();

		while (peekmessage(&msg))
		{
			if (msg.message == WM_KEYDOWN)
			{
				switch (msg.wParam)
				{
				case VK_UP:
					is_move_up = true;
					break;
				case VK_DOWN:
					is_move_down = true;
					break;
				case VK_LEFT:
					is_move_left = true;
					break;
				case VK_RIGHT:
					is_move_right = true;
				}
			}
			if (msg.message == WM_KEYUP)
			{
				switch (msg.wParam)
				{
				case VK_UP:
					is_move_up = false;
					break;
				case VK_DOWN:
					is_move_down = false;
					break;
				case VK_LEFT:
					is_move_left = false;
					break;
				case VK_RIGHT:
					is_move_right = false;
					break;
				}
			}
		}

		if (is_move_up) player_pos.y -= palyer_speed;
		if (is_move_down) player_pos.y += palyer_speed;
		if (is_move_left) player_pos.x -= palyer_speed;
		if (is_move_right) player_pos.x += palyer_speed;

		static int count = 0;
		if (++count % 5 == 0)
			++idx_anim;
		idx_anim = idx_anim % plyer_nums;

		cleardevice();
		putimage(0, 0, &background);
		putimage_alpha(player_pos.x, player_pos.y, &img_player_right[idx_anim]);
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