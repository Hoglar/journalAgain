// Need to make the checklist module
// Is checklist a good name, ne
// I need something i just do everyday, then goals, that i can complete? and keep a track of. 
#include <string>
#include <iostream>
// Access to jso
#include "json.hpp"
#include "checklist.h"
#include "time.h"

// Create 

void createChecklist()
{
	// What does this need.
	// What kind of structure?
	// We need interaction, and we need creation.
	// Access to json i guess. 
}

// Ask user for input for checklist. Then use another function to make it. 
void inputChecklist()
{
	// Ask for title
	std::string title{};
	std::cout << "Checklist title: ";
	std::getline(std::cin, title);
	// Description
	std::string description{};
	std::cout << "Checklist description: ";
	std::getline(std::cin, description);
	// streakTime, need this to make some tracker
	std::cout << "Today is: " << getTodayDate();
	// Tracker
	//dayCounter()
		// Check time agains streak time
}


// Read

// Update

// Delete
