// Egen fil for user funksjonalitet.
// La oss prøve dette nå. Vi lager en mappe, eller json men info om bruker. og lagrer den så jeg kan hente fra den etterpå.
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <limits>
#include "json.hpp"

using json = nlohmann::json;

// createNewUser
// Tar en referanse til en streng. eller da navn som er gitt av user. 
// Lager en json med denne. 

void createNewUser(const std::string& name)
{
	json data;
	data["name"] = name;

	std::ofstream toFile("data.json");
	if (!toFile.is_open())
	{
		std::cerr << "Error: Could not open file for writing.\n";
		std::exit(1);
	}

	toFile << data.dump(4);
	if (toFile.fail())
	{
		std::cerr << "Error: Failed to write to file.\n";
	}
	toFile.close();
}

// userExists
// Veldig enkel funksjon. sjekker om jeg får åpnet data.json, om ikke finnes den ikke og jeg må lage. 
bool userExists()
{
	std::ifstream fromFile("data.json");
	if (!fromFile.is_open()) 
	{
		
		return false;
	}
	else
	{
		return true;
	}

}

// getUser
	// get user if not make user ? greit å ha begge i samme funksjon?


// Må altså forbedres

std::string getUser()
{
	// Først åpner vi filen
	std::ifstream infil("data.json");
	if (!infil.is_open())
	{
		std::cerr << "Could not open data.json\n";
		return "";
	}
	json data;
	infil >> data;
	infil.close();

	return data["name"];
}