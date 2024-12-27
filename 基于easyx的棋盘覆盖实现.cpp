#include <graphics.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#define MAX 128

int board[MAX][MAX];
int tile = 1;
int size = 8;
int gridSize = 80;
bool paused = false;

// 新增结构体用于记录每块棋盘的位置信息
typedef struct {
    int row;
    int col;
} BlockInfo;

// 动态数组用于存储块信息
BlockInfo* blockInfos = NULL;
int blockInfoCount = 0;

// 初始化棋盘
void InitBoard(int size, int grid) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if ((i + j) % 2 == 0) {
                setfillcolor(RGB(240, 240, 240));
            }
            else {
                setfillcolor(RGB(255, 255, 255));
            }
            solidrectangle(j * grid, i * grid, (j + 1) * grid, (i + 1) * grid);
        }
    }
}

// 绘制方格
void drawTile(int row, int col, int gridSize) {
    int x = col * gridSize;
    int y = row * gridSize;
    if (board[row][col]) {
        int color = RGB((board[row][col] * 50) % 256, (board[row][col] * 80) % 256, (board[row][col] * 120) % 256);
        setfillcolor(color);
    }
    else {
        setfillcolor(RGB(255, 255, 255));
    }
    solidrectangle(x, y, x + gridSize, y + gridSize);
}

// 覆盖棋盘
void coverBoard(int tr, int tc, int dr, int dc, int size) { 
    // 记录当前块的信息
    BlockInfo info = { tr, tc };
    blockInfos = (BlockInfo*)realloc(blockInfos, sizeof(BlockInfo) * (blockInfoCount + 1));
    blockInfos[blockInfoCount++] = info;
    if (size == 1) return;
    int t = tile++;
    int s = size / 2;

    // 覆盖左上角
    if (dr < tr + s && dc < tc + s) {
        coverBoard(tr, tc, dr, dc, s);
    }
    else {
        board[tr + s - 1][tc + s - 1] = t;
        drawTile(tr + s - 1, tc + s - 1, gridSize);
        Sleep(50);
        coverBoard(tr, tc, tr + s - 1, tc + s - 1, s);
    }

    // 覆盖右上角
    if (dr < tr + s && dc >= tc + s) {
        coverBoard(tr, tc + s, dr, dc, s);
    }
    else {
        board[tr + s - 1][tc + s] = t;
        drawTile(tr + s - 1, tc + s, gridSize);
        Sleep(50);
        coverBoard(tr, tc + s, tr + s - 1, tc + s, s);
    }

    // 覆盖左下角
    if (dr >= tr + s && dc < tc + s) {
        coverBoard(tr + s, tc, dr, dc, s);
    }
    else {
        board[tr + s][tc + s - 1] = t;
        drawTile(tr + s, tc + s - 1, gridSize);
        Sleep(50);
        coverBoard(tr + s, tc, tr + s, tc + s - 1, s);
    }

    // 覆盖右下角
    if (dr >= tr + s && dc >= tc + s) {
        coverBoard(tr + s, tc + s, dr, dc, s);
    }
    else {
        board[tr + s][tc + s] = t;
        drawTile(tr + s, tc + s, gridSize);
        Sleep(50);
        coverBoard(tr + s, tc + s, tr + s, tc + s, s);
    }
}

// 鼠标点击事件处理函数
void mouseClick() {
    int x, y;
    while (true) {
        if (MouseHit()) {
            MOUSEMSG msg = GetMouseMsg();
            if (msg.uMsg == WM_LBUTTONDOWN) {
                x = msg.x;
                y = msg.y;
                break;
            }
        }
    }
    int dr = y / gridSize;
    int dc = x / gridSize;

    // 初始化棋盘
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            board[i][j] = 0;
        }
    }
    // 覆盖棋盘
    coverBoard(0, 0, dr, dc, size);
}

// 根据记录的块信息重新覆盖棋盘为初始黑白模式
void resetBoard() {
    for (int i = blockInfoCount; i > 0; i--) {
         int c = blockInfos[i].col;
         int r = blockInfos[i].row;
                if ((r + c) % 2 == 0) {
                    setfillcolor(RGB(240, 240, 240));
                    solidrectangle(c * gridSize, r * gridSize, (c + 1) * gridSize, (r + 1) * gridSize);
                    Sleep(50);
                }
                else {
                    setfillcolor(RGB(255, 255, 255));
                    solidrectangle(c * gridSize, r * gridSize, (c + 1) * gridSize, (r + 1) * gridSize);
                    Sleep(50);
                }       
    }
}

int main() {
    initgraph(size * gridSize, size * gridSize);
    InitBoard(size, gridSize);
    while (true) {
        mouseClick();
        // 再次处理鼠标点击事件，重置棋盘
        while (true) {
            if (MouseHit()) {
                MOUSEMSG msg = GetMouseMsg();
                if (msg.uMsg == WM_LBUTTONDOWN) {
                    resetBoard();
                    break;
                }
            }
        }
    }
    getchar();
    closegraph();
    if (blockInfos != NULL) {
        free(blockInfos);
    }
    return 0;
}

