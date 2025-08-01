// Egen fil for user funksjonalitet.
// La oss pr�ve dette n�. Vi lager en mappe, eller json men info om bruker. og lagrer den s� jeg kan hente fra den etterp�.
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <limits>
#include "json.hpp"

using json = nlohmann::json;

// createUser
	//Lage fil men struktur ? JSON?

void createNewUser()
{

	//Henter f�rst navn

	std::cout << "Looks like you dont have an User yett. Do you want to make one? y/n: ";
	char ans{};
	std::cin >> ans;


	if (ans == 'y')
	{


		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		//proceed
		std::cout << "Whats your name? ";
		std::string name{};
		std::getline(std::cin, name);

		// S� lage json data for bruker.
		json data;
		data["navn"] = name;

		// S� lagre til fil
		std::ofstream utfil("data.json");
		utfil << data.dump(4);
		utfil.close();
	}
	else
	{
		std::cout << "Exiting program, try to find out about file.";
		std::exit(1);
	}

}

// Checkfil i egen, det er ryddigere

bool checkUser()
{
	std::ifstream infil("data.json");
	if (!infil.is_open()) 
	{
		std::cerr << "data.json does not exist or could not be opened!" << '\n';
		return false;
	}
	
	return true;
}

// getUser
	// get user if not make user ? greit � ha begge i samme funksjon?


// M� alts� forbedres
std::string getUser()
{
	std::ifstream infil("data.json");
	json data;
	infil >> data;
	infil.close();

	return data["navn"];
}