#include "raylib.h"
#include <iostream>
#include <fstream>
#include <string>
#include <array>

std::string* textures;
std::string* level_title;
std::string* level_anchura;
std::string* level_altura;
std::string title;
int textures_num = 0;
int levels_num = 0;
int tiles_num = 0;

int loadTextures(std::ifstream& file, int num)
{
	std::string word;
	textures = new std::string[num + 1];
	textures[0] = "none";

	int counter = 1;
	while (counter < num + 1) {
		std::getline(file, word, ';');
		std::getline(file, word, ';');
		textures[counter] = word;
		std::cout << word << '\n';
		std::getline(file, word, '\n');

		counter++;
	}

	return 0;
}

int loadLevels(std::ifstream& file, int num)
{
	std::string word;
	level_title = new std::string[num];
	level_anchura = new std::string[num];
	level_altura = new std::string[num];

	int counter = 0;
	while (counter < num) {
		std::getline(file, word, ';');
		std::getline(file, word, ';');

		std::getline(file, word, ';');
		level_title[counter] = word;
		std::cout << word << '\n';

		std::getline(file, word, ';');
		level_altura[counter] = word;
		std::cout << word << '\n';

		std::getline(file, word, ';');
		level_altura[counter] = word;
		std::cout << word << '\n';

		std::getline(file, word, '\n');
		counter++;
	}

	return 0;
}

int generateLevel(std::ifstream& file)
{
	std::string word;
	std::getline(file, word, ';');

	if (word.compare("BACKGROUND") == 0) {
		std::getline(file, word, ';');
		tiles_num = std::stoi(word);
		std::getline(file, word, '\n');
	}
	else if (word.compare("FOREGROUND") == 0) {
		std::getline(file, word, ';');
		tiles_num = std::stoi(word);
		std::getline(file, word, '\n');
	}
	else if (word.compare("COLLISION") == 0) {
		std::getline(file, word, ';');
		tiles_num = std::stoi(word);
		std::getline(file, word, '\n');
	}

	return 0;
}

int main(int argc, char * argv[])
{
	std::ifstream game_conf("../M06_UF1/game.csv");

	if (!game_conf.is_open()) {
		std::cout << "ERROR: Error al abrir el archivo" << '\n';
		return 1;
	}

	std::string word;

	while (game_conf.good()) {
		std::getline(game_conf, word, ';');

		if (word.compare("TEXTURES") == 0) {
			std::getline(game_conf, word, ';');
			textures_num = std::stoi(word);
			std::getline(game_conf, word, '\n');

			loadTextures(game_conf, textures_num);
		}
		else if (word.compare("TITLE") == 0) {
			std::getline(game_conf, word, ';');
			title = word;
			std::cout << title << std::endl;
			std::getline(game_conf, word, '\n');
		}
		else if (word.compare("LEVELS") == 0) {
			std::getline(game_conf, word, ';');
			levels_num = std::stoi(word);
			std::getline(game_conf, word, '\n');

			loadLevels(game_conf, levels_num);
			//generateLevel(game_conf);
		}
	}
	
	game_conf.close();
	return 0;
}

/*int main(int argc, char * argv[]) 
{
	std::ofstream archivo;
	archivo.open("datos.csv");

	archivo << "a;b;c;;\n";
	archivo << "d;e;f;;\n";
	archivo << "1;2;3.456;;\n";

	archivo.close();
	return 0;

	std::ifstream ip("../M06_UF1/Personas.csv");

	if (!ip.is_open())
	{
		std::cout << "ERROR: Error al abrir el archivo" << '\n';
		return 1;
	}

	std::string nombre;
	std::string	apellido;
	std::string edad;
	std::string peso;

	int edadi = 0;
	float pesof = 0;

	while (ip.good())
	{
		std::getline(ip, nombre, ';');
		std::getline(ip, apellido, ';');
		std::getline(ip, edad, ';');
		std::getline(ip, peso, '\n');

		edadi = std::stoi(edad);
		pesof = std::stof(peso);

		std::cout << "Nombre: " << nombre << " " << apellido << '\n';
		std::cout << "Edad: " << edad << '\n';
		std::cout << "Peso: " << peso << '\n';
		std::cout << "===============" << '\n';
	}

	ip.close();
	return 0;
}*/