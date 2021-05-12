//
//  main.cpp
//  przychodnia
//
//  Created by Alexander on 05/05/2021.
//

#include <iostream>
#include <stdlib.h>
#include "doctor_list.hpp"

using namespace std;

void Register(DoctorList& myList);
void Doctor_list();
void XCode_cleaning();


int main() {
    DoctorList myList("/Users/alexander/Desktop/przychodnia_system/przychodnia/przychodnia/lekarze.txt");
    
    try {
        myList.group_docs();
    } catch(std::logic_error) {
        abort();
    }
    char action;
    
    for(;;) {
        cout << "WITAJ W SYSTEMIE PRZYCHODNI \n wybierz czynność" << endl;
        cout << " 'e' - exit \n 'R' - rejestracja \n 'P' - przegląd dostępnych lekarzy w placówce \n\n";
        cin >> action;
        switch (action) {
            case 'e': {
                cout << "Dziękujemy za skorzystanie z naszych usług\n";
                return 0;
            }
                break;
            case 'R':
            case 'r':
                {
                    Register(myList);
                }
                break;
            case 'P':
            case 'p':
                {
                    myList.display_list();
                }
                break;
            default: {
                cout << "Wybrano nieistniejącą opcję\n";
            }
                break;
        }
        
        XCode_cleaning();
        //system ("CLS");
    }
    return 0;
}

void Register(DoctorList& myList) {
    cout << "Lista dostępnych specjalistów:\n - kardiolog (k) \n - okulista (o) \n - internista (i) \n - powrót do menu (inne)";
    cout << "Wybierz specjalistę do którego chcesz się zarejestrować (podaj numer):\n\n";
    char action;
    cin >> action;
    switch (action) {
        case 'k': {
            cout << "Oto lista dostępnych kardiologów:\n\n";
            myList.display_categories("Kardiolog");
        }
            break;
        case 'o': {
            cout << "Oto lista dostępnych okulistów:\n\n";
            myList.display_categories("Okulista");
        }
            break;
        case 'i': {
            cout << "Oto lista dostępnych internistów:\n\n";
            myList.display_categories("Internista");
        }
            break;
        default:
            break;
    }
    XCode_cleaning();
}

void XCode_cleaning() {
    for(int i=0; i<14; i++)
    std::cout << "\n";
}
