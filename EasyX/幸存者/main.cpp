#pragma comment(lib, "MSIMG32.LIB")
#include <graphics.h>
#include <string>
#include "Animation.h"

const int WIN_LENGTH = 640;
const int WIN_WIDTH = 480;

int player_speed = 5;
const int PLAYER_ANIM_NUM = 6;

const int PLAYER_WIDTH = 80;
const int PLAYER_HEIGHT = 80;
const int SHADOW_WIDTH = 32;

POINT player_pos{ WIN_LENGTH / 2 - PLAYER_WIDTH / 2, WIN_WIDTH / 2 - PLAYER_HEIGHT  / 2};

Animation player_anim_left(_T("img/paimon_left_%d.png"), PLAYER_ANIM_NUM, 45);
Animation player_anim_right(_T("img/paimon_right_%d.png"), PLAYER_ANIM_NUM, 45);

IMAGE background, img_shadow;

inline void putimage_alpha(int x, int y, IMAGE* img)
{
	int w = img->getwidth();
	int h = img->getheight();
	AlphaBlend(GetImageHDC(NULL), x, y, w, h, GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA });
}

void DrawPlayer(int delta, int dir_x)
{
	int pos_shadow_x = player_pos.x + (PLAYER_WIDTH / 2 - SHADOW_WIDTH / 2);
	int pos_shadow_y = player_pos.y + PLAYER_HEIGHT - 8;
	putimage_alpha(pos_shadow_x, pos_shadow_y, &img_shadow);

	static bool face_left = false;
	if (dir_x < 0)
		face_left = true;
	else if (dir_x > 0)
		face_left = false;

	if (face_left)
		player_anim_left.Play(player_pos.x, player_pos.y, delta);
	else
		player_anim_right.Play(player_pos.x, player_pos.y, delta);
}


int main()
{
	initgraph(WIN_LENGTH, WIN_WIDTH);

	bool running = true;
	bool is_move_up = false;
	bool is_move_down = false;
	bool is_move_left = false;
	bool is_move_right = false;

	ExMessage msg;

	loadimage(&background, _T("img/background.png"));
	loadimage(&img_shadow, _T("img/shadow_player.png"));

	BeginBatchDraw();
	while (running)
	{
		DWORD start_time = GetTickCount();

		while (peekmessage(&msg))
		{
			if (msg.message == WM_KEYDOWN)
			{
				switch (msg.vkcode)
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
				switch (msg.vkcode)
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

		//if (is_move_up) player_pos.y -= player_speed;
		//if (is_move_down) player_pos.y += player_speed;
		//if (is_move_left) player_pos.x -= player_speed;
		//if (is_move_right) player_pos.x += player_speed;
		int dir_x = is_move_right - is_move_left;
        int dir_y = is_move_down - is_move_up;
		double norms  = sqrt(dir_x * dir_x + dir_y * dir_y);
		if (norms != 0)
		{
			double noms_x = dir_x / norms;
            double noms_y = dir_y / norms;
			player_pos.x += player_speed * noms_x;
            player_pos.y += player_speed * noms_y;
		}
		if(player_pos.x < 0) player_pos.x = 0;
        if(player_pos.x > WIN_LENGTH - PLAYER_WIDTH) player_pos.x = WIN_LENGTH - PLAYER_WIDTH;
        if(player_pos.y < 0) player_pos.y = 0;
        if(player_pos.y > WIN_WIDTH - PLAYER_HEIGHT) player_pos.y = WIN_WIDTH - PLAYER_HEIGHT;

		cleardevice();
		putimage(0, 0, &background);
		DrawPlayer(1000 / 144, is_move_right - is_move_left);
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