#include <graphics.h>		// 引用 EasyX 绘图库头文件
#include <conio.h>

char board_data[3][3] = {
	{ '-', '-', '-' },
	{ '-', '-', '-' },
	{ '-', '-', '-' }
};
char current_piece = 'O';

// 检测获胜
bool checkWin(char c)
{
	if(board_data[0][0] == c && board_data[0][1] == c && board_data[0][2] == c)
		return true;
	if(board_data[1][0] == c && board_data[1][1] == c && board_data[1][2] == c)
		return true;
	if(board_data[2][0] == c && board_data[2][1] == c && board_data[2][2] == c)
		return true;
	if(board_data[0][0] == c && board_data[1][0] == c && board_data[2][0] == c)
		return true;
	if(board_data[0][1] == c && board_data[1][1] == c && board_data[2][1] == c)
		return true;
	if(board_data[0][2] == c && board_data[1][2] == c && board_data[2][2] == c)
		return true;
	if(board_data[0][0] == c && board_data[1][1] == c && board_data[2][2] == c)
		return true;
	if(board_data[0][2] == c && board_data[1][1] == c && board_data[2][0] == c)
		return true;
	return false;
}
// 检测平局
bool checkDraw()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board_data[i][j] == '-')
				return false;
		}
	}

	return true;
}
// 绘制棋盘
void drawBoard()
{
	line(0, 200, 600, 200);
	line(200, 0, 200, 600);
	line(400, 0, 400, 600);
	line(0, 400, 600, 400);
}
// 绘制棋子
void drawPiece()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{

			switch (board_data[i][j])
			{
				case  'O':
					circle(j * 200 + 100, i * 200 + 100, 100);
					break;
				case 'X':
					line(j * 200, i * 200, j * 200 + 200, i * 200 + 200);
					line(j * 200 + 200, i * 200, j * 200, i * 200 + 200);
					break;
				case  '-':
					break;
			}
		}
	}

}

int main()
{
	initgraph(600, 600);
	bool running = true;

	BeginBatchDraw();
	while (running)
	{
		DWORD start_time = GetTickCount();
		//数据处理
		ExMessage msg;
		while (peekmessage(&msg))
		{
			if (msg.message == WM_LBUTTONDOWN) {  // 改为单击事件
				int x = msg.x;
				int y = msg.y;
				int col = x / 200;  // 计算列
				int row = y / 200;  // 计算行

				if (row >= 0 && row < 3 && col >= 0 && col < 3) {  // 添加边界检查
					if (board_data[row][col] == '-') {  // 修正索引顺序
						board_data[row][col] = current_piece;
						current_piece = (current_piece == 'O') ? 'X' : 'O';  // 简化切换逻辑
					}
				}
			}
		}

		//绘制模块
		cleardevice();
		drawBoard();
		drawPiece();
		FlushBatchDraw();

		//胜负判断
		if (checkWin('O'))
		{
			MessageBox(GetHWnd(), _T("O获胜"), _T("游戏结束"), MB_OK);
			running = false;
		}
		else if (checkWin('X'))
		{
			MessageBox(GetHWnd(), _T("X获胜"), _T("游戏结束"), MB_OK);
			running = false;
		}
		else if (checkDraw())
		{
			MessageBox(GetHWnd(), _T("平局"), _T("游戏结束"), MB_OK);
			running = false;
		}

		DWORD end_time = GetTickCount();
		DWORD delet_time = end_time - start_time;
		if (delet_time < 1000 / 60)
		{
			Sleep(1000 / 60 - delet_time);
		}

	}
	EndBatchDraw();
	return 0;
}