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

void listNotes(Note note_list[])
{
  Note createNote();
  std::cout << "Notes\n";
  int sum = 0;
  const in sentinel_value = -1;
  for (int i = 0; i < MAX_NUMBER_NOTES; i++)
  {
    if (note_list[i] == sentinel_value)
    {
      std::cout << "No notes have been added.\n";
    }
    sum += note_list[i];
    std::cout << sum << ". " << note_list[i] << std::endl;
  }

}

void viewNote (int num)
{
  int choice;
  listNotes(Note note_list[]);
  std::cout << "Please input note index: \n";
  std::cin >> choice;
  for (int choice != 0; choice <= MAX_NUMBER_NOTES; note_index++)
  {


  }

/*
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
  }*/
}
