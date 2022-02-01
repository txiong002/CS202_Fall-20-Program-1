//relief.cpp

#include "relief.h"

using namespace std;

//========================CONSTRUCTORS AND DESTRUCTORS======================================
relief::relief():relief_type(NULL),date(NULL) {}

relief::relief(const relief & to_copy)
{
    if(!to_copy.relief_type){

        relief_type = NULL;
    }
    else{

        relief_type = new char[strlen(to_copy.relief_type) + 1];
        strcpy(relief_type, to_copy.relief_type);
    }

    if(!to_copy.date){
        
        date = NULL;
    }
    else{

        date = new char[strlen(to_copy.date) + 1];
        strcpy(date, to_copy.date);
    }
}

relief::~relief()
{
    delete [] relief_type;
    delete [] date;
    relief_type = NULL;
    date = NULL;
}

housing::housing():num_of_rooms(0),is_avail(false) {}

//housing::housing(const housing & to_copy): relief(to_copy)
housing::housing(housing & to_copy):relief(to_copy), my_address(to_copy.my_address)
{
    num_of_rooms = to_copy.num_of_rooms;
    is_avail = to_copy.is_avail;

    //my_address(to_copy.my_address);

    //my_address.set_address(to_copy.my_address.get_street(), to_copy.my_address.get_zip());

}

housing::~housing()
{

}

address::address():street(NULL),zip(NULL) {}

address::address(char * street, char * zip)
{
   this->street = new char[strlen(street) + 1];
   strcpy(this->street, street);

   this->zip = new char[strlen(zip) + 1];
   strcpy(this->zip, zip);
}

address::address(const address & to_copy)
{
    if(!to_copy.street){

        street = NULL;
    }
    else{

        street = new char[strlen(to_copy.street) + 1];
        strcpy(street, to_copy.street);
    }

    if(!to_copy.zip){

        zip = NULL;
    }
    else{

        zip = new char[strlen(to_copy.zip) + 1];
        strcpy(zip, to_copy.zip);
    }
}

address::~address(){

    delete [] street;
    delete [] zip;
    street = NULL;
    zip = NULL;
}

food::food():food_type(NULL),exp_date(NULL),quantity(0) {}

food::food(const food & to_copy):relief(to_copy)
{
    food_type = new char[strlen(to_copy.food_type) + 1];
    strcpy(food_type,to_copy.food_type);

    exp_date = new char[strlen(to_copy.exp_date) + 1];
    strcpy(exp_date,to_copy.exp_date);
    
    quantity = to_copy.quantity;
}

food::~food()
{
    delete [] food_type;
    delete [] exp_date;

    food_type = NULL;
    exp_date = NULL;

}

supplies::supplies():supply_type(NULL),quantity(0) {}

supplies::supplies(const supplies & to_copy):relief(to_copy)
{
    supply_type = new char[strlen(to_copy.supply_type) + 1];
    strcpy(supply_type, to_copy.supply_type);

    quantity = to_copy.quantity;
}

supplies::~supplies(){

    delete [] supply_type;
    supply_type = NULL;
}

search_item::search_item():item(NULL), count(0) {}

search_item::search_item(const search_item & to_copy)
{
    if(!to_copy.item){

        item = NULL;
    }

    item = new char[strlen(to_copy.item) + 1];
    strcpy(item, to_copy.item);

    count = to_copy.count;
}

search_item::search_item(char * to_add)
{
    item = new char[strlen(to_add) + 1];
    strcpy(item, to_add);

}

search_item::~search_item()
{
    delete [] item;
}

//========================RELIEF FUNCTIONS===============================
void relief::read()
{
    char temp [100];
    char temp2 [100];

    if(relief_type){

        delete [] relief_type;
        relief_type = NULL;
    }

    if(date){
        
        delete [] date;
        date = NULL;
    }

    cout << "Enter relief type: (ex: housing, food, supplies) ";
    cin.get(temp,100,'\n');
    cin.ignore(100,'\n');

    cout << "Enter today's date: (ex:00/00/0000) ";
    cin.get(temp2,100,'\n');
    cin.ignore(100,'\n');

    relief_type = new char[strlen(temp) + 1];
    strcpy(relief_type,temp);

    date = new char[strlen(temp2) + 1];
    strcpy(date,temp2);

    return;

}

void relief::display() const
{
    cout << "Relief Type: " << relief_type << endl;
    cout << "Date Entered: " << date << endl;

    return;
}

//================================HOUSING FUNCIONS=======================================
void housing::read()
{
    char response;

    //relief::read();
    my_address.read();

    cout << "Enter number of rooms available: ";
    cin >> num_of_rooms;

    cout << "Is it available now? (y or n) ";
    cin >> response;

    if(response == 'y'){

        is_avail = true;
    }

    return;

}

void housing::display() const
{
    //relief::display();
    my_address.display();

    cout << "Rooms available: " << num_of_rooms << endl;
    cout << "Available today: ";
    if(is_avail){

        cout << "Yes";
    }
    else{
        cout << "No";
    }
    
    cout << endl;
    return;

}

//=============================ADDRESS FUNCTIONS================================
void address::read()
{
    char temp [100];
    char temp2 [100];

    if(street){
        delete [] street;
        street = NULL;
    }
    if(zip){
        delete [] zip;
        zip = NULL;
    }
        
    cout << "Enter address of housing location: ";
    cin.get(temp,100,'\n');
    cin.ignore(100,'\n');

    cout << "Enter zip code: ";
    cin.get(temp2,100,'\n');
    cin.ignore(100,'\n');

    street = new char[strlen(temp) + 1];
    strcpy(street,temp);

    zip = new char[strlen(temp2) + 1];
    strcpy(zip,temp2);

    return;
}

void address::display() const
{
    cout << "Location: " << street << ", " << zip << endl;
    return;
}

void address::set_address(char * new_street, char * new_zip)
{
    street = new char[strlen(new_street) + 1];
    strcpy(street,new_street);

    zip = new char[strlen(new_zip) + 1];
    strcpy(zip, new_zip);

}

char * address::get_street()
{
    return this->street;
}

char * address::get_zip()
{
    return this->zip;
}

//==================FOOD FUNCTIONS======================
void food::read()
{
    char temp [100];
    char temp2[100];
    //char response;

    if(food_type){

        delete [] food_type;
        food_type = NULL;
    }

    if(exp_date){

        delete [] exp_date;
        exp_date = NULL;
    }

    cout << "Enter food donated: ";
    cin.get(temp,100,'\n');
    cin.ignore(100, '\n');

    cout << "Enter expiration date if it has one, else enter 'NONE': ";
    cin.get(temp2,100,'\n');
    cin.ignore(100,'\n');

    cout << "Enter quantity donated: ";
    cin >> quantity;
    cin.ignore();

    food_type = new char[strlen(temp) + 1];
    strcpy(food_type,temp);

    exp_date = new char[strlen(temp2) + 1];
    strcpy(exp_date,temp2);

    return;
}

void food::display() const
{
    cout << "Food Donated: " << food_type << endl;
    cout << "Expiration Date: " << exp_date << endl;
    cout << "Quantity: " << quantity << endl;

    return;
}

// Checks for food that are expired
bool food::compare_date(char * todays_date)
{
    if(strcmp(exp_date,todays_date) <= 0){

        return true;
    }
    return false;

}

//===========================SUPPLIES FUNCTION=============================
void supplies::read()
{
    char temp [100];

    if(supply_type){

        delete [] supply_type;
        supply_type = NULL;
    }

    cout << "Enter type of supplies (ex. hammer, generator, blankets, etc...): ";
    cin.get(temp,100, '\n');
    cin.ignore(100, '\n');

    cout << "Enter quantity: ";
    cin >> quantity;

    supply_type = new char[strlen(temp) + 1];
    strcpy(supply_type, temp);

    return;
}

void supplies::display() const
{
    cout << "Supply: " << supply_type << endl;
    cout << "Quantity: " << quantity << endl;

    return;
}


//===========================SEARCH ITEM FUNCTIONS=================================
void search_item::read()
{
    char temp [100];

    if(item){

        delete [] item;
        item = NULL;
    }

    cout << "Enter item you are searching for: ";
    cin.get(temp,100,'\n');
    cin.ignore(100,'\n');

    item = new char[strlen(temp) + 1];
    strcpy(item,temp);

    return;
}

void search_item::display() const
{
    cout << item << endl;
    return;
}

bool search_item::compare_item(char * to_find)
{

    if(strcmp(to_find,item) == 0){

        return true;
    }
    return false;
}

