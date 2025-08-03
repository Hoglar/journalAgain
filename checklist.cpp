// Need to make the checklist module
// Is checklist a good name, ne
// I need something i just do everyday, then goals, that i can complete? and keep a track of. 
#include <string>
#include <iostream>
#include <fstream>
// Access to jso
#include "json.hpp"
#include "checklist.h"
#include "time.h"


using json = nlohmann::json;

ChecklistItem inputChecklist();
// Create 

void createChecklist()
{
	// What does this need.
	ChecklistItem item = inputChecklist();
	// Access to json i guess. 
	std::ifstream inData("data.json");
	if (!inData.is_open())
	{
		std::cerr << "Error: Could not open data.json.\n";
		std::exit(1);
	}

	json data{};
	inData >> data;
	inData.close();

	if (!data.contains("checklist") || !data["checklist"].is_array()) {
		data["checklist"] = json::array();
	}

	json jsonItem = {
		{"title", item.title},
		{"description", item.description},
		{"creation_date", item.creationDate},
		{"creation_timestamp", item.creationTimestamp},
		{"completed_days", item.completedDays}
	};

	data["checklist"].push_back(jsonItem);

	std::ofstream outData("data.json");
	outData << data.dump(4);
	outData.close();

	std::cout << "Saved Checklist item!";
}

// Ask user for input for checklist. Then use another function to make it. 
ChecklistItem inputChecklist()
{

	ChecklistItem item {};
	
	std::cout << "Checklist title: ";
	std::getline(std::cin, item.title);
	
	std::cout << "Checklist description: ";
	std::getline(std::cin, item.description);

	item.creationDate = getTodayDate();
	// Need to store creationtimestamp(TS)
	item.creationTimestamp = creationTimestamp();
	// Tracker
	item.completedDays = 0;

	return item;
}


// Read

// Update

// Delete
