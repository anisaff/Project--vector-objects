#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <stdio.h>
#include <cctype>
#include "Actor.h"
#include "Pictures.h"
using namespace std;

// Function Prototypes
void readInActors(vector<Actor>&);
void addActor(vector<Actor>&);
void modifyActors(vector<Actor>&);
void sortActors(vector<Actor>&);
void partialSearchActors(vector<Actor>&);
void completeSearchActors(vector<Actor>&);
void printActors(vector<Actor>&);
void rewriteActorsFile(vector<Actor>&);

void readInPictures(vector<Pictures>&);
void addPicture(vector<Pictures>&);
void modifyPictures(vector<Pictures>&);
void sortPictures(vector<Pictures>&);
void partialSearchPictures(vector<Pictures>&);
void completeSearchPictures(vector<Pictures>&);
void printPictures(vector<Pictures>&);
void rewritePicturesFile(vector<Pictures>&);

int main()
{
    //Declare Variables
    int choice, choice2;
    char again = 'N';

    //Create Vectors
    vector<Actor> Actors;
    vector<Pictures> Picture;


    //While loop to create menu
    while(again == 'N')
    {
        char repeat = 'Y';
        cout << "\nMenu Selection:" << endl;
        cout << "----------------------" << endl;
        cout << "1. Actor File" << endl;
        cout << "2. Picture File" << endl;
        cout << "3. Exit Program" << endl;
        cout << "Enter selection number:";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "\nActor file has been read in!" << endl;
                readInActors(Actors);
                while (repeat == 'Y')
                {
                    cout << "\nSubmenu Selection:" << endl;
                    cout << "--------------------" << endl;
                    cout << "1. Modify Actor File" << endl;
                    cout << "2. Add to Actor File" << endl;
                    cout << "3. Sort Actor File" << endl;
                    cout << "4. Search Actor File" << endl;
                    cout << "5. Print Actor File" << endl;
                    cout << "6. Return to Main" << endl;
                    cout << "Enter selection number:";
                    cin >> choice2;

                    switch(choice2)
                    {
                        case 1:
                            modifyActors(Actors);
                            break;
                        case 2:
                            addActor(Actors);
                            break;
                        case 3:
                            sortActors(Actors);
                            break;
                        case 4:
                            int selection;
                            cout << "\nSelect Type of Search:" << endl;
                            cout << "----------------------" << endl;
                            cout << "1. Partial Search" << endl;
                            cout << "2. Complete Search" << endl;
                            cout << "Enter selection number:";
                            cin >> selection;

                            switch (selection)
                            {
                                case 1:
                                    partialSearchActors(Actors);
                                    break;
                                case 2:
                                    completeSearchActors(Actors);
                                    break;
                                default:
                                    cout << "You have entered an incorrect selection!" << endl;
                                    break;
                            }

                            break;
                        case 5:
                            printActors(Actors);
                            break;
                        case 6:
                            repeat = 'y';
                            break;
                        default:
                            break;

                    }
                }
                break;

            case 2:
                cout << "\nPicture file has been read in!" << endl;
                readInPictures(Picture);
                while(repeat == 'Y')
                {
                    cout << "\nSubmenu Selection:" << endl;
                    cout << "---------------------------" << endl;
                    cout << "1. Modify Picture File" << endl;
                    cout << "2. Add to Picture File" << endl;
                    cout << "3. Sort Picture File" << endl;
                    cout << "4. Search Picture File" << endl;
                    cout << "5. Print Picture File" << endl;
                    cout << "6. Return to Main"<< endl;
                    cout << "Enter selection number:";
                    cin >> choice2;

                    switch(choice2)
                    {
                        case 1:
                            modifyPictures(Picture);
                            break;
                        case 2:
                            addPicture(Picture);
                            break;
                        case 3:
                            sortPictures(Picture);
                            break;
                        case 4:
                            int selection;
                            cout << "\nSelect Type of Search:" << endl;
                            cout << "----------------------" << endl;
                            cout << "1. Partial Search" << endl;
                            cout << "2. Complete Search" << endl;
                            cout << "Enter selection number:";
                            cin >> selection;

                            switch (selection)
                            {
                                case 1:
                                    partialSearchPictures(Picture);
                                    break;
                                case 2:
                                    completeSearchPictures(Picture);
                                    break;
                                default:
                                    cout << "You have entered an incorrect selection!" << endl;
                                    break;
                            }
                            break;
                        case 5:
                            printPictures(Picture);
                            break;
                        case 6:
                            repeat = 'y';
                            break;
                        default:
                            cout << "You have entered an incorrect selection!" << endl;
                            break;
                    }
                }
                break;
            case 3:
                cout << "The program will now end!" << endl;
                again = 'n';
                break;
            default:
                break;

        }
    }
    return 0;
}
// Function to read in the info from the actor file
void readInActors(vector<Actor> &Actors)
{
    //Variables
    int year, winner;
    string award, name, film;
    char c, a;  // Variables to hold the commas in the file

    string firstLine;   //Variable for first line in file

    ifstream infile;
    infile.open("actor-actress.csv");

    getline(infile, firstLine); //Hold first line of file

    while(infile >> year)
    {
        infile >> c;
        getline(infile, award, ',');
        infile >> winner;
        infile >> a;
        getline(infile, name, ',');
        getline(infile, film);

        Actor Act(year, award, winner, name, film); //Create object

        Actors.push_back(Act);
    }
    infile.close();
}

// Function to allow user to add info to file
void addActor(vector<Actor> &Actors)
{
    int year, winner;
    string award, name, film;

    cout << "Enter Movie Year: ";
    cin >> year;
    cout << "Enter Award Type: ";
    cin.ignore();
    getline(cin , award);
    cout << "Enter Winner: ";
    cin >> winner;
    cout << "Enter Actor Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Film Name: ";
    getline(cin, film);

    Actor Act(year, award, winner, name, film);

    Actors.push_back(Act);

    //Call function to write into file
    rewriteActorsFile(Actors);

    cout << "Actor has been added!" << endl;
}

// Function to modify selected actor object
void modifyActors(vector<Actor> &Actors)
{
    // Variables modify
    int year, winner;
    string award, name, film;

    // Find movie they would like to modify
    string movieName;
    cout << "Enter name of Movie you would like to modify: ";
    cin.ignore();
    getline(cin, movieName);

    //find location of object to modify
    int spot = 0;   //variable to hold location
    int size = Actors.size();   //Size of vector
    for(int i = 0; i < size; i++)
    {
        if(Actors[i].getFilm() == movieName )
        {
            spot = i;
            break;
        }
    }

    // Menu to decide what variable to modify
    int choice;
    cout << "\nWhat would you like to change:" << endl;
    cout << "------------------------------" << endl;
    cout << "1. Movie Year" << endl;
    cout << "2. Award Type" << endl;
    cout << "3. Winner" << endl;
    cout << "4. Actor Name" << endl;
    cout << "5. Film Name" << endl;
    cout << "Enter selection number:";
    cin >> choice;

    switch (choice)
    {
        case 1:
            cout << "Enter New Year:";
            cin >> year;
            Actors[spot].setYear(year);
            cout << "The year has been Modified!" << endl;
            break;
        case 2:
            cout << "Enter New Award Type:";
            cin.ignore();
            getline(cin, award);
            Actors[spot].setAward(award);
            cout << "The Award has been Modified!" << endl;
            break;
        case 3:
            cout << "Enter Winner(0 or 1):";
            cin >> winner;
            Actors[spot].setWinner(winner);
            cout << "The Winner has been Modified!" << endl;
            break;
        case 4:
            cout << "Enter New Actor Name:";
            cin.ignore();
            getline(cin, name);
            Actors[spot].setName(name);
            cout << "The Actor's Name has been Modified!" << endl;
            break;
        case 5:
            cout << "Enter New Film:";
            cin.ignore();
            getline(cin, film);
            Actors[spot].setFilm(film);
            cout << "The Film has been Modified!" << endl;
            break;
        default:
            cout << "You have entered an incorrect selection!" << endl;
            break;
    }

    // Call function to write over the file
    rewriteActorsFile(Actors);

}

// Function to Sort file in ascending order of year
void sortActors(vector<Actor> &Actors)
{

    vector<pair<int, int> > Years;
    int size = Actors.size();
    int *arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i]=  Actors[i].getYear();
    }


    // Inserting element in pair vector
    // to keep track of previous indexes
    for (int i = 0; i < size; ++i) {
        Years.push_back(make_pair(arr[i], i));
    }

    // Sorting pair vector
    sort(Years.begin(), Years.end());

    // Displaying sorted element
    // with previous indexes
    // corresponding to each element
    //cout << "Element\t"
    // << "index" << endl;
    for (int i = 0; i < Years.size(); i++) {
        int k = Years[i].second;

        cout << Actors[k].getYear() << "\t" << Actors[k].getAward() << "\t" << Actors[k].getWinner() << "\t"
             << Actors[k].getName() << "\t" << Actors[k].getFilm() << endl;
    }




}

// Function to do a partial search of names entered by user
void partialSearchActors(vector<Actor> &Actors)
{
    string name;
    cout << "Enter First Name of Actor " << endl;
    cout << "you are looking for: ";
    cin.ignore();
    getline(cin, name);
    name[0] = toupper(name[0]);

    int size = Actors.size();
    int nameSize = name.length();
    vector<string> n;

    cout << "\nHere's who we Found Matching " << name << endl;
    cout << "-----------------------------------------" << endl;
    for (int i = 0; i < size; i++)
    {
        string copyName = Actors[i].getName();
        if(name == copyName.substr(0, nameSize))
        {
            n.push_back(Actors[i].getName());
        }
    }

    // Sort array of found names and remove duplicates from vector
    sort(n.begin(), n.end());

    // Erasing duplicate names from vector
    auto end = n.end();
    for (auto it = n.begin(); it != end; ++it) {
        end = remove(it + 1, end, *it);
    }
    n.erase(end, n.end());

    // Ouput all the names found
    int s = n.size();
    for(int j = 0; j < s; j++)
    {
        cout << n[j] << endl;
    }

    // Check if there was any outputted data otherwise output no match
    if (n.empty())
        cout << "No Matches!" << endl;

}

// Function to do a complete search of name entered
void completeSearchActors(vector<Actor> &Actors)
{
    // Variables
    string firstName, lastName, fullName;
    vector<int> n;
    // Collect user input about actor
    cout << "Enter First Name of Actor:";
    cin.ignore();
    getline(cin, firstName);
    cout << "Enter Last Name of Actor:";
    getline(cin, lastName);

    // Capitalize first and last name first letter
    firstName[0] = toupper(firstName[0]);
    lastName[0] = toupper(lastName[0]);

    fullName = firstName + " " + lastName;      // Combine first and last name

    // Loop through vector and find movies with matching Actors
    cout << "\nHere's Some Stats Matching " << fullName << endl;
    cout << "--------------------------------------" << endl;
    cout << "Year:" << setw(10) << "Movies:" << setw(35) << "Awards:" << setw(15) << "Win:" << endl;
    cout << "-----" << setw(10) << "-------" << setw(35) << "-------" << setw(15) << "----" << endl;
    int size = Actors.size();
    for(int i = 0; i < size; i++)
    {
        if (fullName == Actors[i].getName())
        {
            n.push_back(i);
        }
    }

    // Output all the lines matching with the actor name
    int s = n.size();
    for (int j = 0; j < s; j++)
    {
        cout << Actors[n[j]].getYear() << "\t" << Actors[n[j]].getFilm() << setw(35) << Actors[n[j]].getAward() << setw(10)<< Actors[n[j]].getWinner() << endl;
    }

    // Check if there was any outputted data otherwise output no match
    if (n.empty())
        cout << "No Matches!" << endl;

}       //Add year

// Function to print out information from the Actors file
void printActors(vector<Actor> &Actors)
{
    int size = Actors.size();

    cout << "\nYear:" << setw(10) << "Award:" << setw(30) << "Winner:\t" << "Name:\t" << "Film:\t" << endl;
    cout << "-----\t" << " ------"<< setw(30) << "-------\t" << "-----\t" << "-----\t" << endl;

    for(int i = 0; i < size; i++)
    {
        cout << Actors[i].getYear() << "\t"<< Actors[i].getAward() << right << setw(10) << Actors[i].getWinner() << "\t\t"
        << Actors[i].getName() << "\t\t" << left << Actors[i].getFilm() << endl;
    }
}

//Function to Write vector back into file
void rewriteActorsFile(vector<Actor> &Actors)
{
    //Read new object into file
    int size = Actors.size();
    ofstream outfile;
    outfile.open("actor-actress.csv");
    outfile << "Year,Award,Winner,Name,Film" << endl;
    for (int i = 0; i < size; i++)
    {
        outfile << Actors[i].getYear() << ","<< Actors[i].getAward() << "," << Actors[i].getWinner() << ","
                << Actors[i].getName() << "," << Actors[i].getFilm() << endl;
    }
    outfile.close();

}

// Function to read in the info from the pictures file
void readInPictures(vector<Pictures> &Picture)
{
    //Variables
    int year, nominations, duration, metacritic;
    float rating;
    string name, genre1, genre2, release, synopsis;
    char c, a, b, d, e; // Variables to hold the commas in the file

    string firstLine;   //Variable for first line in file

    ifstream infile;
    infile.open("pictures.csv");

    getline(infile, firstLine); //Hold first line of file

    while(getline(infile, name, ','))
    {
        infile >> year;
        infile >> c;
        infile >> nominations;
        infile >> a;
        infile >> rating;
        infile >> b;
        infile >> duration;
        infile >> d;
        getline(infile, genre1, ',');
        getline(infile, genre2, ',');
        getline(infile, release, ',');
        infile >> metacritic;
        infile >> e;
        getline(infile, synopsis);

        Pictures Pic(name, year, nominations, rating, duration, genre1, genre2, release, metacritic, synopsis);

        Picture.push_back(Pic);
    }
    infile.close();
}

// Function to allow user to add info to file
void addPicture(vector<Pictures> &Picture)
{
    //Variables
    int year, nominations, duration, metacritic;
    float rating;
    string name, genre1, genre2, release, synopsis;

    cout << "Enter Picture Name:";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Movie Year:";
    cin >> year;
    cout << "Enter Nomination Number:";
    cin >> nominations;
    cout << "Enter Rating Value:";
    cin >> rating;
    cout << "Enter Duration:";
    cin >> duration;
    cout << "Enter Genre 1:";
    cin.ignore();
    getline(cin, genre1);
    cout << "Enter Genre 2:";
    getline(cin, genre2);
    cout << "Enter Release Month:";
    getline(cin, release);
    cout << "Enter Metaritic Value:";
    cin >> metacritic;
    cout << "Enter Synopsis:";
    cin.ignore();
    getline(cin, synopsis);

    Pictures Pic(name, year, nominations, rating, duration, genre1, genre2, release, metacritic, synopsis);

    Picture.push_back(Pic);

    // Call function to write into file
    rewritePicturesFile(Picture);

    cout << "Picture has been added!" << endl;
}

//Function to modify selected Picture object
void modifyPictures(vector<Pictures> &Picture)
{
    //Variables
    int year, nominations, duration, metacritic;
    float rating;
    string name, genre1, genre2, release, synopsis;

    // Find movie they would like to modify
    string movieName;
    cout << "Enter name of Picture you would like to modify: ";
    cin.ignore();
    getline(cin, movieName);

    //find location of object to modify
    int spot = 0;   //variable to hold location
    int size = Picture.size();   //Size of vector
    for(int i = 0; i < size; i++)
    {
        if(Picture[i].getmovieName() == movieName )
        {
            spot = i;
            break;
        }
    }

    // Menu to decide what variable to modify
    int choice;
    cout << "\nWhat would you like to change:" << endl;
    cout << "------------------------------" << endl;
    cout << "1. Picture Name" << endl;
    cout << "2. Picture Year" << endl;
    cout << "3. Nominations" << endl;
    cout << "4. Rating" << endl;
    cout << "5. Duration" << endl;
    cout << "6. Genre 1" << endl;
    cout << "7. Genre 2" << endl;
    cout << "8. Release" << endl;
    cout << "9. Metacritic" << endl;
    cout << "10. Synopsis" << endl;
    cout << "Enter selection number:";
    cin >> choice;

    switch (choice)
    {
        case 1:
            cout << "Enter New Picture Name:";
            cin.ignore();
            getline(cin, name);
            Picture[spot].setmovieName(name);
            cout << "The Picture Name has been modified!" << endl;
            break;
        case 2:
            cout << "Enter New Year:";
            cin >> year;
            Picture[spot].setyear(year);
            cout << "The Year has been modified!" << endl;
            break;
        case 3:
            cout << "Enter New Nominations:";
            cin >> nominations;
            Picture[spot].setnumNominations(nominations);
            cout << "The Nominations have been modified!" << endl;
            break;
        case 4:
            cout << "Enter New Ratings:";
            cin >> rating;
            Picture[spot].setrating(rating);
            cout << "The Ratings have been modified!" << endl;
            break;
        case 5:
            cout << "Enter New Duration:";
            cin >> duration;
            Picture[spot].setDuration(duration);
            cout << "The Duration has been modified!" << endl;
            break;
        case 6:
            cout << "Enter New First Genre:";
            cin.ignore();
            getline(cin, genre1);
            Picture[spot].setGenre1(genre1);
            cout << "The First Genre has been modified!" << endl;
            break;
        case 7:
            cout << "Enter New Second Genre:";
            cin.ignore();
            getline(cin, genre2);
            Picture[spot].setGenre2(genre2);
            cout << "The Second Genre has been modified!" << endl;
            break;
        case 8:
            cout << "Enter New Release Month:";
            cin.ignore();
            getline(cin, release);
            Picture[spot].setreleaseMonth(release);
            cout << "The Release Month has been modified!" << endl;
            break;
        case 9:
            cout << "Enter New Metacritic:";
            cin >> metacritic;
            Picture[spot].setmetacritic(metacritic);
            cout << "The Metacritic has been modified!" << endl;
            break;
        case 10:
            cout << "Have not implemented synopsis"<< endl;
            break;
        default:
            cout << "You have entered an incorrect selection!" << endl;
            break;
    }

    // Call function to write over the file
    rewritePicturesFile(Picture);
}

//Function to sort file in ascending order of year
void sortPictures(vector<Pictures> &Picture)
{

    vector<pair<int, int> > Years;
    int size = Picture.size();
    int *arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i]=  Picture[i].getyear();
    }


    // Inserting element in pair vector
    // to keep track of previous indexes
    for (int i = 0; i < size; ++i) {
        Years.push_back(make_pair(arr[i], i));
    }

    // Sorting pair vector
    sort(Years.begin(), Years.end());

    // Displaying sorted element
    // with previous indexes
    // corresponding to each element
    //cout << "Element\t"
    cout << "index" << endl;
    for (int i = 0; i < Years.size(); i++) {
        int k = Years[i].second;

        cout << Picture[k].getyear() << "\t" << Picture[k].getmovieName() << "\t" << Picture[k].getnumNominations() << "\t"
             << Picture[k].getrating() << "\t" << Picture[k].getDuration() << "\t" << Picture[k].getGenre1()
             << "\t" << Picture[k].getGenre2() << "\t" << Picture[k].getreleaseMonth()
             << "\t" << Picture[k].getmetacritic() <<"\t" << Picture[k].getsynopsis() << endl << endl;
    }
}

// Function to do a partial search of the file based in unspecific input
void partialSearchPictures(vector<Pictures> &Picture)
{
    //Ask User for release month desired
    string month;
    cout << "Enter Release Month: ";
    cin.ignore();
    getline(cin, month);

    //Capitalize first letter in month
    month[0] = toupper(month[0]);

    // Find objects with matching months
    vector<int> n;
    int size = Picture.size();
    for(int i = 0; i < size; i++)
    {
        if(month == Picture[i].getreleaseMonth())
            n.push_back(i);
    }

    // Output all the movies with that release month
    cout << "\nHere are the Movies Released in " << month << ":" << endl;
    cout << "-------------------------------------------" << endl;
    int s = n.size();
    for(int j = 0; j < s; j++)
    {
        cout << Picture[n[j]].getmovieName() << endl;
    }

    // Check if there was any outputted data otherwise output no match
    if (n.empty())
        cout << "No Matches!" << endl;
}

// Function to do a complete search of movie name entered
void completeSearchPictures(vector<Pictures> &Picture)
{
    // Ask for user input
    string movie;
    cout << "Enter Movie Title: ";
    cin.ignore();
    getline(cin, movie);

    movie[0] = toupper(movie[0]);       // Capitalize first letter

    // Loop through vector to find matching movie titles
    vector<int> n;
    int size = Picture.size();
    for(int i = 0; i < size; i++)
    {
        if (movie == Picture[i].getmovieName())
            n.push_back(i);
    }

    // Output stats of movie matching line
    cout << "\nHere's Some Stats Matching " << movie << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Release:\t" << "Nominations\t" << "Rating:\t" << "Genre:" << endl;
    cout << "--------\t" << "-----------\t" << "-------\t" << "------" << endl;
    int s = n.size();
    for (int j = 0; j < s; j++)
    {
        cout << Picture[n[j]].getreleaseMonth() << "," << Picture[n[j]].getyear() << setw(6) << Picture[n[j]].getnumNominations() << setw(15)
            << Picture[n[j]].getrating() << setw(13) << Picture[n[j]].getGenre1() << endl;
    }

    // Check if there was any outputted data otherwise output no match
    if (n.empty())
        cout << "No Matches!" << endl;
}

// Function to print out information from the Actors file
void printPictures(vector<Pictures> &Picture)
{
    int size = Picture.size();

    for(int i = 0; i < size; i++)
    {
        cout << endl << Picture[i].getmovieName() << "\t"<< Picture[i].getyear() << "\t" << Picture[i].getnumNominations() << "\t"
             << Picture[i].getrating() << "\t" << Picture[i].getDuration() << "\t" << Picture[i].getGenre1()
             << "\t" << Picture[i].getGenre2() << "\t" << Picture[i].getreleaseMonth() << "\t" << Picture[i].getmetacritic()
             << "\t" << Picture[i].getsynopsis() << endl;

    }
}

// Function to print out information from the Actors file
void rewritePicturesFile(vector<Pictures> &Picture)
{
    //Read new object into file
    int size = Picture.size();
    ofstream outfile;
    outfile.open("pictures.csv");
    outfile << "name,year,nominations,rating,duration,genre1,genre2,release,metacritic,synopsis" << endl;
    for (int i = 0; i < size; i++)
    {
        outfile << Picture[i].getmovieName() << ","<< Picture[i].getyear() << "," << Picture[i].getnumNominations() << ","
                << Picture[i].getrating() << "," << Picture[i].getDuration() << "," << Picture[i].getGenre1()
                << "," << Picture[i].getGenre2() << "," << Picture[i].getreleaseMonth() << "," << Picture[i].getmetacritic()
                << "," << Picture[i].getsynopsis() << endl;
    }
    outfile.close();
}
