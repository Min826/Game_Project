#include <ege.h>
#include <stdio.h>
#include <graphics.h> 
#define hih 480
#define wid 640
extern PIMAGE ori_bg, player_origin_mask, player_origin_img, player_new_mask, player_new_img, new_bg;
struct human
{
	int x;
	int y;
	int hp;
};

void output_image(struct human *player)
{
	putimage(0, 0, new_bg);
	
	putimage(player->x, player->y, player_new_mask, NOTSRCERASE);
	putimage(player->x, player->y, player_new_img, SRCINVERT);
}