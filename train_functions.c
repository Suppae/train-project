#include "train.h"


station_node *create_list_of_stations(char *name) {
    station_node *head = (station_node *)malloc(sizeof(station_node));
    if (head == NULL) {
        perror("Memory allocation failed\n");
        exit(1);
    }
    head->next = NULL;
    strcpy(head->station.name, name);
    return head;
}


struct station_node *addstation(struct station_node *head,char *name){
    struct station_node *new_station = (struct station_node *)malloc(sizeof(station_node));

    if (new_station == NULL) {
        perror("Memory allocation failed\n");
        exit(1);
    }
    strcpy(new_station->station.name, name);
    new_station->next=NULL;
    
    if (head == NULL) {
        return new_station;
    }
    
    station_node *current = head;
    while(current->next!= NULL){
        current=current->next;
    }
    current->next=new_station;
    
    return head;
}

void print_stations(struct station_node *head) {
    station_node *current = head;
    
    printf("This are the stations available:\n\n");
    
    while (current != NULL) {
        for (int i=1;i<3;i++){
        printf("%d. Estação: %s\n",i, current->station.name);
        current = current->next;
        }
    }
    printf("\n\n");
}



//functions for train_list


struct train_node *create_list_of_trains(char *namestartstation, char *namefinishstation) {
    struct train_node *head = (struct train_node *)malloc(sizeof(train_node));
    if (head == NULL) {
        perror("Memory allocation failed\n");
        exit(1);
    }
    head->next = NULL;
    strcpy(head->train.namestartstation, namestartstation);
    strcpy(head->train.namefinishstation, namefinishstation);
    return head;
}

struct train_node *addtrain(train_node *head,char *namestartstation, char *namefinishstation){
    struct train_node *train = (struct train_node *)malloc(sizeof(train_node));

    if (train == NULL) {
        perror("Memory allocation failed\n");
        exit(1);
    }
    strcpy(train->train.namestartstation, namestartstation);
    strcpy(train->train.namefinishstation, namefinishstation);
    if (head == NULL) {
        return train;
    }
    
    train_node *current = head;
    while(current->next!= NULL){
        current=current->next;
    }
    current->next=train;
    train->next=NULL;
    return current;
}

void print_trains(struct train_node *head) {
    train_node *current = head;
    while (current != NULL) {
        for(int i=1;i<5000000;i++){
            printf("%d:   Origem: %s\n     Destino: %s\n\n",i, current->train.namestartstation, current->train.namefinishstation);
            current = current->next;
        }
        
    }
}


void print_trains_available(train_node *head, char *station) {
    train_node *current = head;
    int found = 0;
    int idx=2;
    printf("\n\nPara a estação %s há os seguintes comboios:\n", station);
    
    while (current != NULL) {
        if (strcmp(station, current->train.namestartstation) == 0) {
            printf("%d. Origem: %s | Destino: %s\n", idx,current->train.namestartstation, current->train.namefinishstation);
            found = 1;
            idx++;
        }
        current = current->next;
        
    }
    if (!found) {
        printf("Não há comboios disponíveis para esta estação\n");
    }
}

//function for taking seats

seat_node *create_list_of_seats(){
    seat_node *head = (seat_node*)malloc(sizeof(seat_node));

    if(head== NULL){
        perror("Memory allocation failed\n");
        exit(1);
    }
    head->next=NULL;
    return head;
}
int is_number(const char *str) {
    if (str[0] == '\0') return 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit((unsigned char)str[i]))
            return 0;
    }
    return 1;
}

seat_node *reserve_seat(seat_node *headlistofseats, char *seat, char *nameofpassenger, train_node *headoftrains) {
    if (is_number(seat)==1){}
    seat_node *new_seat = (seat_node*)malloc(sizeof(seat_node));
    if (new_seat == NULL) {
        perror("Memory allocation failed\n");
        exit(1);
    }
    
    strcpy(new_seat->passenger.name,nameofpassenger);
    strcpy(new_seat->seat.seat,seat);
    new_seat->next=NULL;

    if (headlistofseats == NULL) {
        return new_seat;
    }

    seat_node *current = headlistofseats;
    while(current->next != NULL){
        current=current->next;
    }
    current->next=new_seat;
    return headlistofseats;
}

void print_seats(seat_node *headlistofseats){
    seat_node *current=headlistofseats->next;
    while(current!=NULL){
        printf("Passageiro/a: %s\nSeat:%s\n",current->passenger.name,current->seat.seat);
        current=current->next;
    }

}

//functio to represent train

void print_train_model(seat_node *headlistofseats,train_node *train) {
    int num_carriages = 2;
    int num_rows = 4;
    int num_cols = 8;
    int seat_number = 1;

    printf("\n");

    for (int car = 1; car <= num_carriages; car++) {
        printf("    ---------------------------------------------");
    }
    printf("\n");

    for (int r = 1; r <= num_rows; r++) {
        for (int car = 0; car < num_carriages; car++) {
            printf("    |");

            for (int c = 1; c <= num_cols; c++) {
                if (c == 5) {
                    printf("| |");
                }

                int ocupado = 0;
                seat_node *current = headlistofseats;
                while (current != NULL && train) {
                    if (atoi(current->seat.seat) == seat_number) {
                        ocupado = 1;
                        break;
                    }
                    current = current->next;
                }

                if (ocupado)
                    printf("  X  ");
                else
                    printf(" %2d  ", seat_number);

                seat_number++;
            }

            printf("|");
        }
        printf("\n");

        if (r == 2) {
            for (int car = 0; car < num_carriages; car++) {
                printf("   []                                           |");
            }
            printf("\n");
        }
    }

    for (int car = 0; car < num_carriages; car++) {
        printf("    ---------------------------------------------");
    }

    for (int car = 0; car < num_carriages; car++) {
        if (car < num_carriages - 1) {
            printf("                                         ");
        }
    }
    printf("\n\n\n");
}

//funções interface


void print_first_menu(){
    printf("Type the option:\n");
    printf("0. Exit\n");
    printf("1. Go back\n");
    printf("2. See stations available\n\n");
}


void print_second_menu(station_node *headstations){
    station_node *current = headstations;
    int number = 2; 
    printf("Type the option of the second menu:\n");
    printf("0. Exit\n");
    printf("1. Go back to menu\n\n");
    printf("See trains available at:\n");
    
    while (current != NULL) {
        printf("%d. Estação: %s\n", number, current->station.name);
        current = current->next;
        number++;
    }
}

void print_third_menu(){
    
    printf("\nType the option of the third menu:\n\n");
    printf("0. Exit\n");
    printf("1. Go back to menu\n\n");
    printf("See seats available at train number:\n");
    
}

void print_fourth_menu(){
    printf("Type the option of the fourth menu:\n");
    printf("0. Exit\n");
    printf("1. Go back to menu\n");
    printf("2. Reserve a seat\n");

}

void fourth_menu(seat_node *headlistofseats,train_node *headoftrains, station_node *headlistofstations) {
    int option4;
    print_fourth_menu();
    char nameofpassenger[MAX];
    char seat[MAX];
    while(1){
        if (scanf("%d", &option4) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }
        switch(option4){
        case 0:
            printf("Exiting...\n");
            return;
        case 1:
            printf("Going back...\n");
            return;
        case 2: 
            
            printf("Type your name:\n");
            scanf("%s", nameofpassenger);
            printf("Type the seat you want:\n");
            scanf("%s", seat);
            reserve_seat(headlistofseats, seat, nameofpassenger, headoftrains);
            printf("%s, your seat has been reserved at train %s | %s!\n", nameofpassenger,headoftrains->train.namestartstation,headoftrains->train.namefinishstation);
            memset(nameofpassenger, 0, sizeof(nameofpassenger));
            memset(seat, 0, sizeof(seat));
            print_train_model(headlistofseats,headoftrains);
            break;
        case 3:
            if (headlistofstations->station.name != headoftrains->train.namestartstation) {
                headoftrains = headoftrains->next;
                return;
            }
            printf("Type your name:\n");
            scanf("%s", nameofpassenger);
            printf("Type the seat you want:\n");
            scanf("%s", seat);
            reserve_seat(headlistofseats, seat, nameofpassenger,headoftrains);
            printf("%s, your seat has been reserved at train %s | %s!\n", nameofpassenger,headoftrains->train.namestartstation,headoftrains->train.namefinishstation);
            memset(nameofpassenger, 0, sizeof(nameofpassenger));
            memset(seat, 0, sizeof(seat));
            return;
        default:
            printf("Invalid input. Please choose an available option.\n");
            break;
        }
    }
}


void third_menu(train_node *headlistoftrains,seat_node *headlistofseats,station_node *headlistofstations) {
    int option3;
    print_third_menu();
    while(1){
        if (scanf("%d", &option3) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Limpa o buffer
            continue;
        }
        switch(option3){
        case 0:
            printf("Exiting...\n");
            return;
        case 1:
            printf("Going back...\n");
            return;
        case 2:
            print_train_model(headlistofseats,headlistoftrains);
            fourth_menu(headlistofseats,headlistoftrains,headlistofstations);
            break;
        default:
            printf("Invalid input. Please choose a option available.\n");
            break;
        }
    }
}


void second_menu(train_node *headtrain,seat_node *headlistofseats, station_node *headlistofstations) {
    int option2;
    while(1){
        if (scanf("%d", &option2) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Limpa o buffer
            continue;
        }
        switch (option2){
            
            case 0:
                printf("Exiting...\n");
                return;
            case 1:
                printf("Going back...\n");
                return;
            case 2:
                print_trains_available(headtrain,"Pombal");
                third_menu(headtrain,headlistofseats,headlistofstations);
                break;
            case 3:
                print_trains_available(headtrain,"Coimbra");
                third_menu(headtrain,headlistofseats,headlistofstations);
                break;
            default:
                printf("Invalid input. Please enter a valid option.\n");
                break;
        }
    }
        
}



void print_interface_options(station_node *headstation, train_node *headtrain, seat_node *headlistofseats) {
    int option;

    while (1) {
        print_first_menu();
        printf("Escolha uma opção: ");
        if (scanf("%d", &option) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Limpa o buffer
            continue;
        }
        switch (option) {
            case 0:
                printf("Exiting...\n");
                return;
            case 1:
                printf("Going back...\n");
                print_first_menu();
                break;
            case 2:
                print_stations(headstation);
                print_second_menu(headstation);
                second_menu(headtrain,headlistofseats, headstation);
                break;
            default:
                printf("Invalid input. Please choose a option available.\n");
                break;
        }
    }
}




void print_current_time() {
    time_t now;
    struct tm *local;
    now = time(NULL);
    local = localtime(&now);
    printf("Current time: %02d:%02d:%02d\n", local->tm_hour, local->tm_min, local->tm_sec);
}

void print_train_time(train_node *headoftrains){
    train_node *current=headoftrains;
    int i=0;
    while(i==0){
        time_t now;
        struct tm *local;
        now = time(NULL)+30*60;
        local = localtime(&now);
        printf("O comboio %s -> %s é às: %02d:%02d:%02d\n",headoftrains->train.namestartstation,headoftrains->train.namefinishstation,local->tm_hour, local->tm_min, local->tm_sec);
        i=1;
    }
}

