// Tou Xiong
// CS202 Fall '20
// Program 01: Relief Efforts

#include "relief.h"

using namespace std;

int main (){

    hNode my_house;
    fNode my_food;
    sNode my_supply;
    searchNode my_search;

    relief_list housing_list;
    relief_list food_list;
    relief_list supply_list;
    search_list search_list;


    char response;
    char temp_date [100];
    char to_find [100];
    int choice;

    do{

        cout << "\nChoose from options below\n====================== \n";
        cout << "1. Add Housing\n2. Add Food\n3. Add Supplies\n4. Search for an Item\n5. Exit Program\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch(choice){
            case 1:
                {
                    my_house.read();
                    housing_list.add_items(my_house);
                    break;
                }
            case 2:
                {
                    my_food.read();
                    food_list.add_items(my_food);
                    break;
                }
            case 3:
                {
                   my_supply.read();
                   supply_list.add_items(my_supply);
                   break;
                }
            case 4:
                {
                    //Search for an item
                    cout << "What item are you searching for: ";
                    cin.get(to_find,100,'\n');
                    cin.ignore(100,'\n');
                    search_list.find_item(to_find);

                    search_list.display();

                    break;

                }
            case 5:
                {
                    cout << "Thanks for using my Program!!!" << endl;
                    break;
                }

        }

        cout << "Do you want to add or search for anything else? (y or n) ";
        cin >> response;
        cin.ignore();

    }while(response == 'y');
   
    //Displays all the list of relief type
    cout << endl;
    housing_list.display();
    food_list.display2();
    supply_list.display3();
    
    //Check for expired food, any date less than the one entered will be removed
    cout << "Check for expired food products? (y or n): ";
    cin >> response; cin.ignore();

    if(response == 'y'){
        
        int count = 0;

        cout << "Enter in today's date (ex: 00/00/0000): ";
        cin.get(temp_date,100,'\n');
        cin.ignore(100,'\n');

        count = food_list.remove_expired(temp_date);

        cout << count << " items were removed from your food inventory." << endl;
        cout << "Updated Food List\n===================\n";
        food_list.display2();

    }

    return 0;
}

