/* ------------------------------------------------------
CMP2801M: Advanced Programming
Driver program for assignment
Fall 2019

Written by Ayse Kucukyilmaz

This file is a representative test file.
During marking, we will use the exact same notation
as provided in the brief, so make sure
you follow that guideline. Also make sure that you don't
change the main body provided to you here.
Otherwise, your code may not pass the test cases...

GOOD LUCK!

------------------------------------------------------ */

#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Movable.h"

#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <regex>

using namespace std;

int main()
{
	string userCommand;
	vector <Shape*> shapes;
	vector <std::string> parameters;

	while (userCommand.compare("exit") != 0)
	{
		userCommand = "";

		std::stringstream ss;

		std::cout << "Enter the command: ";


		// Switch this back to using strtok
		getline(cin, userCommand);


		if (std::regex_match(userCommand, std::regex("(([a-zA-Z]+){1}(\\s[0-9]+)*(\\s)*)"))) {

			char* cstr = new char[userCommand.length() + 1];

			strcpy_s(cstr, userCommand.length()+1, userCommand.c_str());
			
			char* token = strtok_s(cstr, " ", &cstr);

			while (token) {
				parameters.push_back(token);
				token = strtok_s(NULL, " ", &cstr);
			}

			if (parameters.size() == 0) {
				continue;
			}

			std::string command = parameters[0];

			//ss << userCommand;
			/*std::string token;
			while (getline(ss, token, ' ')) {
				parameters.push_back(token);
			}*/

			


			if (command.compare("addR") == 0) {

				if (parameters.size() != 5) {
					continue;

				}
				int x = std::stoi(parameters[1]);
				int y = std::stoi(parameters[2]);
				int h = std::stoi(parameters[3]);
				int w = std::stoi(parameters[4]);

				Rectangle* r = new Rectangle(x, y, h, w);
				Shape* shape = static_cast<Shape*>(r);
				shapes.push_back(shape);
				std::cout << *shape;

			}
			else if (command.compare("addS") == 0) {

				if (parameters.size() != 4) {
					continue;
				}
				int x = std::stoi(parameters[1]);
				int y = std::stoi(parameters[2]);
				int e = std::stoi(parameters[3]);
				Square* s = new Square(x, y, e);
				Shape* shape = static_cast<Shape*>(s);
				shapes.push_back(shape);
				std::cout << *shape;

			}

			if (command.compare("addC") == 0) {

				if (parameters.size() != 4) {
					continue;

				}
				int x = std::stoi(parameters[1]);
				int y = std::stoi(parameters[2]);
				int r = std::stoi(parameters[3]);
				Circle* c = new Circle(x, y, r);
				Shape* shape = static_cast<Shape*>(c);
				shapes.push_back(shape);
				std::cout << *shape;

			}
			else if (command.compare("scale") == 0) {
				// scale object at index... the scaling needs to be isotropic in case of circle and square 

				if (parameters.size() != 4) {
					continue;

				}

				int shapeNo = std::stoi(parameters[1]);
				if (shapeNo <= shapes.size()) {
					int x = std::stoi(parameters[2]);
					int y = std::stoi(parameters[3]);
					try {
						Movable* m = dynamic_cast<Movable*>(shapes[shapeNo - 1]);
						m->scale(x, y);
						std::cout << *shapes[shapeNo - 1];

					}
					catch (const char* err) {
						std::cout << "Shape isn't Movable" << std::endl;

					}
				}

			}
			else if (command.compare("move") == 0) {

				if (parameters.size() != 4) {
					continue;

				}

				int shapeNo = std::stoi(parameters[1]);

				if (shapeNo <= shapes.size()) {
					// Inefficient as X and Y are defined earlier to just be rewritten again.
					// Potentially restructure to remove inefficiencies.
					int x = std::stoi(parameters[2]);
					int y = std::stoi(parameters[3]);
					Movable* m = dynamic_cast<Movable*>(shapes[shapeNo - 1]);

					m->move(x, y);


					std::cout << *shapes[shapeNo - 1];

				}
				else {
					std::cout << "Doesn't exist" << std::endl;

				}

			}
			else if (command.compare("display") == 0) {
				for (auto& shape : shapes) {
					std::cout << *shape << "\n" << std::endl;
				}

			}



			// Post Processing
			parameters.clear();
			userCommand.clear();

			std::cout << endl << endl;
		}
		else {
			std::cout << "\n\nInvalid Command or Format\n\n";

		}
	}


	std::cout << "Press any key to continue...";
	std::getchar();

	// Memory Clearing.
	for (size_t it = 0; it < shapes.size(); ++it) {
		delete shapes.at(it);
	}
	shapes.clear();

	return 0;
}