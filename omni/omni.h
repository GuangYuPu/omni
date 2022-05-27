#ifndef _OMNI_H__
#define _OMNI_H__

typedef struct WHEEL
{
	double o_pos_x; // 舵轮相对控制中心的 x 位置 (m)
	double o_pos_y; // 舵轮相对控制中心的 y 位置 (m)
	float speed;
} Wheel;

void Kine_Init(double distance_x, double distance_y, double o_offset_x, double o_offset_y);

void Kine_SetSpeed(double robot_vx, double robot_vy, double robot_rot);

extern Wheel wheel[4];
extern double r[4];

#endif