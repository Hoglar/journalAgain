// Prøver igjen

#include "startup.h"
#include "checklist.h"
#include "journal.h"
#include "menu.h"

int main()
{
	//startup();
	startup();
	int programChoice{ menuChoices() };

	switch (programChoice) 
	{
		// Journal entry
		case 1:
			saveJournalInput();
			break;
		case 2:
			checkOffList();
			break;
		case 3:
			createChecklist();
			break;
		case 4:
			removeChecklistItem();
			break;
	}
	// First we startup

	// Menu

	//saveJournalInput();
}