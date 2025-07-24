#ifndef TRAIN_H
#define TRAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <features-time64.h>
#include <ctype.h>

#define MAX 100


//Passenger structures
typedef struct passenger{
    char name[MAX];
}passenger;


//Seat structures
typedef struct seat{
    char seat[MAX];
}seat;

typedef struct seat_node{
    struct passenger passenger;
    struct seat seat;
    struct seat_node *next;
}seat_node;


//Train structures
typedef struct train{
    struct seat seat_node;
    char namestartstation[MAX];
    char namefinishstation[MAX];
    int hours;
    int min; 
    int sec;
} train;

typedef struct train_node{
    struct train train;
    struct seat_node seat;
    struct train_node *next;
}train_node;


//Station structures
typedef struct station{
    char name[MAX];
}station;

typedef struct station_node{
    struct train train;
    struct station station;
    struct station_node *next;
}station_node;


//functions for station_list
station_node *create_list_of_stations(char *name);
station_node *addstation(struct station_node *head,char *name);
void print_stations(struct station_node *head);

//functions for train_list
train_node *create_list_of_trains(char *namestartstation, char *namefinishstation);
train_node *addtrain(struct train_node *head,char *namestartstation, char *namefinishstation);    
void print_trains(struct train_node *head);
void print_trains_available(train_node *head, char *station);


//function for seats
seat_node *create_list_of_seats();
seat_node *reserve_seat(seat_node *headlistofseats, char *seat, char *nameofpassenger,train_node *headoftrains);
void print_seats(seat_node *headlistofseats);
//void print_train_model();
void print_train_model(seat_node *headlistofseats, train_node *train);
void print_interface_options(station_node *head,train_node*headtrain,seat_node *headlistofseats);
//time
void print_current_time();
void print_train_time(train_node *headoftrains);
#endif