//
//  doctor_list.hpp
//  przychodnia
//
//  Created by Alexander on 05/05/2021.
//

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <exception>

#include "MyList.hpp"
#include "Specialists.hpp"

#ifndef doctor_list_hpp
#define doctor_list_hpp

class DoctorList {
private:
    MyList<std::string> doctor_list;
    std::vector<Doctor*> CategoriesDocs;
    std::string FilePath, list;
    
    void inicialization();
public:
    DoctorList(std::string listPath): FilePath(listPath) { inicialization(); }
    ~DoctorList() {};
    
    void display_list();
    void group_docs() throw(std::logic_error);
    void display_categories(std::string category);
};



#endif /* doctor_list_hpp */
