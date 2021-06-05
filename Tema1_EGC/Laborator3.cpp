#include "Laborator3.h"

#include <GL/GLU.h>

#include <vector>
#include <iostream>

#include <Core/Engine.h>
#include "Transform2D.h"
#include "Object2D.h"
#include <time.h> 
#include <math.h>
#include <ctime>
#include <stdio.h> 



using namespace std;


int j = 0;
float viteza_sageata = 100;

float x_patrat_bara = 0;
float y_patrat_bara = 20;
int contor_viteza = 0;
int contor_patrate = 0;
int score = 0;
int nivel = 0;
float lives = 3;
float k = 0;
float borna_rosu = 0;
float borna_galben = 0;
float borna_special = 0;



char string1[] = "FIRE";


enum TYPE {
	balloon, shuriken_type, archery
};


class Shuriken {

public:
	float x;
	float y;
	float rotate;

	Shuriken(float x_point, float y_point, float rotate_point);


};


Shuriken::Shuriken(float x_point, float y_point, float rotate_point) {

			x = x_point;
			y = y_point;
			rotate = rotate_point;
	}



class BalonXY {

public:
	float x;
	float y;
	float rotate;
	static float interval_var;

	BalonXY(float x_point, float y_point, float rotate_point);


};

BalonXY::BalonXY(float x_point, float y_point, float rotate_point) {

	x = x_point;
	y = y_point;
	rotate = rotate_point;
}





class Balon {

public:
	float x;
	float y;
	float rotate;
	float interval_var;
	
	void addIntervalVar(float value) {

		interval_var = interval_var + value;
	}

	float getInterval() {
		return interval_var;
	}

	Balon(float x_point, float y_point, float rotate_pointr);


};



Balon::Balon(float x_point, float y_point, float rotate_point) {

	x = x_point;
	y = y_point;
	rotate = rotate_point;
	interval_var = 0;
}





static vector<Shuriken> shurikens;

static vector<Balon> balloons;

static vector<Balon> gold_balloons;

static vector<Balon> special_balloons;


static unordered_map<float, float> balloonsXY;


Laborator3::Laborator3()
{
}
Laborator3::~Laborator3()
{
}




bool checkCollision(float x_point , float y_point, float x_collision_point, float y_collision_point, TYPE type, float radius1, float rad1, float rad2) {


		if(type == balloon)
		{
		float distance = sqrt((x_point -  x_collision_point) * (x_point - x_collision_point) +
							(y_point - y_collision_point) * (y_point - y_collision_point));

	

			if(radius1 * scaling_index  > distance) {
				return true;
			}
			else
				return false;

		}

		if (type == shuriken_type)
		{
			float distance = sqrt((x_point - x_collision_point) * (x_point - x_collision_point) +
				(y_point - y_collision_point) * (y_point - y_collision_point));



			if (radius1 > distance) {
				return true;
			}
			else
				return false;

		}
		

		if (type == archery) {
			float k;
			k = rad1;

			while (k <= rad2) {
				float distance = sqrt(((x_point + radius1 * cos(k)) - x_collision_point) * ((x_point + radius1 * cos(k)) - x_collision_point) +
					((y_point + radius1 * sin(k)) - y_collision_point) * ((y_point + radius1 * sin(k)) - y_collision_point));

				if (sqrt(2) * length_shuriken > distance) {
					return true;
					
				}
				else false;

				k += 0.05;


			}


		}

}


void Laborator3::Init()
{
	glm::ivec2 resolution = window->GetResolution();
	auto camera = GetSceneCamera();
	camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
	camera->SetPosition(glm::vec3(0, 0, 50));
	camera->SetRotation(glm::vec3(0, 0, 0));
	camera->Update();
	GetCameraInput()->SetActive(false);

	glm::vec3 corner = glm::vec3(0, 0, 0);
	squareSide = 100;


	float dreptunghi_side = 400;

	// compute coordinates of square center

	float balon_x = 800;
	float balon_y = 1000;


	cx = 110;
	cy = resolution.y/2;
	initial_x_sageata = 110;

	cx_sageata = cx ;
	cy_sageata = cy;
	initial_bow = 110;
	last_bow = cy_sageata;
	lungime_sageata = (6 * squareSide) / arrow_partition + squareSide / (arrow_partition * 3);
	
	
	// initialize tx and ty (the translation steps)
	translateX = resolution.x;
	
	

	// initialize sx and sy (the scale factors)
	scaleX = 1;
	scaleY = 1;
	
	// initialize angularStep
	angularStep = 0;

	
	cout << resolution.x << endl;
	
	initial_time = 0;
	last_time = 0;
	last_time2 = 0;

	add_shuriken = true;
	game  = true;
	up_down  = true;
	small_difference = true;
	afisare_patrate_bara = true;
	viata1 = true;
	viata2 = true;
	viata3 = true;
	baloane_galben = true;
	game_over = false;
	add_special = true;
	add_balloon = true;
	win_game = false;
	restart = false;
	deleted_balloon = true;
	deleted_shuriken = true;
	sageata_end = false;
	on_press = false;
	big_difference = false;
	delete_yellow = false;
	on_move = false;
	before_release = false;
	baloane_galben = true;
	balon_rosu = true;
	balon_special = true;
	limita_rosu = true;
	limita_galben = true;
	limita_special = true;
	diff_shuriken_times = 0;
	shuriken_appearance = 0;
	



	Mesh* tinta = Object2D::CreateTintaBalonSus("tinta", corner, squareSide, glm::vec3(0, 0, 1));
	AddMeshToList(tinta);



	Mesh* gura_suparat = Object2D::CreateGuraSuparat("gura_suparat", corner, squareSide, glm::vec3(1, 1, 1));
	AddMeshToList(gura_suparat);

	Mesh* tinta2 = Object2D::CreateGuraSuparat("tinta2", corner, squareSide, glm::vec3(1, 1, 1));
	AddMeshToList(tinta2);

	Mesh* cap = Object2D::CreateCap("cap", corner, squareSide, glm::vec3(0, 1, 0));
	AddMeshToList(cap);

	Mesh* picior1 = Object2D::CreatePicior1("picior1", corner, squareSide, glm::vec3(1, 0, 0));
	AddMeshToList(picior1);

	Mesh* casca = Object2D::CreateCasca("casca", corner, squareSide, glm::vec3(1, 0, 0));
	AddMeshToList(casca);

	Mesh* mana1 = Object2D::CreatePicior1("mana1", corner, squareSide, glm::vec3(1, 0, 0));
	AddMeshToList(mana1);


	Mesh* picior2 = Object2D::CreatePicior2("picior2", corner, squareSide, glm::vec3(1, 0, 0));
	AddMeshToList(picior2);
	Mesh* gura = Object2D::CreateGura("gura", corner, squareSide, glm::vec3(1, 1, 1));
	AddMeshToList(gura);


	Mesh* corp = Object2D::CreateCorp("corp", corner, squareSide, glm::vec3(1, 0, 0));
	AddMeshToList(corp);


	Mesh* ochi = Object2D::CreateOchi("ochi", corner, squareSide, glm::vec3(1, 1, 1));
	AddMeshToList(ochi);
	
	Mesh* arc  =  Object2D::CreateArc("arc", corner, squareSide, glm::vec3(0, 1, 0));
	AddMeshToList(arc);

	Mesh* sageata  =  Object2D::CreateSageata("sageata", corner, squareSide, glm::vec3(1, 0, 0));
	AddMeshToList(sageata);
	Mesh* sageatavarf  =  Object2D::CreateSageataVarf("sageatavarf", corner, squareSide, glm::vec3(1, 0, 0));
	AddMeshToList(sageatavarf);

	Mesh* viata  =  Object2D::CreateViata("viata", corner, squareSide, glm::vec3(1, 0, 0));
	AddMeshToList(viata);



	Mesh* bara  =  Object2D::CreateBara("bara", corner, squareSide, glm::vec3(0.2, 0.75, 0.75));
	AddMeshToList(bara);


	Mesh* patrat  =  Object2D::CreatePatratBara("patrat", corner, squareSide, glm::vec3(0.2, 0.75, 0.75));
	AddMeshToList(patrat);


	
	Mesh* Balon  =  Object2D::CreateBalon("balon", corner, squareSide, glm::vec3(1, 0, 0));
	AddMeshToList(Balon);

	Mesh* Balon_Special = Object2D::CreateBalon("balon_special", corner, squareSide, glm::vec3(1, 1, 0));
	AddMeshToList(Balon_Special);
	Mesh* coadaspecial = Object2D::CreateCoadaBalon("coadabalonspecial", corner, squareSide, glm::vec3(1, 1, 0));
	AddMeshToList(coadaspecial);
	Mesh* coada0special = Object2D::CreateCoadaBalon0("coadabalonspecial0", corner, squareSide, glm::vec3(1, 1, 0));
	AddMeshToList(coada0special);



	Mesh* GoldBalloon  =  Object2D::CreateBalon("balongalben", corner, squareSide, glm::vec3(1, 1, 0));
	AddMeshToList(GoldBalloon);
	Mesh* coada0galben = Object2D::CreateCoadaBalon0("coadabalon0galben", corner, squareSide, glm::vec3(1,1, 0));
	AddMeshToList(coada0galben);


	Mesh* coadagalben = Object2D::CreateCoadaBalon("coadabalongalben", corner, squareSide, glm::vec3(1, 1, 0));
	AddMeshToList(coadagalben);

	Mesh* mana2 = Object2D::CreateMana2("mana2", corner, squareSide, glm::vec3(1, 0, 0));
	AddMeshToList(mana2);


	Mesh* coada = Object2D::CreateCoadaBalon("coadabalon", corner, squareSide, glm::vec3(0.7, 0.5, 0.34));
	AddMeshToList(coada);

	Mesh* coada0 = Object2D::CreateCoadaBalon0("coadabalon0", corner, squareSide, glm::vec3(0.7, 0.5, 0.34));
	AddMeshToList(coada0);



	Mesh* shuriken  =  Object2D::CreateShuriken("shuriken", corner, squareSide, glm::vec3(0, 0, 1));
	AddMeshToList(shuriken);
	

	Mesh* square2 = Object2D::CreateSquare("square2", corner, squareSide, glm::vec3(0, 1, 0));
	AddMeshToList(square2);

	Mesh* square3 = Object2D::CreateSquare("square3", corner, squareSide, glm::vec3(0, 0, 1));
	AddMeshToList(square3);
}

void Laborator3::FrameStart()
{
	// clears the color buffer (using the previously set color) and depth buffer
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::ivec2 resolution = window->GetResolution();
	// sets the screen area where to draw
	glViewport(0, 0, resolution.x, resolution.y);
}



void Laborator3::Update(float deltaTimeSeconds)
{
	// TODO: update steps for translation, rotation, scale, in order to create animations




	float diff_bows_y = cy - initial_bow;
	

	float y_diff = yPress + cy;


	
	if (restart == true) {

		add_balloon = true;
		baloane_galben = true;
		score = 0;
		add_shuriken = true;
		viata1 = true;
		viata2 = true;
		viata3 = true;
		add_special = true;
		lives = 3;
		nivel = 0;

		add_shuriken_speed = 0;
		add_shuriken_rotate = 0;
		shuriken_appearance = 0;
		restart = false;
	}

	
	glm::ivec2 resolution = window->GetResolution();



	//Viata 1

	if (viata1) {
		modelMatrix = glm::mat3(1);
		modelMatrix *= Transform2D::Translate(resolution.x - 40, resolution.y - 40);
		RenderMesh2D(meshes["viata"], shaders["VertexColor"], modelMatrix);
	}


	//Viata 2

	if (viata2) {
		modelMatrix = glm::mat3(1);
		modelMatrix *= Transform2D::Translate(resolution.x - 80, resolution.y - 40);
		RenderMesh2D(meshes["viata"], shaders["VertexColor"], modelMatrix);
	}




	//Viata 3
	if (viata3) {
		modelMatrix = glm::mat3(1);
		modelMatrix *= Transform2D::Translate(resolution.x - 120, resolution.y - 40);
		RenderMesh2D(meshes["viata"], shaders["VertexColor"], modelMatrix);
	}






	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(20, 20);
	RenderMesh2D(meshes["bara"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(cx , cy - balloon_radius);
	RenderMesh2D(meshes["picior1"], shaders["VertexColor"], modelMatrix);


	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(cx, cy);
	RenderMesh2D(meshes["mana1"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(cx, cy);
	modelMatrix *= Transform2D::Rotate((atan((resolution.y - y_diff) / xPress)));
	RenderMesh2D(meshes["mana2"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(cx -  30, cy + 160);
	RenderMesh2D(meshes["casca"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(cx, cy - balloon_radius);
	RenderMesh2D(meshes["picior2"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(cx + 20, cy + 130);
	modelMatrix *= Transform2D::Rotate((atan((resolution.y - y_diff) / xPress)));
	RenderMesh2D(meshes["ochi"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(cx , cy - balloon_radius);
	RenderMesh2D(meshes["corp"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(cx - 20, cy + 130);
	modelMatrix *= Transform2D::Rotate((atan((resolution.y - y_diff) / xPress)));
	RenderMesh2D(meshes["ochi"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= Transform2D::Translate(cx, cy + 130);
    RenderMesh2D(meshes["gura"], shaders["VertexColor"], modelMatrix);
	
	


	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(cx, cy + 120);
	modelMatrix *= Transform2D::Rotate((atan((resolution.y - y_diff) / xPress)));
	RenderMesh2D(meshes["cap"], shaders["VertexColor"], modelMatrix);


	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(cx, cy);
	modelMatrix *= Transform2D::Rotate((atan((resolution.y -y_diff ) / xPress)));
	RenderMesh2D(meshes["arc"], shaders["VertexColor"], modelMatrix);




	if (add_shuriken) {


		if (small_difference) {


			double diffTime = (2 + shuriken_appearance) * CLOCKS_PER_SEC;
			if (clock() - last_time > diffTime) {


				Shuriken shuriken(0, rand() % resolution.y + 1, 0);
				shurikens.emplace_back(shuriken);
				last_time = clock();
			}
		}

		if (!small_difference) {


			double diffTime = 2.5 * CLOCKS_PER_SEC;
			if (clock() - last_time > diffTime) {


				Shuriken shuriken(0, rand() % resolution.y + 1, 0);
				shurikens.emplace_back(shuriken);
				last_time = clock();
			}
		}

		
		

		for(auto &it = shurikens.begin();deleted_shuriken = true && it != shurikens.end();) {

			Shuriken shuriken = *it;
			modelMatrix = glm::mat3(1);
			
			modelMatrix *= Transform2D::Translate(resolution.x + 2 * squareSide, shuriken.y);
			shuriken.x = shuriken.x - (x_speed + add_shuriken_speed) * x_speed_per_shuriken * deltaTimeSeconds;
			shuriken.rotate = shuriken.rotate + (rotate_speed + add_shuriken_rotate) * rotate_speed_per_shuriken * deltaTimeSeconds;

			*it = shuriken;
			modelMatrix *= Transform2D::Translate(shuriken.x, 0);
			modelMatrix *= Transform2D::Rotate(shuriken.rotate);

			float dist = resolution.x + 2 * squareSide + shuriken.x;
			float start = 0;
			
			float start_to = -PI4 + atan((resolution.y - y_diff) / xPress);
			float end = PI4 + atan((resolution.y - y_diff) / xPress);


			float x_sageata = 0 + (lungime_sageata + (cx_sageata)) * cos(last_angle);

			float y_sageata = (cy_sageata + (lungime_sageata + (cx_sageata)) * sin(last_angle));


		 if (checkCollision(x_sageata, y_sageata, dist, shuriken.y, shuriken_type, sqrt(2) * length_shuriken, 0, 0)) {

			modelMatrix *= Transform2D::Scale(0.3, 0.3);
			it = shurikens.erase(it);


		 }
			
		    else if (checkCollision(start, cy, dist, shuriken.y, archery, raza_arc,  start_to, end)) {

			
				double diffTime6 = 1 * CLOCKS_PER_SEC;
				if (clock() - last_time8 > diffTime6) {
					lives--;
					
					last_time8 = clock();
					if (lives == no_lives - 1) {
						viata1 = false;
					}

					if (lives == no_lives - 2) {
						viata2 = false;
					}

				
					if (lives == no_lives - 3) {
						viata3 = false;
						game_over = true;

						cout << "GAME OVER !!!";

						restart = false;
					

						add_balloon = false;
						add_shuriken = false;
						baloane_galben = false;
						add_special = false;
					}
					
				}
				
			}

			else if (shuriken.x  <= -(resolution.x +  3 * squareSide)) {
				it = shurikens.erase(it);
				

			}
			else {
				it++;
			}

			RenderMesh2D(meshes["shuriken"], shaders["VertexColor"], modelMatrix);

			
		}

		
	}


	if (add_special) {


		if (small_difference) {


			double diffTime11 = 41 * CLOCKS_PER_SEC;
			if (clock() - last_time11 > diffTime11) {


				Balon balon(rand() % (resolution.x / 2) + (resolution.x / 2), 0, 0);
				special_balloons.emplace_back(balon);
				last_time11 = clock();
			}
		}

		if (!small_difference) {


			double diffTime11 = 41 * CLOCKS_PER_SEC;
			if (clock() - last_time11 > diffTime11) {


				Balon balon(rand() % (resolution.x / 2) + (resolution.x / 2), 0, 0);
				special_balloons.emplace_back(balon);
				last_time11 = clock();
			}
		}




		for (auto & it = special_balloons.begin();deleted_balloon == true && it != special_balloons.end();) {

			Balon balon = *it;
			modelMatrix = glm::mat3(1);
			modelMatrix *= Transform2D::Scale(1, scaling_index);




			balon.y = balon.y +  0.8 * x_speed * x_speed_per_shuriken * deltaTimeSeconds;

			modelMatrix *= Transform2D::Translate(balon.x, balon.y);





			// modelMatrix *= Transform2D::Translate(balon.x, balon.y);




			*it = balon;



			float x_sageata = 0 + (lungime_sageata + (cx_sageata)) * cos(last_angle);

			float y_sageata = (cy_sageata + (lungime_sageata + (cx_sageata)) * sin(last_angle));
			if (balon.y > resolution.y) {
				it = special_balloons.erase(it);

			}

			else if (checkCollision(x_sageata, y_sageata, balon.x, balon.y + 0.1 * x_speed * x_speed_per_shuriken * deltaTimeSeconds, balloon, balloon_radius, 0, 0)) {

				modelMatrix *= Transform2D::Scale(0.3, 0.3);
				it = special_balloons.erase(it);

				if (!game_over || !win_game) {

					score += 400;

					cout << "Scorul actual este " << score << endl;
					cout << "Nivelul actual este " << nivel << endl;
				}
			}
			else {
				it++;
			}

			if (balon.y >= resolution.y / 2 - 100) {

				RenderMesh2D(meshes["tinta"], shaders["VertexColor"], modelMatrix);



			}
			RenderMesh2D(meshes["viata"], shaders["VertexColor"], modelMatrix);
			RenderMesh2D(meshes["balon_special"], shaders["VertexColor"], modelMatrix);
			RenderMesh2D(meshes["coadabalonspecial"], shaders["VertexColor"], modelMatrix);
			RenderMesh2D(meshes["coadabalonspecial0"], shaders["VertexColor"], modelMatrix);

		}

	}
	

	if (add_balloon) {


			if (small_difference) {


				double diffTime2 = 8 * CLOCKS_PER_SEC;
				if (clock() - last_time2 > diffTime2) {


					Balon balon(rand() % (resolution.x / 2) + (resolution.x / 2) , 0, 0);
					balloons.emplace_back(balon);
					last_time2 = clock();
				}
			}

			if (!small_difference) {


				double diffTime2 = 20 * CLOCKS_PER_SEC;
				if (clock() - last_time2 > diffTime2) {


					Balon balon(rand() % (resolution.x / 2) +  (resolution.x / 2) - 300 , 0, 0);
					balloons.emplace_back(balon);
					last_time2 = clock();
				}
			}

			


			for (auto & it = balloons.begin();deleted_balloon == true && it != balloons.end();) {

				Balon balon = *it;
				modelMatrix = glm::mat3(1);
				modelMatrix *= Transform2D::Scale(1, scaling_index);


				balon.y = balon.y + 0.1 * x_speed * x_speed_per_shuriken * deltaTimeSeconds;

				

				

				 
				modelMatrix *= Transform2D::Translate(balon.x, balon.y);
				
				
				
				// modelMatrix *= Transform2D::Translate(balon.x, balon.y);
				
				
				

				*it = balon;

				
				
				float x_sageata = 0 + (lungime_sageata + (cx_sageata)) * cos(last_angle);

				float y_sageata = (cy_sageata + (lungime_sageata + (cx_sageata)) * sin(last_angle));
				if (balon.y > resolution.y) {
					it = balloons.erase(it);

				}

				else if(checkCollision(x_sageata, y_sageata, balon.x, balon.y + 0.1 * x_speed * x_speed_per_shuriken * deltaTimeSeconds, balloon, balloon_radius, 0, 0)) {

					modelMatrix *= Transform2D::Scale(0.3, 0.3);
					it = balloons.erase(it);		
					
					if (!game_over || !win_game) {

						score += 200;
					
						cout << "Scorul actual este " << score << endl;
						cout << "Nivelul actual este " << nivel << endl;
					}
				}
				else {
					it++;
				}

				if (balon.y >= resolution.y / 2 - 100) {

					RenderMesh2D(meshes["tinta"], shaders["VertexColor"], modelMatrix);
					
				

				}
				RenderMesh2D(meshes["balon"], shaders["VertexColor"], modelMatrix);
				RenderMesh2D(meshes["coadabalon"], shaders["VertexColor"], modelMatrix);
				RenderMesh2D(meshes["coadabalon0"], shaders["VertexColor"], modelMatrix);
				
			}
			
		}


		if (baloane_galben) {


			if (small_difference) {


				double diffTime5 = 21 * CLOCKS_PER_SEC;
				if (clock() - last_time5 > diffTime5) {


					Balon balon(rand() % (resolution.x / 2) + (resolution.x / 2) - 2 * squareSide, 0, 0);
					gold_balloons.emplace_back(balon);
					last_time5 = clock();
				}
			}

			if (!small_difference) {


				double diffTime5 = 30 * CLOCKS_PER_SEC;
				if (clock() - last_time5 > diffTime5) {


					Balon balon(rand() % (resolution.x / 2) +  (resolution.x / 2) - 2 * squareSide, 0, 0);
					gold_balloons.emplace_back(balon);
					last_time5 = clock();
				}
			}

			


			for (auto &it = gold_balloons.begin();deleted_balloon == true && it != gold_balloons.end();) {

				Balon balon = *it;
				modelMatrix = glm::mat3(1);
				modelMatrix *= Transform2D::Scale(1, scaling_index);
				
			
				balon.y = balon.y + 0.1 * x_speed * x_speed_per_shuriken * deltaTimeSeconds;
				
			
				
		
				if (limita_rosu && balon_rosu) {

					balon.addIntervalVar((ratios - diff_Interval) * deltaTimeSeconds);
					balon.x = balon.x + balon.getInterval();
					if (balon.getInterval() >= (ratios - diff_Interval)) {
						limita_rosu = false;
					}

				}
				if (!limita_rosu && balon_rosu) {
					balon.addIntervalVar(-(ratios - diff_Interval) * deltaTimeSeconds);
					balon.x = balon.x + balon.getInterval();
					if (balon.getInterval() <= -(ratios - diff_Interval)) {
						limita_rosu = true;
					}


				}

				modelMatrix *= Transform2D::Translate(balon.x, balon.y);

				*it = balon;
				float x_sageata = 0 + (lungime_sageata + (cx_sageata)) * cos(last_angle);

				float y_sageata = (cy_sageata + (lungime_sageata + (cx_sageata)) * sin(last_angle));
				if (balon.y > resolution.y) {
					it = gold_balloons.erase(it);

				}
				else if (checkCollision(x_sageata, y_sageata, balon.x, balon.y + 0.1 * x_speed * x_speed_per_shuriken * deltaTimeSeconds, balloon, balloon_radius, 0, 0)) {

					modelMatrix *= Transform2D::Scale(0.3, 0.3);
					it = gold_balloons.erase(it);


					if (!game_over || !win_game) {
						score += 200;

						cout << "Scorul actual este " << score << endl;
						cout << "Nivelul actual este " << nivel << endl;
					}
				}
				else {
					it++;
				}
				
				if (balon.y >= resolution.y / 2 - 100) {

					RenderMesh2D(meshes["tinta"], shaders["VertexColor"], modelMatrix);


				}

				RenderMesh2D(meshes["balongalben"], shaders["VertexColor"], modelMatrix);
				RenderMesh2D(meshes["coadabalongalben"], shaders["VertexColor"], modelMatrix);
				RenderMesh2D(meshes["coadabalon0galben"], shaders["VertexColor"], modelMatrix);

				

			}
			
		}


	if(press_button && !sageata_end) {

				double diffTime3 = 0.10 * CLOCKS_PER_SEC;

	     		if (clock() - last_time3 > diffTime3) {

	     		if(viteza_sageata <= MAX_SPEED ) {


	     			last_time3 = clock();

					viteza_sageata += speed_to_add;

	     		    contor_viteza++;
	          		

      				}
				
         }


	}

		if(contor_viteza >= VITEZA_1) {
		modelMatrix = glm::mat3(1);
		 modelMatrix *= Transform2D::Translate(20, y_patrat_bara);
		 RenderMesh2D(meshes["patrat"], shaders["VertexColor"], modelMatrix);
		}
		if(contor_viteza >= VITEZA_2) {
		 modelMatrix = glm::mat3(1);
		 modelMatrix *= Transform2D::Translate(40, y_patrat_bara);
		 RenderMesh2D(meshes["patrat"], shaders["VertexColor"], modelMatrix);
		}
		if(contor_viteza >= VITEZA_3) {
		modelMatrix = glm::mat3(1);
		 modelMatrix *= Transform2D::Translate(60, y_patrat_bara);
		 RenderMesh2D(meshes["patrat"], shaders["VertexColor"], modelMatrix);
		}
		if(contor_viteza >= VITEZA_4) {
		modelMatrix = glm::mat3(1);
		 modelMatrix *= Transform2D::Translate(80, y_patrat_bara);
		 RenderMesh2D(meshes["patrat"], shaders["VertexColor"], modelMatrix);
		}
		if(contor_viteza >= VITEZA_5) {
		modelMatrix = glm::mat3(1);
		 modelMatrix *= Transform2D::Translate(100, y_patrat_bara);
		 RenderMesh2D(meshes["patrat"], shaders["VertexColor"], modelMatrix);
		}
		if(contor_viteza >= VITEZA_6) {
		modelMatrix = glm::mat3(1);
		 modelMatrix *= Transform2D::Translate(120, y_patrat_bara);
		 RenderMesh2D(meshes["patrat"], shaders["VertexColor"], modelMatrix);
		}
		if(contor_viteza >= VITEZA_7) {
		modelMatrix = glm::mat3(1);
		 modelMatrix *= Transform2D::Translate(140, y_patrat_bara);
		 RenderMesh2D(meshes["patrat"], shaders["VertexColor"], modelMatrix);
		}
		if(contor_viteza >= VITEZA_8) {
		modelMatrix = glm::mat3(1);
		 modelMatrix *= Transform2D::Translate(160, y_patrat_bara);
		 RenderMesh2D(meshes["patrat"], shaders["VertexColor"], modelMatrix);
		}






		modelMatrix = glm::mat3(1);
		modelMatrix *= Transform2D::Translate(cx_sageata, cy_sageata);
	
	

		bow_diff = yPress + cy_sageata;
	
	if(before_release == false) {


	last_angle = atan((resolution.y - bow_diff) / xPress);
	modelMatrix *= Transform2D::Rotate(last_angle);

	

	}
	

if(on_release) {

		press_button = false;
		before_release = true;
		contor_viteza = 0;
		x_patrat_bara = 0;
		sageata_end = true;
		contor_patrate = 0;
		afisare_patrate_bara = false;
		chance = true;


		

		modelMatrix *= Transform2D::Rotate(last_angle);
		

		cx_sageata += viteza_sageata * deltaTimeSeconds;

		modelMatrix *= Transform2D::Translate(cx_sageata, 0);

	

		if (score >= 1200 && score <= 1600) {
			nivel = 1;
			add_shuriken_speed = 100;
			add_shuriken_rotate = 10;
			shuriken_appearance = -0.25;
		}

		if (score >= 1600 && score <= 2000) {
			nivel = 2;
			add_shuriken_speed = 200;
			add_shuriken_rotate = 15;
			shuriken_appearance = -0.5;
		}

		if (score >=2000 && score <= 3200) {
			nivel = 3;
			add_shuriken_speed = 400;
			add_shuriken_rotate = 20;
			shuriken_appearance = -0.5;
		}

		if (score > 3200) {
			nivel = 3;
			add_shuriken_speed = 600;
			add_shuriken_rotate = 25;
			shuriken_appearance = -0.75;
		}

		if (score >= 4000) {

			cout << "You win !!!"<<endl;
			win_game = true;
			add_shuriken = false;
			add_balloon = false;
			baloane_galben = false;
			restart = false;
			add_special = false;
		}
		
		up_down = false;

		
if(cx_sageata  > resolution.x  || cy_sageata > resolution.y  ) {

		sageata_end = false;
	 	
	 	
		cx_sageata = cx;
	 	cy_sageata = cy;
	 	modelMatrix *= Transform2D::Translate(cx_sageata, cy_sageata);
	 	
	 	on_release = false;
	 	before_release = false;
	 	on_release = false;
	 	up_down = true;
		deleted_balloon = true;
	 	viteza_sageata = 100;
	 	afisare_patrate_bara = true;
		
	
	 	
	  }

	}


	RenderMesh2D(meshes["sageata"], shaders["VertexColor"], modelMatrix);
	RenderMesh2D(meshes["sageatavarf"], shaders["VertexColor"], modelMatrix);

	



}



void Laborator3::FrameEnd()
{

}

void Laborator3::OnInputUpdate(float deltaTime, int mods)
{


	if (!window->MouseHold(GLFW_MOUSE_BUTTON_RIGHT)) {

	  if (window->KeyHold(GLFW_KEY_W) )
		{
			cy += deltaTime * speed;
			
			
		}

		 if (window->KeyHold(GLFW_KEY_W) && up_down)
		{
			
			cy_sageata += deltaTime * speed;
			
		}
		if (window->KeyHold(GLFW_KEY_S) )

		{
			cy -= deltaTime * speed;
			
		}

		if (window->KeyHold(GLFW_KEY_S) && up_down)

		{
			
			cy_sageata -= deltaTime * speed;
		
		}

	}
	
	
}

void Laborator3::OnKeyPress(int key, int mods)
{
	if (window->KeyHold(GLFW_KEY_R) && game_over == true)
	{
		restart = true;
	}

}

void Laborator3::OnKeyRelease(int key, int mods)
{
	
}

void Laborator3::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{	
	on_move  = true;
	xPress = mouseX;
	yPress = mouseY;
}

void Laborator3::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{

	press_button = true;
	
	
}

void Laborator3::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button release event
	on_release = true;
	//PlaySound(TEXT("arrow-hit.wav"), NULL, SND_FILENAME | SND_ASYNC);
	
}

void Laborator3::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}

void Laborator3::OnWindowResize(int width, int height)
{
}
