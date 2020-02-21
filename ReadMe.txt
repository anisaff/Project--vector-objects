*******************************************************
*  Name      :  Anisa Filfil and Edwina Maben
*  Student ID:  107592654  and   108270286
*  Class     :  CSCI 2421
*  HW#       :  MOVIES DATABASE-FINAL PROJECT
*  Due Date  :  December 11th, 2019
*******************************************************


                Read Me


*******************************************************
*  Description of the program
*******************************************************

This program works to create a small database from
the files, "actor-actress.csv" and "pictures.csv".
These large files each have several fields and the
database works to sort and allow modifications
to be made to the file based on user input.


*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
  Main program. Most of program was developed in
  main.cpp. Several functions are declared and
  implemented. Main.cpp collects user input and
  calls functions and members from class
  Actors and class Pictures.

Name:  Actor.h
  Contains the definition for the class Actors. All
  get and set functions relating to the
  "actor-actress.csv" are located here.

Name: Actor.cpp
  Defines and implements functions for the Actors
  class.

Name:  Pictures.h
  Contains the definition for the class Pictures.
   All get and set functions relating to the
    "pictures.csv" are located here.

Name: Pictures.cpp
  Defines and implements functions for the Pictures
  class.

*******************************************************
*  Circumstances of programs
*******************************************************

  The program runs successfully.

  The program was developed and tested on CLion.  It was
  then compiled, run, and tested on csegrid. On csegrid,
  the actor complete search was not fully printing
  the same information printed on CLion (looks like
  it was cut out).
  Printing out on csegrid appeared more squished
  toegther compared to printing out on CLion.


*******************************************************
*  How to build and run the program
*******************************************************

1. Uncompress the project.  The project file is compressed.
  To uncompress it use the following commands
      % unzip [Final]

  Now you should see a directory named homework with the files:
       main.cpp
       Actors.h
       Actors.cpp
       Pictures.cpp
       Pictures.h
       pictures.csv
       actor-actress.csv
       makefile
       Readme.txt

2. Build the program.

   Change to the directory that contains the file by:
   % cd [Final]

   Compile the program by:
   % make

3. Run the program by:
  % ./Final.exe

4. Delete the obj files, executables, and core dump by
  %./make clean
