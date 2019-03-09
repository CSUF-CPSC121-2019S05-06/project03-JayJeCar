#include "../notebook.hpp"
#include "gtest_ext.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(Milestone1, FiniteChoiceLoop) {
  srand(time(NULL));
  ASSERT_DURATION_LE(3, { main_output("tuffynotes", "c\nX\nX\ne"); });
}

TEST(Milestone1, CreateQuestionChoice) {
  std::string unittest_output =
      "Welcome to TuffyNotes!\n[C] Create a note\n[L] List notes\n[V] View "
      "note\n[E] Exit\nChoice: \nPlease enter the note's title: Please "
      "enter the note: \nNote added!\n\n[C] Create a note\n[L] List notes\n[V] "
      "View note\n[E] Exit\n"
      "Choice: \nThank you for using TuffyNotes!\n";
  ASSERT_DURATION_LE(
      3, { ASSERT_EXECIO_EQ("tuffynotes", "c\nX\nX\ne\n", unittest_output); });
}

TEST(Milestone3, ListNotesChoice) {
  std::string unittest_output =
      "Welcome to TuffyNotes!\n[C] Create a note\n[L] List notes\n[V] View "
      "note\n[E] Exit\nChoice: \nPlease enter the note's title: Please "
      "enter the note: \nNote added!\n\n[C] Create a note\n[L] List notes\n[V] "
      "View note\n[E] Exit\nChoice: \nNotes\n1. X\n\n[C] Create a note\n[L] "
      "List notes\n[V] View "
      "note\n[E] Exit\nChoice: \nThank you for using TuffyNotes!\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECIO_EQ("tuffynotes", "c\nX\nX\nl\ne\n", unittest_output);
  });
}

TEST(Milestone3, ViewNoteChoice) {
  std::string unittest_output =
      "Welcome to TuffyNotes!\n[C] Create a note\n[L] List notes\n[V] View "
      "note\n[E] Exit\n"
      "Choice: \nPlease enter the note's title: Please "
      "enter the note: \nNote added!\n\n[C] Create a note\n[L] List notes\n[V] "
      "View note\n[E] Exit\n"
      "Choice: \nNotes\n1. X\n\nPlease input note index: \n[X]\nX\n\n[C] "
      "Create a note\n[L] List notes\n[V] View note\n[E] Exit\nChoice: \nThank "
      "you for using TuffyNotes!\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECIO_EQ("tuffynotes", "c\nX\nX\nv\n1\ne\n", unittest_output);
  });
}

TEST(Milestone1, QuitChoice) {
  std::string unittest_output =
      "Welcome to TuffyNotes!\n[C] Create a note\n[L] List notes\n[V] View "
      "note\n[E] Exit\n"
      "Choice: \nThank you for using TuffyNotes!\n";
  ASSERT_DURATION_LE(
      3, { ASSERT_EXECIO_EQ("tuffynotes", "e\n", unittest_output); });
}

TEST(Milestone1, InvalidOptionChoice) {
  std::string unittest_output =
      "Welcome to TuffyNotes!\n[C] Create a note\n[L] List notes\n[V] View "
      "note\n[E] Exit\n"
      "Choice: \nInvalid choice. Please try "
      "again.\n\n[C] Create a note\n[L] List notes\n[V] View note\n[E] Exit\n"
      "Choice: \nThank you for using TuffyNotes!\n";
  ASSERT_DURATION_LE(
      3, {ASSERT_EXECIO_EQ("tuffynotes", "x\ne\n", unittest_output)});
}

TEST(Milestone1, ChoiceLoopLowercase) {
  std::string input = "";
  std::string unittest_output = "Welcome to TuffyNotes!";
  char choices[] = {'c', 'e', 'l', 'v', 'L', 'C', 'E'};
  unsigned int note_count = 1;
  std::string note_list = "\nNotes\n";
  char choice = ' ';
  do {
    choice = choices[rand() % 4];
    unittest_output +=
        "\n[C] Create a note\n[L] List notes\n[V] View note\n[E] Exit\nChoice: ";
    std::string s_choice(1, choice);
    input += s_choice + "\\n";
    switch (choice) {
    case 'c':
      unittest_output += "\nPlease enter the note's title: ";
      unittest_output += "Please enter the note: \nNote added!\n";
      input += "t\\nb\\n";
      note_list += std::to_string(note_count) + ". t\n";
      note_count++;
      break;
    case 'l':
      if (note_count > 1) {
        unittest_output += note_list + "\n";
      } else {
        unittest_output += "\nNo notes have been added.\n";
      }
      break;
    case 'v':
      if (note_count > 1) {
        unittest_output +=
            note_list + "\nPlease input note index: \n[t]\nb\n\n";
        input += "1\n";
      } else {
        unittest_output += "\nNo notes have been added.\n";
      }
      break;
    case 'e':
      unittest_output += "\nThank you for using TuffyNotes!\n";
      break;
    default:
      unittest_output += "Invalid choice. Please try again.\n";
    }
  } while (choice != 'e');
  ASSERT_DURATION_LE(
      3, { ASSERT_EXECIO_EQ("tuffynotes", input, unittest_output); });
}

TEST(Milestone1, ChoiceLoopUppercase) {
  std::string input = "";
  std::string unittest_output = "Welcome to TuffyNotes!";
  char choices[] = {'c', 'e', 'l', 'v', 'C', 'E', 'L', 'V'};
  unsigned int note_count = 1;
  std::string note_list = "\nNotes\n";
  char choice = ' ';
  do {
    choice = choices[rand() % 4 + 4];
    unittest_output +=
        "\n[C] Create a note\n[L] List notes\n[V] View note\n[E] Exit\nChoice: ";
    std::string s_choice(1, choice);
    input += s_choice + "\\n";
    switch (choice) {
    case 'C':
      unittest_output += "\nPlease enter the note's title: ";
      unittest_output += "Please enter the note: \nNote added!\n";
      input += "t\\nb\\n";
      note_list += std::to_string(note_count) + ". t\n";
      note_count++;
      break;
    case 'L':
      if (note_count > 1) {
        unittest_output += note_list + "\n";
      } else {
        unittest_output += "\nNo notes have been added.\n";
      }
      break;
    case 'V':
      if (note_count > 1) {
        unittest_output +=
            note_list + "\nPlease input note index: \n[t]\nb\n";
        input += "1\n";
      } else {
        unittest_output += "\nNo notes have been added.\n";
      }
      break;
    case 'E':
      unittest_output += "\nThank you for using TuffyNotes!\n";
      break;
    default:
      unittest_output += "Invalid choice. Please try again.\n";
    }
  } while (choice != 'E');
  ASSERT_DURATION_LE(
      3, { ASSERT_EXECIO_EQ("tuffynotes", input, unittest_output); });
}

TEST(Milestone2, NoteClass) {
  Note temp;
  temp.setTitle("title");
  temp.setBody("body");
  temp.getTitle();
  temp.getBody();
}

TEST(Milestone2, TitleGetSet) {
  Note your_note_object;
  std::string unittest_title = generate_string(10);
  your_note_object.setTitle(unittest_title);
  ASSERT_EQ(your_note_object.getTitle(), unittest_title);
}

TEST(Milestone2, BodyGetSet) {
  Note your_note_object;
  std::string unittest_body = generate_string(10);
  your_note_object.setBody(unittest_body);
  ASSERT_EQ(your_note_object.getBody(), unittest_body);
}

TEST(Milestone2, CreateNote) {
  Note your_note_object;
  std::string unittest_title = generate_string(10);
  std::string unittest_body = generate_string(10);
  std::string input = unittest_title + "\n" + unittest_body + "\n";
  std::string unittest_output = "\nPlease enter the note's title: ";
  unittest_output += "Please enter the note: \nNote added!\n";
  ASSERT_SIO_EQ(input, unittest_output, { your_note_object = createNote(); });
  ASSERT_EQ(your_note_object.getTitle(), unittest_title);
  ASSERT_EQ(your_note_object.getBody(), unittest_body);
}

TEST(Milestone3, ListNotesEmpty) {
  Note empty_array[0];
  ASSERT_DURATION_LE(3, {
    ASSERT_SIO_EQ("", "\nNo notes have been added.\n",
                  { listNotes(empty_array, 0); });
  });
}

TEST(Milestone3, ListNotesSingle) {
  Note notes[1];
  notes[0].setTitle("Buy groceries");
  ASSERT_DURATION_LE(3, {
    ASSERT_SIO_EQ("", "\nNotes\n1. Buy groceries\n",
                  { listNotes(notes, 1); });
  });
}

TEST(Milestone3, ListNotesMultiple) {
  Note notes[3];
  notes[0].setTitle("Buy groceries");
  notes[1].setTitle("CPSC 121 guide questions");
  notes[2].setTitle("Group mates list");
  ASSERT_DURATION_LE(3, {
    ASSERT_SIO_EQ("",
                  "\nNotes\n1. Buy groceries\n2. CPSC 121 guide questions\n3. "
                  "Group mates list\n",
                  { listNotes(notes, 3); });
  });
}

TEST(Milestone3, ViewNoteEmpty) {
  Note empty_array[0];
  ASSERT_DURATION_LE(3, {
    ASSERT_SIO_EQ("", "\nNo notes have been added.\n",
                  { viewNote(empty_array, 0); });
  });
}

TEST(Milestone3, ViewNote) {
  Note notes[2];
  notes[0].setTitle("Group mates list");
  notes[1].setTitle("Buy groceries");
  notes[1].setBody("1 qt. of milk, 5 apples, 1 dozen eggs");
  ASSERT_DURATION_LE(3, {
    ASSERT_SIO_EQ(
        "2",
        "\nNotes\n1. Group mates list\n2. Buy groceries\n\nPlease input note "
        "index: \n[Buy groceries]\n1 qt. of milk, 5 apples, 1 dozen eggs\n",
        { viewNote(notes, 2); });
  });
}

TEST(Milestone3, ViewNoteInvalidIndex) {
  Note notes[2];
  notes[0].setTitle("Group mates list");
  notes[1].setTitle("Buy groceries");
  notes[1].setBody("1 qt. of milk, 5 apples, 1 dozen eggs");
  ASSERT_DURATION_LE(3, {
    ASSERT_SIO_EQ("8",
                  "\nNotes\n1. Group mates list\n2. Buy groceries\n\nPlease "
                  "input note index: \nInvalid note index.\n",
                  { viewNote(notes, 2); });
  });
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
