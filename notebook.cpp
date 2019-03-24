// Project Milestone 02
// Jizzelle Cardenas
// March 21, 2019
// This project contains the implementation for the
// TuffyNotes project milestone 02
// The program repeatedly asks a user to create a note
// until exit is selected.
// The program also keeps track of all notes entered.

#include <iostream>

#include "notebook.hpp"

//-------------------------------------
// global function definitions
//-------------------------------------

Note createNote()
{
  std::string title, body;

  std::cout << "\nPlease enter the note's title: ";
  std::getline(std::cin, title);
  std::cout << "Please enter the note: ";
  std::getline(std::cin, body);

  Note note;
  note.setTitle(title);
  note.setBody(body);

  std::cout << "\nNote added!\n";

  return note;
}

void listNotes(Note note_list[], int MAX_NUMBER_NOTES)
{
  std::cout << "Notes\n";
  if (list_notes >= 1)
  {
    while (n < list_notes)
    std::cout << n << ". " << note_list;
    n += 1;
  }
  else (list_notes == 0)
  {
    std::cout << "No notes have been added.\n";
  }
}

void viewNote (Note note_list[], int MAX_NUMBER_NOTES)
{
  listNotes(Note note_list[], int MAX_NUMBER_NOTES);
  if (list_notes >= 1)
  {
    std::cout << "Please input note index: " << n\n;
    if (n != index && n == 0)
    {
      std::cout << "Invalid note index." << std::endl;
    }
    else if (n != int index)
    {
      std::cout << "Invalid choice. Please try again." << std::endl;
    }
    std::cout << "[" <<name of title <<"]" << std::endl;
    std::cout << Note body << std::endl;
  }
}
