#include "omni.h"
#include <math.h>

Wheel wheel[4] = {0};
double r[4] = {0};

void Kine_Init(double distance_x, double distance_y, double o_offset_x, double o_offset_y)
{
	// 计算各舵轮相对控制中心的位置
	wheel[0].o_pos_x = -(distance_x / 2 - o_offset_x);
	wheel[0].o_pos_y = distance_y / 2 - o_offset_y;
	wheel[1].o_pos_x = distance_x / 2 - o_offset_x;
	wheel[1].o_pos_y = distance_y / 2 - o_offset_y;
	wheel[2].o_pos_x = -(distance_x / 2 - o_offset_x);
	wheel[2].o_pos_y = -(distance_y / 2 - o_offset_y);
	wheel[3].o_pos_x = distance_x / 2 - o_offset_x;
	wheel[3].o_pos_y = -(distance_y / 2 - o_offset_y);

    for (int i = 0; i < 4; i++)
    {
        r[i] = sqrt(pow(wheel[i].o_pos_x,2)+pow(wheel[i].o_pos_y,2));
    }
}

void Kine_SetSpeed_0(Wheel *wheel,double robot_vx, double robot_vy, double robot_rot)
{
    wheel->speed = r[0]*robot_rot + sqrt(2)*robot_vy/2 - sqrt(2)*robot_vx/2;
}

void Kine_SetSpeed_1(Wheel *wheel,double robot_vx, double robot_vy, double robot_rot)
{
    wheel->speed = r[1]*robot_rot - sqrt(2)*robot_vy/2 - sqrt(2)*robot_vx/2;
}

void Kine_SetSpeed_2(Wheel *wheel,double robot_vx, double robot_vy, double robot_rot)
{
    wheel->speed = r[2]*robot_rot - sqrt(2)*robot_vy/2 + sqrt(2)*robot_vx/2;
}

void Kine_SetSpeed_3(Wheel *wheel,double robot_vx, double robot_vy, double robot_rot)
{
    wheel->speed = r[3]*robot_rot + sqrt(2)*robot_vy/2 + sqrt(2)*robot_vx/2;
}

void Kine_SetSpeed(double robot_vx, double robot_vy, double robot_rot)
{
    Kine_SetSpeed_0(&wheel[0],robot_vx,robot_vy,robot_rot);
    Kine_SetSpeed_1(&wheel[1],robot_vx,robot_vy,robot_rot);
    Kine_SetSpeed_2(&wheel[2],robot_vx,robot_vy,robot_rot);
    Kine_SetSpeed_3(&wheel[3],robot_vx,robot_vy,robot_rot);
}