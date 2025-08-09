// Trenger en meny
// Så kan jeg velge hva jeg skal gjøre.

// meny items?	
// create checklist item
// delete checklist item
// make journal entry

#include <iostream>
#include <iomanip>

#include "menu.h"

// Ask for input
int menuChoices()
{
	std::cout << std::left << std::setw(25) << "Make journal entry:" << "-1-\n";
	std::cout << std::left << std::setw(25) << "Checklist:" << "-2-\n";
	std::cout << std::left << std::setw(25) << "Create Checklist item" << "-3-\n";
	std::cout << std::left << std::setw(25) << "Delete checklist item" << "-4-\n\n";

	std::cout << "Enter number: ";
	int choice{};
	std::cin >> choice;

	return choice;
	
}


// Make choice, i make chioses in main i think.
