// Egen fil for user funksjonalitet.
// La oss pr�ve dette n�. Vi lager en mappe, eller json men info om bruker. og lagrer den s� jeg kan hente fra den etterp�.
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
// Veldig enkel funksjon. sjekker om jeg f�r �pnet data.json, om ikke finnes den ikke og jeg m� lage. 
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
	// get user if not make user ? greit � ha begge i samme funksjon?


// M� alts� forbedres

std::string getUser()
{
	// F�rst �pner vi filen
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