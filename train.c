#include "train.h"


int main(){
    printf("-------------------------------------------------------------------------INICIO-------------------------------------------------------------------------\n");
    seat_node *headofseats=create_list_of_seats();
    train_node *headlistoftrains=create_list_of_trains("Pombal","Coimbra");
    station_node *headlistofstations = create_list_of_stations("Pombal");
    addstation(headlistofstations,"Coimbra");
    addtrain(headlistoftrains,"Coimbra","Pombal");
    print_current_time();
    print_interface_options(headlistofstations,headlistoftrains,headofseats);
    
    
    
    printf("\n\n-------------------------------------------------------------------------FIM----------------------------------------------------------------------------\n");
    return 0;
}