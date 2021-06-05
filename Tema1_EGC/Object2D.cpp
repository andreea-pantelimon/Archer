#include "Object2D.h"


#include <Core/Engine.h>

using namespace std;

Mesh* Object2D::CreateSquare(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill)
{
	glm::vec3 corner = leftBottomCorner;

	std::vector<VertexFormat> vertices =
	{
		VertexFormat(corner, color),
		VertexFormat(corner + glm::vec3(length, 0, 0), color),
		VertexFormat(corner + glm::vec3(length, length, 0), color),
		VertexFormat(corner + glm::vec3(0, length, 0), color)
	};

	Mesh* square = new Mesh(name);
	std::vector<unsigned short> indices = { 0, 1, 2, 3 };
	
	if (!fill) {
		square->SetDrawMode(GL_LINE_LOOP);
	}
	else {
		// draw 2 triangles. Add the remaining 2 indices
		indices.push_back(0);
		indices.push_back(2);
	}

	square->InitFromData(vertices, indices);
	return square;
}

Mesh* Object2D::CreateArc(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill, bool no_fan)
{
	glm::vec3 corner = leftBottomCorner;

	


	float doublePi = 6.28318530718;

	float arg;
	int r = 110;

	Mesh*  arc =  new Mesh(name);
	
	vector<VertexFormat> vertices;

	float cosinus_angle;
	float sinus_angle;
	
	int i = 0;
	while(i <= 70) {

		cosinus_angle = r *  cos((-doublePi/ 8) + i * (doublePi /4 / 70));
		sinus_angle = r *  sin(((-doublePi/ 8) + i * (doublePi / 4/ 70)));
		vertices.emplace_back(VertexFormat(glm::vec3(cosinus_angle , sinus_angle, 0), color));

		i++;

	}

	vector<unsigned short> indices ;

	int j = 0;
	if(no_fan) {
	while(j < 70) {

		indices.emplace_back(j);
		indices.emplace_back(j);

		j++;
	}
	}
	
	indices.emplace_back(70);
	arc->SetDrawMode(GL_LINE_LOOP);


	arc->InitFromData(vertices, indices);
	return arc;
}


Mesh* Object2D::CreateGura(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill, bool no_fan)
{
	glm::vec3 corner = leftBottomCorner;




	float doublePi = 6.28318530718;

	float arg;
	int r = 40;

	Mesh*  arc = new Mesh(name);

	vector<VertexFormat> vertices;

	float cosinus_angle;
	float sinus_angle;

	int i = 0;
	while (i <= 70) {

		cosinus_angle = r * cos((-doublePi / 2.7) + i * (doublePi / 4 / 70));
		sinus_angle = r * sin(((-doublePi / 2.7) + i * (doublePi / 4 / 70)));
		vertices.emplace_back(VertexFormat(glm::vec3(cosinus_angle, sinus_angle, 0), color));

		i++;

	}

	vector<unsigned short> indices;

	int j = 0;
	if (no_fan) {
		while (j < 70) {

			indices.emplace_back(j);
			indices.emplace_back(j);

			j++;
		}
	}

	indices.emplace_back(70);
	arc->SetDrawMode(GL_TRIANGLE_FAN);


	arc->InitFromData(vertices, indices);
	return arc;
}


Mesh* Object2D::CreateGuraSuparat(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill, bool no_fan)
{


	glm::vec3 corner = leftBottomCorner;

	Mesh* Patrat = new Mesh(name);

	length = 20;

	vector<VertexFormat> vertices;


	vertices.emplace_back(VertexFormat(glm::vec3(length, 0, 0), color));
	vertices.emplace_back(VertexFormat(glm::vec3(length + length, 0, 0), color));
	vertices.emplace_back(VertexFormat(glm::vec3(length  +length + length, 0, 0), color));



	vector<unsigned short> indices;

	indices.emplace_back(0);
	indices.emplace_back(1);
	indices.emplace_back(2);




	Patrat->SetDrawMode(GL_LINE_LOOP);
	Patrat->InitFromData(vertices, indices);

	return Patrat;
	
}


Mesh* Object2D::CreateSageata(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill, bool no_fan)
{


	glm::vec3 corner = leftBottomCorner;

	length /= 3.5;

	vector<VertexFormat> vertices =
	{
		VertexFormat(glm::vec3(0,0,0), color), //0
		VertexFormat(corner + glm::vec3(length, 0, 0), color), // 1
		VertexFormat(corner + glm::vec3(length + length, 0, 0), color), // 2
		VertexFormat(corner + glm::vec3(length + length + length + length + length, 0, 0), color), // 3 
	
	
	};

	Mesh* Sageata  = new Mesh(name);
	std::vector<unsigned short> indices = { 0, 1, 2 , 
											3};
	if (!fill) {
		Sageata->SetDrawMode(GL_LINE_LOOP);
	}
	else {
		// draw 2 triangles. Add the remaining 2 indices
		indices.push_back(0);
		indices.push_back(2);
	}

	Sageata->InitFromData(vertices, indices);
	return Sageata;
	
}





Mesh* Object2D::CreateSageataVarf(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill, bool no_fan)
{


	glm::vec3 corner = leftBottomCorner;

	length /= 3.5;

	vector<VertexFormat> vertices =
	{
		VertexFormat( glm::vec3(length + length + length + length + length, 0, 0), color), // 3
		VertexFormat( glm::vec3(length + length + length + length + length, length / 2, 0), color), // 4
		VertexFormat(glm::vec3(length + length + length + length + +length + length+ length /3, 0, 0), color), // 5
		VertexFormat(glm::vec3(length + length + length + length + length, - (length / 2), 0), color) // 6
	
	};

	Mesh* SageataVarf  = new Mesh(name);
	std::vector<unsigned short> indices = {0, 1, 2, 
											3, 0};
	
	
	SageataVarf->SetDrawMode(GL_TRIANGLE_FAN);									
	SageataVarf->InitFromData(vertices, indices);
	return SageataVarf;
	
}

Mesh* Object2D::CreateCorp(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill, bool no_fan)
{


	Mesh* Corp = new Mesh(name);

	length = 40;

	vector<VertexFormat> vertices;


	vertices.emplace_back(VertexFormat(glm::vec3(0, 0, 0), color));
	vertices.emplace_back(VertexFormat(glm::vec3(0, length, 0), color));
	vertices.emplace_back(VertexFormat(glm::vec3(0, length + length, 0), color));
	vertices.emplace_back(VertexFormat(glm::vec3(0, length + length + length, 0), color));






	vector<unsigned short> indices;

	indices.emplace_back(0);
	indices.emplace_back(1);
	indices.emplace_back(2);
	indices.emplace_back(3);




	Corp->SetDrawMode(GL_LINE_LOOP);
	Corp->InitFromData(vertices, indices);

	return Corp;




}

Mesh* Object2D::CreatePicior1(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill, bool no_fan)
{


	Mesh* Corp = new Mesh(name);

	length = 40;

	vector<VertexFormat> vertices;


	vertices.emplace_back(VertexFormat(glm::vec3(0, 0, 0), color));
	vertices.emplace_back(VertexFormat(glm::vec3(-length, -length - length, 0), color));






	vector<unsigned short> indices;

	indices.emplace_back(0);
	indices.emplace_back(1);




	Corp->SetDrawMode(GL_LINE_LOOP);
	Corp->InitFromData(vertices, indices);

	return Corp;

}


Mesh* Object2D::CreatePicior2(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill, bool no_fan)
{


	Mesh* Corp = new Mesh(name);

	length = 40;

	vector<VertexFormat> vertices;


	vertices.emplace_back(VertexFormat(glm::vec3(0, 0, 0), color));
	vertices.emplace_back(VertexFormat(glm::vec3(length, -length - length, 0), color));






	vector<unsigned short> indices;

	indices.emplace_back(0);
	indices.emplace_back(1);




	Corp->SetDrawMode(GL_LINE_LOOP);
	Corp->InitFromData(vertices, indices);

	return Corp;

}

Mesh* Object2D::CreateMana1(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill, bool no_fan)
{


	Mesh* Corp = new Mesh(name);

	length = 40;

	vector<VertexFormat> vertices;


	vertices.emplace_back(VertexFormat(glm::vec3(0, 0, 0), color));
	vertices.emplace_back(VertexFormat(glm::vec3(-length, -length - length -length, 0), color));






	vector<unsigned short> indices;

	indices.emplace_back(0);
	indices.emplace_back(1);




	Corp->SetDrawMode(GL_LINE_LOOP);
	Corp->InitFromData(vertices, indices);

	return Corp;

}
Mesh* Object2D::CreateCasca(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill, bool no_fan)
{


	Mesh* Corp = new Mesh(name);

	length = 20;

	vector<VertexFormat> vertices;


	vertices.emplace_back(VertexFormat(glm::vec3(0, 0, 0), color));
	vertices.emplace_back(VertexFormat(glm::vec3(length + length + length, 0, 0), color));
	vertices.emplace_back(VertexFormat(glm::vec3(length + length/2, length, 0), color));






	vector<unsigned short> indices;

	indices.emplace_back(0);
	indices.emplace_back(1);
	indices.emplace_back(2);
	indices.emplace_back(0);




	Corp->SetDrawMode(GL_TRIANGLES);
	Corp->InitFromData(vertices, indices);

	return Corp;

}

Mesh* Object2D::CreateMana2(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill, bool no_fan)
{


	Mesh* Corp = new Mesh(name);

	length = 40;

	vector<VertexFormat> vertices;


	vertices.emplace_back(VertexFormat(glm::vec3(0, 0, 0), color));
	vertices.emplace_back(VertexFormat(glm::vec3(length + length , 0, 0), color));






	vector<unsigned short> indices;

	indices.emplace_back(0);
	indices.emplace_back(1);




	Corp->SetDrawMode(GL_LINE_LOOP);
	Corp->InitFromData(vertices, indices);

	return Corp;

}


Mesh* Object2D::CreateShuriken(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color,bool fill, bool no_fan)
{
	

	glm::vec3 corner = leftBottomCorner;

	Mesh* Shuriken = new Mesh(name);

	length = 25;

	vector<VertexFormat> vertices;


	vertices.emplace_back(VertexFormat(glm::vec3(0, 0, 0), color));
	vertices.emplace_back(VertexFormat(glm::vec3(-length  , 0, 0), color));
	vertices.emplace_back(VertexFormat(glm::vec3(-length , -length, 0), color));
	vertices.emplace_back(VertexFormat(glm::vec3(0, -length, 0), color));
	vertices.emplace_back(VertexFormat(glm::vec3(length, -length, 0), color));
	vertices.emplace_back(VertexFormat(glm::vec3(length, 0, 0), color));
	vertices.emplace_back(VertexFormat(glm::vec3(length, length, 0), color));
	vertices.emplace_back(VertexFormat(glm::vec3(0, length, 0), color));
	vertices.emplace_back(VertexFormat(glm::vec3(-length, length, 0), color));





	vector<unsigned short> indices;

	indices.emplace_back(0);
	indices.emplace_back(1);
	indices.emplace_back(2);
	indices.emplace_back(0);
	indices.emplace_back(3);
	indices.emplace_back(4);
	indices.emplace_back(0);
	indices.emplace_back(5);
	indices.emplace_back(6);
	indices.emplace_back(0);
	indices.emplace_back(7);
	indices.emplace_back(8);

	Shuriken->SetDrawMode(GL_TRIANGLES);
	Shuriken->InitFromData(vertices, indices);

	return Shuriken;


}


Mesh* Object2D::CreateBalon(std::string name, glm::vec3 leftBottomCorner,  float length, glm::vec3 color, bool fill , bool no_fan) {

	
	Mesh*  Balon = new Mesh(name);

	vector<VertexFormat> vertices;
	vector<unsigned short> indices;

	float PI = 3.1415926;

	float theta = 2 * PI / float(50);
	float c = cosf(theta);//precalculate the sine and cosine
	float s = sinf(theta);
	float t;

	

	float rx = 30;
	float ry = 40;
	float cx = 80;
	float cy = 40;
	float r = 40;

	float arg;
	
	int ii = 0;
	 
   while (ii < 50)
	{
		

		arg =  (PI* ii)  / 25;
		float x = r * cos(arg);
		float y = r * sin(arg);

		vertices.emplace_back(VertexFormat(glm::vec3(x ,  y , 0), color));

		//apply the rotation matrix
		t = x;
		x = c * x - s * y;
		y = s * t + c * y;

		indices.emplace_back(ii);
		ii++;
	}

	indices.emplace_back(50);

	
	Balon->SetDrawMode(GL_TRIANGLE_FAN);


	Balon->InitFromData(vertices, indices);
	return Balon;

}



Mesh* Object2D::CreateCap(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill, bool no_fan) {


	Mesh*  Balon = new Mesh(name);

	vector<VertexFormat> vertices;
	vector<unsigned short> indices;

	float PI = 3.1415926;

	float theta = 2 * PI / float(50);
	float c = cosf(theta);//precalculate the sine and cosine
	float s = sinf(theta);
	float t;

	float x = 1;//we start at angle = 0 
	float y = 0;

	float rx = 30;
	float ry = 40;
	float cx = 80;
	float cy = 40;
	float r = 40;

	int ii = 0;
	float arg;

	while (ii < 50)
	{


		arg = (PI* ii) / 25;
		float x = r * cos(arg);
		float y = r * sin(arg);

		vertices.emplace_back(VertexFormat(glm::vec3(x, y, 0), color));

		//apply the rotation matrix
		t = x;
		x = c * x - s * y;
		y = s * t + c * y;

		indices.emplace_back(ii);
		ii++;
	}

	indices.emplace_back(50);


	Balon->SetDrawMode(GL_TRIANGLE_FAN);


	Balon->InitFromData(vertices, indices);
	return Balon;

}

Mesh* Object2D::CreateOchi(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill, bool no_fan) {


	Mesh*  Balon = new Mesh(name);

	vector<VertexFormat> vertices;
	vector<unsigned short> indices;

	float PI = 3.1415926;

	float theta = 2 * PI / float(50);
	float c = cosf(theta);//precalculate the sine and cosine
	float s = sinf(theta);
	float t;

	float x = 1;//we start at angle = 0 
	float y = 0;

	float rx = 30;
	float ry = 40;
	float cx = 80;
	float cy = 40;
	float r = 5;
	

	float arg;


	int ii = 0;

	while (ii < 50)
	{


		arg = (PI* ii) / 25;
		float x = r * cos(arg);
		float y = r * sin(arg);

		vertices.emplace_back(VertexFormat(glm::vec3(x, y, 0), color));

		//apply the rotation matrix
		t = x;
		x = c * x - s * y;
		y = s * t + c * y;

		indices.emplace_back(ii);
		ii++;
	}

	indices.emplace_back(50);


	Balon->SetDrawMode(GL_TRIANGLE_FAN);


	Balon->InitFromData(vertices, indices);
	return Balon;

}

Mesh* Object2D::CreateTintaBalonSus(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill, bool no_fan) {


	glm::vec3 corner = leftBottomCorner;
	length /= 2;

	std::vector<VertexFormat> vertices =
	{
		VertexFormat(corner, color),
		VertexFormat(corner + glm::vec3(-length, 0, 0), color),
		VertexFormat(corner + glm::vec3(-length, length, 0), color),
		VertexFormat(corner + glm::vec3(-length -length, length, 0), color)
	};

	Mesh* square = new Mesh(name);
	std::vector<unsigned short> indices = { 0, 1, 2, 3 };

	if (!fill) {
		square->SetDrawMode(GL_LINE_LOOP);
	}
	else {
		// draw 2 triangles. Add the remaining 2 indices
		indices.push_back(0);
		indices.push_back(2);
	}

	square->InitFromData(vertices, indices);
	return square;
}

Mesh* Object2D::CreateViata(std::string name, glm::vec3 leftBottomCorner,  float length, glm::vec3 color, bool fill , bool no_fan) {

	
	Mesh*  Viata = new Mesh(name);

	vector<VertexFormat> vertices;
	vector<unsigned short> indices;

	float PI = 3.1415926;

	float theta = 2 * PI / float(50);
	float c = cosf(theta);//precalculate the sine and cosine
	float s = sinf(theta);
	float t;

	float x = 1;//we start at angle = 0 
	float y = 0;

	float r = 20;

	float arg;
	int ii = 0;

	while (ii < 50)
	{


		arg = (PI* ii) / 25;
		float x = r * cos(arg);
		float y = r * sin(arg);

		vertices.emplace_back(VertexFormat(glm::vec3(x, y, 0), color));

		//apply the rotation matrix
		t = x;
		x = c * x - s * y;
		y = s * t + c * y;

		indices.emplace_back(ii);
		ii++;
	}
	
	
	Viata->SetDrawMode(GL_TRIANGLE_FAN);


	Viata->InitFromData(vertices, indices);
	return Viata;

}


Mesh* Object2D::CreateCoadaBalon0(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill, bool no_fan)
{


	glm::vec3 corner = leftBottomCorner;

	Mesh* CoadaBalon = new Mesh(name);

	length = 40;

	vector<VertexFormat> vertices;


	vertices.emplace_back(VertexFormat(glm::vec3(0 , -30, 0), color));
	vertices.emplace_back(VertexFormat(glm::vec3(0  + 10, - 30  - (length /2), 0), color));
	vertices.emplace_back(VertexFormat(glm::vec3(0 - 10, - 30  -(length /2 ), 0), color));
	
	
	vector<unsigned short> indices;

	indices.emplace_back(0);
	indices.emplace_back(1);
	indices.emplace_back(2);
	
	


	CoadaBalon->SetDrawMode(GL_TRIANGLES);
	CoadaBalon->InitFromData(vertices, indices);

	return CoadaBalon;


}




Mesh* Object2D::CreateCoadaBalon(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill, bool no_fan)
{


	glm::vec3 corner = leftBottomCorner;

	Mesh* CoadaBalon = new Mesh(name);

	length = 40;

	vector<VertexFormat> vertices;


	vertices.emplace_back(VertexFormat(glm::vec3(-5, -30, 0), color));
	vertices.emplace_back(VertexFormat(glm::vec3(-5 + 10,-30 - (length / 2), 0), color));
	vertices.emplace_back(VertexFormat(glm::vec3(-5, -30 -(length / 2 + length / 2), 0), color));
	vertices.emplace_back(VertexFormat(glm::vec3(-5 + 10,-30 -(length / 2 + length / 2 + length / 2), 0), color));
	vertices.emplace_back(VertexFormat(glm::vec3(-5  , -30-(length / 2 + length / 2 + length / 2 + length/ 2), 0), color));
	
	
	





	vector<unsigned short> indices;

	indices.emplace_back(0);
	indices.emplace_back(1);
	indices.emplace_back(2);
	indices.emplace_back(3);
	indices.emplace_back(4);
	indices.emplace_back(5);

	


	CoadaBalon->SetDrawMode(GL_LINE_LOOP);
	CoadaBalon->InitFromData(vertices, indices);

	return CoadaBalon;


}


Mesh* Object2D::CreateBara(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill, bool no_fan)
{


	glm::vec3 corner = leftBottomCorner;

	Mesh* Bara = new Mesh(name);

	length = 20;

	vector<VertexFormat> vertices;


	vertices.emplace_back(VertexFormat(glm::vec3(0, 0, 0), color));
	vertices.emplace_back(VertexFormat(glm::vec3(0, length , 0), color));
    vertices.emplace_back(VertexFormat(glm::vec3(length * 8  , length , 0), color));
	vertices.emplace_back(VertexFormat(glm::vec3(length * 8, 0, 0), color));
	





	vector<unsigned short> indices;

	indices.emplace_back(0);
	indices.emplace_back(1);
	indices.emplace_back(2);
	indices.emplace_back(3);
	// indices.emplace_back(0);

	

	Bara->SetDrawMode(GL_LINE_LOOP);
	Bara->InitFromData(vertices, indices);

	return Bara;


}




Mesh* Object2D::CreatePatratBara(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill, bool no_fan)
{


	glm::vec3 corner = leftBottomCorner;

	Mesh* Patrat = new Mesh(name);

	length = 20;

	vector<VertexFormat> vertices;


	vertices.emplace_back(VertexFormat(glm::vec3(0, 0, 0), color));
	vertices.emplace_back(VertexFormat(glm::vec3(0, length , 0), color));
    vertices.emplace_back(VertexFormat(glm::vec3(length   , length , 0), color));
	vertices.emplace_back(VertexFormat(glm::vec3(length , 0, 0), color));
	





	vector<unsigned short> indices;

	indices.emplace_back(0);
	indices.emplace_back(1);
	indices.emplace_back(2);
	indices.emplace_back(3);
	// indices.emplace_back(0);

	

	Patrat->SetDrawMode(GL_TRIANGLE_FAN);
	Patrat->InitFromData(vertices, indices);

	return Patrat;
}


