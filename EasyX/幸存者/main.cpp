#include "graphics.h"

#include <cmath>

int main()
{
	initgraph(640, 480);

	bool running = true;
	ExMessage msg;

	IMAGE background, player;
	int player_x = 320, player_y = 240;
	int player_speed = 10;
	loadimage(&background, _T("img/background.png"));
	loadimage(&player, _T("img/paimon_left_0.png"));

	BeginBatchDraw();
	while (running)
	{
		DWORD start_time = GetTickCount();

		while (peekmessage(&msg))
		{
			// 移动方向
			int dx = 0, dy = 0;
			if (GetAsyncKeyState(VK_LEFT) & 0x8000) dx -= 1;
			if (GetAsyncKeyState(VK_RIGHT) & 0x8000) dx += 1;
			if (GetAsyncKeyState(VK_UP) & 0x8000) dy -= 1;
			if (GetAsyncKeyState(VK_DOWN) & 0x8000) dy += 1;

			// 如果有方向输入，归一化后乘速度
			if (dx != 0 || dy != 0)
			{
				float length = sqrt(dx * dx + dy * dy);
				player_x += static_cast<int>(player_speed * dx / length);
				player_y += static_cast<int>(player_speed * dy / length);
			}
		}
		cleardevice();
		putimage(0, 0, &background);
		putimage(player_x, player_y, &player);
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