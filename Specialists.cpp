//
//  Specialists.cpp
//  przychodnia
//
//  Created by Alexander on 05/05/2021.
//

#include "Specialists.hpp"

void Doctor::setVisit(int day, int hour) {
    if(schedule[day][hour] == false)
        schedule[day][hour] = true;
    else
        std::cout << "Termin wizity jest zajęty, wybierz inny termin\n";
}
