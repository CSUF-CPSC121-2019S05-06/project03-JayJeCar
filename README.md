# TuffyNotes Project Milestone 3

This is milestone 3 of the [TuffyNotes Project](https://docs.google.com/document/d/14qiyhHtXpZOkVqHdUmLjLu1OWcBhQijvqybHtgsEWhI/edit?usp=sharing).

# Prerequesites

Class `Note` from milestone 2, containing:
 - public *accessors* named `getTitle` and `getBody`
 - public *mutators* named `setTitle` and `setBody`

Global function `createNote` from milestone 2

# Requirements

Provide functionality to list all the `Note` objects that were created, and view a particular `Note` object using its index.

Implement the `listNotes` function that takes in an array of `Note` objects and the size of that array as its input. The function does not return anything, but it displays on screen the list of note titles from the array that was passed in. It should show an informational message if no notes have been created yet. Specifically, it should say *No notes have been added.*

Implement the `viewNote` function that also takes in an array of `Note` objects and the size of the array as its input. This function should first call the `listNotes` function to show all the notes available.

If the program already created notes, `viewNote` will then ask the user to select the note they want to view, given its index. Specifically, it should ask: *Please input note index:*

The function will use the index to select and show the contents of the note. The format for showing a note is as follows.

```
[Note title]
Note body
```
The function does not print anything else if there were no notes created.

Take note that the index in the list of notes begins with 1, but array indices start at 0. Make sure you consider this in your code.

Finally, the function should display an error message if the user provides an invalid index. Specifically, it should say: *Invalid note index.*

Update your menu to support listing and viewing notes. Kindly refer to the sample output below and follow it as closely as possible.

```
Welcome to TuffyNotes!
[C] Create a note
[L] List notes
[V] View note
[E] Exit
Choice: c

Please enter the note's title: Grocery list
Please enter the note: milk, banana, water, turkey sandwich

Note added!

[C] Create a note
[L] List notes
[V] View note
[E] Exit
Choice: c

Please enter the note's title: Band mates
Please enter the note: Geddy Lee, Alex Lifeson, Neil Peart

Note added!

[C] Create a note
[L] List notes
[V] View note
[E] Exit
Choice: l

Notes
1. Grocery list
2. Band mates

[C] Create a note
[L] List notes
[V] View note
[E] Exit
Choice: v

Notes
1. Grocery list
2. Band mates

Please input note index: 2

[Band mates]
Geddy Lee, Alex Lifeson, Neil Peart

[C] Create a note
[L] List notes
[V] View note
[E] Exit
Choice: v

Notes
1. Grocery list
2. Band mates

Please input note index: 0

Invalid note index.

[C] Create a note
[L] List notes
[V] View note
[E] Exit
Choice: j

Invalid choice. Please try again.

[C] Create a note
[L] List notes
[V] View note
[E] Exit
Choice: e

Thank you for using TuffyNotes!
```

Place the function prototypes and classes in `notebook.hpp`, the function implementations in `notebook.cpp`, and the main function in `tuffynotes.cpp`.

# Submission checklist
1. Created function prototype
1. Created function implementation
1. Called function in the driver
1. Followed the [proper file structure for using functions](https://github.com/ILXL-guides/function-file-organization)
1. Compiled and ran the driver
1. No errors on the unit test (make test)
1. No errors on the style check (make stylecheck)
1. No errors on the format check (make formatcheck)

# Documentation
See [google's style guide](https://google.github.io/styleguide/cppguide.html#Comments) for more details.

## File comments
Describe the contents of the file on the first line. For example:

```cpp
// This file implements a simple calculator
```

## Function comments
Describe the use of the function and how it is implemented if it is non-obvious. For example:

```cpp
// Displays a greeting based on the time of day on the command line using the name parameter.
void showGreeting(std::string name) {
  ...
}
```

## Implementation comments
Provide comments in tricky, non-obvious, interesting, or important parts of your code.

```cpp
// Compute the distance between two points using the Manhattan distance formula
double dist = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
```

# Code evaluation
Open the terminal and navigate to the folder that contains this milestone. Assuming you have pulled the code inside of `/home/student/project02-tuffy` and you are currently in `/home/student` you can issue the following commands

```
cd project02-tuffy
```

Use the `clang++` command to compile your code and the `./` command to run it. The sample commands below shows how you would compile code saved in `tuffynotes.cpp` and `notebook.cpp` and into the executable file `tuffynotes`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
clang++ -std=c++17 tuffynotes.cpp notebook.cpp -o tuffynotes
./tuffynotes
```

You can run one, two, or all the commands below to `test` your code, `stylecheck` your code's design, or `formatcheck` your work. Kindly make sure that you have compiled and executed your code before issuing any of the commands below to avoid errors.

```
make test
make stylecheck
make formatcheck
```

A faster way of running all these tests uses the `all` parameter.

```
make all
```

# Submission
1. When everything runs correctly, let's copy your code into the Github repository. The first step is to add your code to what is called the staging area using git's `add` command. The parameter after `add` is the name of the file you want to add. There are cases when you have multiple changed files, so you can just type . (period) to add all modified files.

    ```
    git add .
    ```

1. Once everything is in the staging area, we use the `commit` command to tell git that we have added everything we need into the staging area.

    ```
    git commit -m "Description of the code change."
    ```

1. In case it asks you  to configure global variables for an email and name, just copy the commands it provides then replace the dummy text with your email and Github username.

    ```
    git config --global user.email "tuffy@csu.fullerton.edu"
    git config --global user.name "Tuffy Titan"
    ```

    When you're done, make sure you type `git commit` again.

1. Git will ask you to describe what you have added to the staging area. By default, you will use a command-line based editor called *nano*. Go ahead and provide a description then press <kbd>Ctrl</kbd> + <kbd>x</kbd> to exit. Press <kbd>Y</kbd> to confirm that you want to make changes and then press <kbd>Enter</kbd>.

1. Lets push all changes to the Github repository using git's `push` command. Provide your Github username and password when you are asked.

    ```
    git push
    ```

1. When you finish the exercise, go back to Titanium and click on the `Add submission` button in the project milestone page. Provide a short message in the text area such as "finished milestone" and click on `Save changes`. Finally click on `Submit assignment` to inform your instructor that you are done.
