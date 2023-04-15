#include "lib/player_move3D.h"
#include "lib/var.h"
#include "lib/output_img.h"
#include "lib/initialization.h"
#include <iostream>
#include <string>
using namespace std;

extern int player_walk_cnt3D,bgX,bgY, inFight;
extern Human player;
extern char BgName[];
int speed = 3;
int fps = 25;
int table[] = {0,-1,0,1};

void itemwall(int xl, int xr, int yu, int yd) {
    if(bgX <= xl && bgX >= xr && bgY <= yu &bgY >= yd) {
        if(GetAsyncKeyState(0x41) || GetAsyncKeyState('a'))  bgX -= speed;
        if(GetAsyncKeyState(0x44) || GetAsyncKeyState('d'))  bgX += speed;
        if(GetAsyncKeyState(0x53) || GetAsyncKeyState('s'))  bgY += speed;
        if(GetAsyncKeyState(0x57) || GetAsyncKeyState('w'))  bgY -= speed;
    }
}

void keyListener() {
    if(GetAsyncKeyState(0x41) || GetAsyncKeyState('a'))  {
        player.output_idx = 29 + table[player_walk_cnt3D++/fps];
		bgX += speed;
        if (player_walk_cnt3D/fps==4) player_walk_cnt3D = 0; 
	}
    if(GetAsyncKeyState(0x44) || GetAsyncKeyState('d'))  {
        player.output_idx = 35 + table[player_walk_cnt3D++/fps];
		bgX -= speed;
        if (player_walk_cnt3D/fps==4) player_walk_cnt3D = 0; 
	}
    if(GetAsyncKeyState(0x53) || GetAsyncKeyState('s'))  {
        player.output_idx = 32 + table[player_walk_cnt3D++/fps];
		bgY -= speed;
        if (player_walk_cnt3D/fps==4) player_walk_cnt3D = 0; 
	}
    if(GetAsyncKeyState(0x57) || GetAsyncKeyState('w'))  {
        player.output_idx = 26 + table[player_walk_cnt3D++/fps];
		bgY += speed;
        if (player_walk_cnt3D/fps==4) player_walk_cnt3D = 0; 
	}
    //home2樓設定
    if (strcmp(BgName, "images\\bg\\home2.png")==0) {
        //地圖牆
        if(bgX  <-360) bgX = -360;
        if(bgX > 375) bgX = 375;
        if(bgY  <-192) bgY = -192;
        if(bgY > 285) bgY = 285;
        //物件牆
        itemwall(70,-59,175,-30);
        itemwall(370,13,285,250);
        itemwall(375,313,250,210);
        itemwall(370,211,98,-75);
        itemwall(-76,-219,285,153);
        itemwall(-76,-270,213,153);
        //背景轉換
        if(bgX == -222 && bgY >=213 && bgY <=285) {
            sprintf(BgName,"%s","images\\bg\\home1.png");
            loadBG(BgName,1587/2,1300/2); //讀取背景
        }
    }
    //home1樓設定
    if (strcmp(BgName, "images\\bg\\home1.png")==0) {
        //地圖牆
        if(bgX  <-360) bgX = -360;
        if(bgX > 375) bgX = 375;
        if(bgY  <-192) bgY = -192;
        if(bgY > 285) bgY = 285;
        //物件牆
        itemwall(-231,-360,225,192);
        itemwall(189,-360,-177,-220);
        itemwall(375,249,-177,-220);
        itemwall(375,165,285,264);
        itemwall(135,18,285,264);
        itemwall(132,-30,166,22);
        //背景轉換
        //上樓
        if(bgX == -273 && bgY >=213 && bgY <=285) {
            sprintf(BgName,"%s","images\\bg\\home2.png");
            loadBG(BgName,1587/2,1300/2);
        }
        //出門
        if(bgX > 189 && bgX < 249 && bgY == -192) {
            sprintf(BgName,"%s","images\\bg\\village.png");
            loadBG(BgName);
        }
    }
    cout << bgX << " " << bgY << "       \r";
}

