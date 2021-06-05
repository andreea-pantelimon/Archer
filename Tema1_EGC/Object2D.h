#pragma once

#include <string>

#include <include/glm.h>
#include <Core/GPU/Mesh.h>

namespace Object2D
{

	// Create square with given bottom left corner, length and color
	Mesh* CreateSquare(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false);
	Mesh* CreateArc(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false, bool no_fan = true);
	Mesh* CreateGura(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false, bool no_fan = true);
	Mesh* CreateGuraSuparat(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false, bool no_fan = true);
	Mesh* CreateCorp(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false, bool no_fan = true);
	Mesh* CreateCasca(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false, bool no_fan = true);
	Mesh* CreateTintaBalonSus(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false, bool no_fan = true);
	Mesh* CreateTintaBalonSus1(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false, bool no_fan = true);
	Mesh* CreatePicior1(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false, bool no_fan = true);
	Mesh* CreatePicior2(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false, bool no_fan = true);
	Mesh* CreateMana1(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false, bool no_fan = true);
	Mesh* CreateMana2(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false, bool no_fan = true);
	Mesh* CreateSageata(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false, bool no_fan = true);
	Mesh* CreateSageataVarf(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false, bool no_fan = true);
	Mesh* CreateShuriken(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false, bool no_fan = true);
	Mesh* CreateBalon(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false, bool no_fan = true);

	Mesh* CreateCap(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false, bool no_fan = true);

	Mesh* CreateOchi(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false, bool no_fan = true);
	Mesh* CreateCoadaBalon0(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false, bool no_fan = true);
	Mesh* CreateCoadaBalon(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false, bool no_fan = true);


	Mesh* CreateBara(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false, bool no_fan = true);
	Mesh* CreatePatratBara(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false, bool no_fan = true);



	Mesh* CreateViata(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false, bool no_fan = true);




}

