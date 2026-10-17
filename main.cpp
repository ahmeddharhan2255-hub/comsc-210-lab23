// COMSC-210 | Lab 23 | Ahmad Dharhan

#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(list<Goat> trip);
int main_menu();

int main() {
    srand(time(0));
    bool again;
    int choice = 0;
    list<Goat> trip;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();

    while(choice != 4){

        choice = main_menu();
        
        if(choice == 1){
            add_goat(trip, names, colors);
        }

        if(choice == 2){
            delete_goat(trip);
        }

        if(choice == 3){
            display_trip(trip);
        }

        else{
            cout << "Invalid Input! Try again!" << endl;
        }

    }



    return 0;
}

int main_menu(){
    int n = 0;
    while(n != 4){
        cout << "*** GOAT MANAGER 3001 ***" << endl;
        cout << "[1] Add a goat" << endl;
        cout << "[2] Delete a goat" << endl;
        cout << "[3] List goats" << endl;
        cout << "[4] Quit" << endl;
        cout << "Choice ---> ";
        cin >> n;

        if (n < 1 || n > 4){
            cout << "Invalid Input. View options and try again" << endl;
        }

    }

    return n;
}

void display_trip(list<Goat> trip){
    if(trip.empty()){
        cout << "List is empty!" << endl;
        return;
    }
   
    for(Goat g: trip){
        cout << g.get_name() << endl;
        cout << g.get_age() << endl;
        cout << g.get_color() << endl;
    }

}

void add_goat(list<Goat> trip){

}

void delete_goat(list<Goat> trip, string names[], string colors[]){

}