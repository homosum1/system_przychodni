//
//  doctor_list.cpp
//  przychodnia
//
//  Created by Alexander on 05/05/2021.
//

#include "doctor_list.hpp"

void DoctorList::inicialization() {
    std::ifstream in(FilePath);
    assert(in.is_open());
    
    std::ostringstream os;
    os  << in.rdbuf();
    list = os.str();
    
    std::string temp = list;
    //std::cout << temp << std::endl;
    size_t i = 1, prev = 0;
    while((i = temp.find('\n', prev)) != std::string::npos) {
        doctor_list.queue(temp.substr(prev, i - prev));
        prev = i+1;
    }
    
}

void DoctorList::display_list() {
    MyList<std::string> temporary;
    temporary = doctor_list;
    std::cout << temporary.return_head() << std::endl;
    std::cout << temporary.return_head() << std::endl;
    
    while(!temporary.isEmpty())
        std::cout << temporary.dequeue() << std::endl;
        
    assert(temporary.isEmpty());
    std::cout << "\nAby wyjść z listy naciśnij dowolny przycisk\n";
    char a;
    std::cin >> a;    
}

void DoctorList::group_docs() throw(std::logic_error) {
    MyList<std::string> temporary;
    temporary = doctor_list;
    
    int iterator = 0;
    while(!temporary.isEmpty()) {
        if(iterator <= 4) {
            CategoriesDocs.push_back(new Kardiolog);
            CategoriesDocs[CategoriesDocs.size()-1]->setName(temporary.dequeue());
        } else if((iterator > 4) && (iterator <= 14)) {
            CategoriesDocs.push_back(new Okulista);
            CategoriesDocs[CategoriesDocs.size()-1]->setName(temporary.dequeue());
        } else if(iterator > 14) {
            CategoriesDocs.push_back(new Internista);
            CategoriesDocs[CategoriesDocs.size()-1]->setName(temporary.dequeue());
        }
        else
            temporary.dequeue();
        
        iterator++;
        if(iterator < 0)
            throw std::logic_error("trying to access negative array value");
    }
}

void DoctorList::display_categories(std::string category) {
    int count = 1, diff = 0;
    bool set = false;
    for(int i=0; i<CategoriesDocs.size(); i++) {
        if(CategoriesDocs[i]->Doctor::specialization == category){
            if(!set) {
                set = true;
                diff = i - 1;
            }
            std::cout << "dr. Kardiolog " << CategoriesDocs[i]->name << " (" << count << ")" << std::endl;
            count++;
        }
    }
        
    std::cout << "\nWybierz lekarza do którego chcesz się zapisać:\n";
    char c;
    std::cin >> c;
    int a = (int)c - 48 + diff;
    
    if(a <= count) {
        std::cout << "\n Nazywam się " << CategoriesDocs[a]->name << " \n ";
        CategoriesDocs[a]->description();
        
        std::cout << "\n Pokaż wolne terminy - (t)  powrót do menu - (dowolny przycisk): \n";
        char t;
        std::cin >> t;
        std::string dni[] = {"pon", "wt", "śr", "czw", "ptk", "sob", "nd"};
        std::string godziny[] = {"8-10", "10-12", "12-14", "14-16", "16-18", "18-20"};
        if(t == 't') {
            std::cout << "wolne terminy: \n" << std::endl;
            for(int i = 0; i<7; i++) {
                std::cout << dni[i] << std::endl;
                for(int j = 0; j<6; j++) {
                    std::string status = "termin zajęty";
                    if(!CategoriesDocs[a]->schedule[i][j])
                        status = "wolny termin";
                    std::cout << godziny[j] << " : " << status << std::endl;
                }
                std::cout << "\n\n";
            }
        }
        else return;
        for(;;) {
            std::string d, name;
            std::cout << "\nPodaj imię\n";
            std::cin >> name;

            std::cout << "\nNa jaką godzinę umówić wizytę (dzień, godzina)?  (e) - wyjdź\n";
            char day_char;
            bool set = false;
            
            std::cin >> day_char;
            std::cin >> d;
            
            int day = (int)day_char - 49;
            
            if((d == "8") && (!CategoriesDocs[a]->schedule[day][0])) {
                CategoriesDocs[a]->schedule[day][0] = true;
                CategoriesDocs[a]->names[day][0] = name;
                set = true;
            } else if((d == "10") && (!CategoriesDocs[a]->schedule[day][1])) {
                CategoriesDocs[a]->schedule[day][1] = true;
                CategoriesDocs[a]->names[day][1] = name;
                set = true;
            } else if((d == "12") && (!CategoriesDocs[a]->schedule[day][2])) {
                CategoriesDocs[a]->schedule[day][2] = true;
                CategoriesDocs[a]->names[day][2] = name;
                set = true;
            } else if((d == "14") && (!CategoriesDocs[a]->schedule[day][3])) {
                CategoriesDocs[a]->schedule[day][3] = true;
                CategoriesDocs[a]->names[day][3] = name;
                set = true;
            } else if((d == "16") && (!CategoriesDocs[a]->schedule[day][4])) {
                CategoriesDocs[a]->schedule[day][4] = true;
                CategoriesDocs[a]->names[day][4] = name;
                set = true;
            } else if((d == "18") && (!CategoriesDocs[a]->schedule[day][5])) {
                CategoriesDocs[a]->schedule[day][5] = true;
                CategoriesDocs[a]->names[day][5] = name;
                set = true;
            }
            else if(day_char == 'e')
                return;
            else {
                std::cout << "Wybrano niepoprawną opcję\n";
            }
            if(set == true) {
                std::cout << "\nUdało się zarejestrować wizytę, naciśnij przycisk aby wyjść\n";
                std::cin >> day_char;
                return;
            }
                
        }
    }
}
