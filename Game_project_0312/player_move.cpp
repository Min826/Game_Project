#include <ege.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <graphics.h> 
#define hih 480
#define wid 640
extern int k, left_walk_cnt, right_walk_cnt;
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



void move(int speed)
{
	if (kbhit()) 
		k = getch();
	switch (k)
	{
		case 97:
			if(player.dir != 'a')
			{
				player.output_idx = 1;
				player.dir = 'a';
			}
			else if(left_walk_cnt < 2)
			{
				player.output_idx = 2;
				left_walk_cnt++;
			}
			else if(left_walk_cnt < 4)
			{
				player.output_idx = 1;
				left_walk_cnt++;
			}
			else if(left_walk_cnt < 6)
			{
				player.output_idx = 4;
				left_walk_cnt++;
			}
			else if(left_walk_cnt == 6)
			{
				player.output_idx = 1;
				left_walk_cnt = 0;
			}
			
			player.x -= speed;
			
			break;
		case 100:
			if(player.dir != 'd')
			{
				player.output_idx = 0;
				player.dir = 'd';
			}
			else if(right_walk_cnt < 2)
			{
				player.output_idx = 3;
				right_walk_cnt++;
			}
			else if(right_walk_cnt < 4)
			{
				player.output_idx = 0;
				right_walk_cnt++;
			}
			else if(right_walk_cnt < 6)
			{
				player.output_idx = 5;
				right_walk_cnt++;
			}
			else if(right_walk_cnt == 6)
			{
				player.output_idx = 0;
				right_walk_cnt = 0;
			}
			player.x += speed;
			
			break;
		default:
			break;
	}
	k = 0;
}
