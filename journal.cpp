// Journal skal være ganske enkel, dato og  entry. Ikke så mye mening mere en dette. 
// Spørsmål om vi skal kjøre journal, eller bare velge det fra meny?
// Tror det er bedre

// Hva slags funksjoner. 

// function for saving/creating if not existing.
// Function for input
#include <iostream>
#include <string>
#include <fstream>
#include "json.hpp"

#include "time.h"
#include "journal.h"

using json = nlohmann::json;
journalEntry journalInput();

void saveJournalInput()
{
	journalEntry input {journalInput()};

	std::ifstream inData("data.json");
	if (!inData.is_open())
	{
		std::cerr << "Error: Could not open data.json.\n";
		std::exit(1);
	}

	json data{};
	inData >> data;
	inData.close();

	// Need to check it journal exists
	if (!data.contains("journal") || !data["journal"].is_array()) {
		data["journal"] = json::array();
	}

	json jsonJournalEntry = {
		{"feelings", input.feelings},
		{"mind", input.mind},
		{"plans", input.plans},
		{"div", input.div},
		{"date", input.entryDate}
	};

	data["journal"].push_back(jsonJournalEntry);

	std::ofstream outData("data.json");
	outData << data.dump(4);
	outData.close();

	std::cout << "Saved Journal item!";
}

// Ask for input, and saves said input. then gives it to saveJournalInput for saving to data.json
journalEntry journalInput()
{
	std::cout << "Journal entry for " << getTodayDate() << ":\n";

	journalEntry input;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "How are you feeling today? \n";
	std::getline(std::cin, input.feelings);

	std::cout << "Anything on your mind? \n";
	std::getline(std::cin, input.mind);

	std::cout << "Any plans for today? or plans completed? \n";
	std::getline(std::cin, input.plans);

	std::cout << "Want to write about something else: \n";
	std::getline(std::cin, input.div);

	input.entryDate = getTodayDate();

	return input;

}

