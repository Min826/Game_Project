#include "lib/var.h"
#include "lib/player_atk.h"
#include "lib/enemy_give_dmg.h"

extern int key, atk_cnt, player_walk_cnt, flag, enemy_atk_cnt, enemy_atk_type, player_enemy_dir, atked, enemy_num;
extern double start, end;
extern Human player;
extern Monster enemy[2];

//���a�����ĤH
void atk_enemy(Monster &e, int power, int damage, char dir){
	if(is_middle(e.x + e.width * 0.98, player.x + player.width, e.x + e.width * 0.02))
	{
		e.hp -= damage;
		e.x += (dir == 'd' ? power : -power);// �ĤH�|�Q���a���h 
		player.atked = 1;// �Y���y���ˮ`�h�|�O�� �קK�@���������h���ˮ` 
	}
}

// ���a���� 
void player_atk(int val)
{	
	switch(enemy_num)
	{
		case 0:
			atk_enemy(enemy[0], player.power, player.damage, player.dir);
			break;
		default :
			break;
	}
}
