#include <ege.h>
#include <stdio.h>
#include <graphics.h> 
#define hih 480
#define wid 640
extern PIMAGE ori_bg, new_bg;
extern int left_walk_cnt, right_walk_cnt;
extern struct human
{
	int x;
	int y;
	int hp;
	char dir;
	int output_idx;
	PIMAGE player_origin_img[6], player_origin_mask[6];
	PIMAGE player_new_img[6], player_new_mask[6];
}player;
void loading();

void initialization()
{
	for(int i = 0; i < 6; i++)
	{
		player.player_origin_img[i] = newimage();
		player.player_origin_mask[i] = newimage();
		
		player.player_new_img[i] = newimage(32, 52);
		player.player_new_mask[i] = newimage(32, 52);
	}
	
	loading();
	player.x = wid / 2;
	player.y = hih / 2;
	player.hp = 5;
	player.dir = 'd';
	player.output_idx = 0;
	
	left_walk_cnt = 0;
	right_walk_cnt = 0;
}

void loading()
{
	getimage(ori_bg, "images\\back_ground_01.png");
	
	getimage(player.player_origin_mask[0], "images\\0_d_dir_stand_mask.png");
	getimage(player.player_origin_img[0], "images\\0_d_dir_stand_img.png");
	
	getimage(player.player_origin_mask[1], "images\\1_a_dir_stand_mask.png");
	getimage(player.player_origin_img[1], "images\\1_a_dir_stand_img.png");
	
	getimage(player.player_origin_mask[2], "images\\2_a_dir_walk_1_mask.png");
	getimage(player.player_origin_img[2], "images\\2_a_dir_walk_1_img.png");
	
	getimage(player.player_origin_mask[3], "images\\3_d_dir_walk_1_mask.png");
	getimage(player.player_origin_img[3], "images\\3_d_dir_walk_1_img.png");
	
	getimage(player.player_origin_mask[4], "images\\4_a_dir_walk_2_mask.png");
	getimage(player.player_origin_img[4], "images\\4_a_dir_walk_2_img.png");
	
	getimage(player.player_origin_mask[5], "images\\5_d_dir_walk_2_mask.png");
	getimage(player.player_origin_img[5], "images\\5_d_dir_walk_2_img.png");
	
	putimage(new_bg, 0, 0, wid, hih, ori_bg, 0, 0, 1000, 740);
	
	for(int i = 0; i < 6; i++)
	{	
		putimage(player.player_new_mask[i], 0, 0, 32, 52, player.player_origin_mask[i], 0, 0, 16, 26);
		putimage(player.player_new_img[i], 0, 0, 32, 52, player.player_origin_img[i], 0, 0, 16, 26);
	}
}
