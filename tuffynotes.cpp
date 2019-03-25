// Project Milestone 02
// Jizzelle Cardenas
// March 21, 2019
// This project contains the implementation for the TuffyNotes project milestone 03
// The program keeps track of notes entered.

#include <iostream>
#include <string>
#include "notebook.hpp"

int main()
{
  char choice;
  std::string rem;
  bool display_menu = true;

  Note note_list[MAX_NUMBER_NOTES];
  int note_index = 0;

  std::cout << "Welcome to TuffyNotes!";

  do {
    std::cout << std::endl;
    std::cout << "[C] Create a note" << std::endl;
    std::cout << "[L] List notes" << std::endl;
    std::cout << "[V] View note" << std::endl;
    std::cout << "[E] Exit" << std::endl;
    std::cout << "Choice: ";
    std::cin >> choice;

    std::getline(std::cin, rem);
    if (rem.length() > 0) {
      choice = ' '; // set to invalid "choice"
    }

    switch (choice) {
      case 'C':
      case 'c':
        note_list[note_index++] = createNote();
        break;
      case 'L':
      case 'l':
        listNotes(); //Calling Second Function
        break;
      case 'V':
      case 'v':
        viewNote(); //Calling Third Function
        break;
      case 'E':
      case 'e':
        display_menu = false;
        break;
      default:
        std::cout << "\nInvalid choice. Please try again.\n";
        break;
    }
  } while (display_menu); //Loops until user inputs 'e' or 'E' to exit

  std::cout << "\nThank you for using TuffyNotes!\n";

  /*
  std::cout << "\n(temporary debug)\nArray contents:\n";

  for (int i = 0; i < MAX_NUMBER_NOTES; i++) {
    if (!note_list[i].getTitle().empty() || !note_list[i].getBody().empty()) {
      std::cout << "Array location " << i << ": <" << note_list[i].getTitle()
        << "> " << note_list[i].getBody() << std::endl;
    }
  }
  */

  return 0;
}
