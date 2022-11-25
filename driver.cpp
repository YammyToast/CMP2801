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

using namespace std;

int main()
{
	string userCommand;
	vector <Shape*> shapes;     // this one will hold your shapes
	vector <std::string> parameters; // this one will hold parameters for the commands


	while (userCommand.compare("exit") != 0) 
	{
		std::cout << "Enter the command: ";
		
		getline(cin, userCommand);

		std::stringstream ss;
		ss << userCommand;
		std::string token;
		while(getline(ss, token, ' ')) {
			parameters.push_back(token);
		}

		// char * cstr = new char[userCommand.length() + 1];
		// strncpy_s(cstr, userCommand.length()+1, userCommand.c_str());
		
		// // implement a string tokenizer to populate the parameters vector 
		// // check function strtok_s
		// char *token = std::strtok(cstr, " ");
		// while(token) {
		// 	std::cout << token << " ";
		// }
		

		// as a result of the process, parameters[0] should hold your command, followed by your parameters 
		std::string command = parameters[0];
		int x = std::stoi(parameters[1]); 
		int y = std::stoi(parameters[2]);
		

		// in the following code, consider checking for the arguments.
		// in case of too few arguments, you may remind the user the correct format

		if (command.compare("addR") == 0) {
			// get parameters in the correct order
			// The following four lines have a type mismatch error
			// note that the the parameters vector contains ascii values
			// HINT: stoi function converts from string to int

			// fix me! also note that x is not previously defined :(
			// int y = ...
			// int h = ...
			// int w = ...
			int h = std::stoi(parameters[3]);
			int w = std::stoi(parameters[4]);

			Rectangle* r = new Rectangle(x, y, h, w);
			Shape* shape = static_cast<Shape*>(r);
			shapes.push_back(shape);
			std::cout << *shape;
		}
		else if (command.compare("addS") == 0) {
			// get parameters
			// ...
			int e = std::stoi(parameters[3]);
			Square* s = new Square(x, y, e);
			Shape* shape = static_cast<Shape*>(s);
			shapes.push_back(shape);
			std::cout << *shape;
		}

		if (command.compare("addC") == 0) {
			// get parameters
			// ...
			int r = std::stoi(parameters[3]);
			Circle* c = new Circle(x, y, r);
			Shape* shape = static_cast<Shape*>(c);
			shapes.push_back(shape);
			std::cout << *shape;
			
		}
		else if (command.compare("scale") == 0) {
			// scale object at index... the scaling needs to be isotropic in case of circle and square 
			// you may want to check if the index exists or not!
			int shapeNo = std::stoi(parameters[1]);
			if (shapeNo <= shapes.size()) {
				x = std::stoi(parameters[2]);
				y = std::stoi(parameters[3]);
				try {
					Movable *m = dynamic_cast<Movable*>(shapes[shapeNo - 1]);
					m->scale(x, y);
					std::cout << *shapes[shapeNo - 1];
				}
				catch (const char* err) {
					std::cout << "Shape isn't Movable" << std::endl;

				}
			}
			// Multiple inhertitance is tricky! The Shape class does nto have a scale function, the Movable does!
			// As a result all your derived classes have scale functions... 
			// You may need to use type casting wisely to use polymorphic functionality!
			
		}
		else if (command.compare("move") == 0) {
			// move object at index 
			int shapeNo = std::stoi(parameters[1]); // read from parameters
			// you may want to check if the index exists or not!
			if (shapeNo <= shapes.size()) {
				// Inefficient as X and Y are defined earlier to just be rewritten again.
				x = std::stoi(parameters[2]);
				y = std::stoi(parameters[3]);
				Movable *m = dynamic_cast<Movable*>(shapes[shapeNo - 1]);
				m->move(x, y);

				// scale should work similarly...

				// note that here you should see the corresponding toString output for the derived classes...
				// if toString is not a virtual function, you may see the base class functionality :(
				std::cout << *shapes[shapeNo - 1];

			} else {
				std::cout << "Doesn't exist" << std::endl;

			}
			// Study the following code. A Shape object is not Movable, but all derived classes are...
			// you can't automatically type cast from a Shape to a Movable, but you can force a downcasting
		}
		else if (command.compare("display") == 0) {
			for (auto& shape: shapes) {
				std::cout << *shape << "\n" << std::endl;
			}
			// this is not given in our example, but why don't you implement a display function which shows all objects stored in shapes?
		}

		// do any necessary postprocessing at the end of each loop...
		// yes, there is some necessary postprocessing...
		parameters.clear();
		userCommand = "";

		std::cout << endl << endl;
	}

	std::cout << "Press any key to continue...";
	std::getchar();

	return 0;
}