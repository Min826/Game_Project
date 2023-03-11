#include <ege.h>
#include <stdio.h>
#include <graphics.h> 
#define hih 480
#define wid 640
extern PIMAGE ori_bg, new_bg;
extern PIMAGE player_origin_mask, player_origin_img;
extern PIMAGE player_new_mask, player_new_img;
struct human
{
	int x;
	int y;
	int hp;
};
void loading();

void initialization(struct human *player)
{
	loading();
	player->x = wid / 2;
	player->y = hih / 2;
	player->hp = 5;
}

void loading()
{
	getimage(ori_bg, "images\\back_ground_01.png");
	getimage(player_origin_mask, "images\\main_mask.png");
	getimage(player_origin_img, "images\\main.png");

	putimage(new_bg, 0, 0, wid, hih, ori_bg, 0, 0, 1000, 740);
	putimage(player_new_mask, 0, 0, 28, 52, player_origin_mask, 0, 0, 14, 26);
	putimage(player_new_img, 0, 0, 28, 52, player_origin_img, 0, 0, 14, 26);
}