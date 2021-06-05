#pragma once
#pragma comment(lib, "winmm.lib")

#include <Component/SimpleScene.h>
#include <string>
#include <Core/Engine.h>
#include <vector>
#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
#define length_shuriken (25.f)
#define arrow_partition (3.5f)
#define VITEZA_1 1
#define VITEZA_2 2
#define VITEZA_3 3
#define VITEZA_4 4
#define VITEZA_5 5
#define VITEZA_6 6
#define VITEZA_7 7
#define VITEZA_8 8
#define scaling_index (1.3f)
#define balloon_radius (40.f)
#define raza_arc (110.f)
#define no_lives 3
#define jumate_coada (40.f)
#define MAX_SPEED 800
#define speed_to_add 100
#define ratios 50
#define add_ratio 10
#define ratios (3.f)
#define diff_Interval (1.5f)











class Laborator3 : public SimpleScene
{
	public:
		Laborator3();
		~Laborator3();

		void Init() override;

		const float LIMIT = 0.5f;
		const float MOVE_RATIO = 0.10f;
		const float direction = 1.f;
		const float speed  = 500;

		const float x_speed = 120;
		const float x_speed_per_shuriken = 1.2;
		const float rotate_speed = 10;
		const float rotate_speed_per_shuriken = 1.3;
		const float PI4 = 0.78539816;
		const float PI = 3.14159;
		
		


	private:
		void FrameStart() override;
		void Update(float deltaTimeSeconds) override;
		void FrameEnd() override;

		void OnInputUpdate(float deltaTime, int mods) override;
		void OnKeyPress(int key, int mods) override;
		void OnKeyRelease(int key, int mods) override;
		void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
		void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
		void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
		void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
		void OnWindowResize(int width, int height) override;


		glm::mat3 modelMatrix;
		
		float translateX, translateY;
		float scaleX, scaleY;
		float angularStep;
		float cx, cy;
		float cx_sageata;
		float cy_sageata;
		float x_shuriken;
		float y_shuriken;
		float rotation = 0;
		float last_time4;
		float initial_x_sageata;
		float last_time11;


		bool ok;
		bool ok2;
		bool add_shuriken;
		bool add_balloon;
		bool small_difference;
		bool big_difference;
		bool on_press;
		bool on_release;
		bool on_move;
		bool before_release;
		bool game;
		bool up_down;
		bool press_button;
		bool sageata_end;
		bool afisare_patrate_bara;
		bool baloane_galben;
		bool chance;
		bool delete_red;
		bool delete_yellow;
		bool deleted_balloon;
		bool viata1;
		bool viata2;
		bool viata3;
		bool game_over;
		bool win_game;
		bool restart;
		bool add_special;
		bool ztrace;
		bool deleted_shuriken;
		bool balon_rosu;
		bool balon_galben;
		bool balon_special;
		bool limita_galben;
		bool limita_rosu;
		bool limita_special;






		double initial_time;
		double last_time;
		double last_time2;
		double last_time3;
		double last_time6;
		double diff_shuriken_times;
		double last_time10;


		float xPress;
		float yPress;
		float  last_bow;
		float initial_bow;
		float last_x;
		float squareSide;
		float last_angle;
		float balon_x;
		float balon_y;
		float last_time5;
		float unghi;
		float lungime_sageata;
		float added_distance_bow_ox;
		float initial_bow_distance;
		float add_shuriken_speed;
		float add_shuriken_rotate;
		float shuriken_appearance;
		float last_time8;
		float last_time9;
		float bow_diff;
			

};
