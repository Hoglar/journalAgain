// Need to make the checklist module
// Is checklist a good name, ne
// I need something i just do everyday, then goals, that i can complete? and keep a track of. 
#include <string>
#include <iostream>
#include <fstream>
// Access to json
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
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "Checklist title: ";
	std::getline(std::cin, item.title);
	
	std::cout << "Checklist description: ";
	std::getline(std::cin, item.description);

	item.creationDate = getTodayDate();
	// Need to store creationtimestamp(TS)
	item.creationTimestamp = creationTimestamp();
	// Tracker
	item.completedDays = 0;
	// Til senere, kan ha en array med refleksjoner rundt hvorfor jeg faila. 

	return item;
}


// Read
	// View current items and some status on them
	// en funksjon, som printer ut alle checklist items med counter på alle. 
	// Kunne laget en som viser mere detaljer.
void displayChecklist()
{
	// Hva må vi gjøre her?
	// Vi må hvertfal kjøre en read, så åpne en kanal først
	// åpne kanal
		// Hva så? iterere over allet itemsene inne i checklist.
			//Printe ut titel og score på en grei måte.
	std::ifstream innData("data.json");
	if (!innData.is_open())
	{
		std::cerr << "Error: Could not open data.json.\n";
		std::exit(1);
	}

	json data{};
	innData >> data;
	innData.close();

	std::cout << "Checklist:" << "\n\n";
	for (const auto& item : data["checklist"]) {
		std::cout << item["title"].get<std::string>() << " - ";
		std::cout << "Completed days: " << item["completed_days"] << "\n\n";
	}
	 
}
// three functions, one for iteration ans questions, then one for update and one for restart. 

// Update
// 


void restartCounter(json& item) 
{
	item["creation_timestamp"] = creationTimestamp();
	item["completed_days"] = 0;

	std::cout << "Checklist restart, better luck next time\n\n";

}

void updateCounter(json& item)
{
	item["completed_days"] = (creationTimestamp() - item["creation_timestamp"]) / 86400;

}

void checkOffList()
{
	std::cout << "Going through checklist. Answer y/n on wheather your are going strong:\n\n";

	std::ifstream innData("data.json");
	if (!innData.is_open())
	{
		std::cerr << "Error: Could not open data.json\n";
		std::exit(1);
	}

	json data{};
	innData >> data;
	innData.close();

	for (auto& item : data["checklist"]) {
		std::cout << item["title"].get<std::string>() << ": ";

		char ans{};
		std::cin >> ans;

		// Fikse det at ikke bare kan entere
		if (ans == 'n')
		{
			restartCounter(item);
			// Restart counter
			// Endre timestamp og counter
		}
		else 
		{
			// Update counter
			updateCounter(item);
		}
	}

	std::ofstream utData("data.json");
	utData << data.dump(4);
	utData.close();

	std::cout << "Checklist updated!";

}
	// checkOffList()
		// Needs some question and answer
		// Then separate update one for restart and one for update counter
		// 
// Delete
	//deleteChecklistItem(title?)
	// Load up checklist, then delete one.


void removeChecklistItem()
{
	std::ifstream inFile("data.json");
	json data{};
	inFile >> data;
	inFile.close();

	std::cout << "Going through checklist items, type y/n wheather you want to remove: \n\n";

	for (size_t i = 0; i < data["checklist"].size(); ++i)
	{
		auto& item = data["checklist"][i];

		std::cout << item["title"].get<std::string>() << ": ";

		char ans{};
		std::cin >> ans;
		
		if (ans == 'y')
		{
			data["checklist"].erase(data["checklist"].begin() + i);
			--i;

			std::cout << "Removed item from checklist!\n";
		}
	}

	std::ofstream outData("data.json");
	outData << data.dump(4);
	outData.close();
}
