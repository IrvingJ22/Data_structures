#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <sys/stat.h>



typedef struct ticket {
    char name_participant[15];
    int number_ticket;
} Ticket;


int random_number(){
    srand(time(NULL));
    int number = rand() % 51 + 1;
    return number;
}

int binary_search_recursive(Ticket array[], int left, int right, int obejtive){
    if(right >= left){
        int half = left + (right - left)/2;
        if(array[half].number_ticket ==obejtive){
            return half;
        }
        if(array[half].number_ticket >obejtive){
            return binary_search_recursive(array, left, half-1, obejtive);
        }
        return binary_search_recursive(array, half+1, right, obejtive);
    }
    return -1;
}




int len_array(int array[]){
    int size_of_array = sizeof(array);
    int size_of_first_element = sizeof(array[0]);
    int len = size_of_array / size_of_first_element;
    return len;
}

int main(){
    Ticket tickets[50];
    int winning_ticket;
    


    for(int i=0; i<50; i++){
        tickets[i].number_ticket = i+1;
    }


    strcpy(tickets[0].name_participant, "Alberto");
    strcpy(tickets[1].name_participant, "David");
    strcpy(tickets[2].name_participant, "Juan");
    strcpy(tickets[3].name_participant, "Monica");
    strcpy(tickets[4].name_participant, "Sebastian");
    strcpy(tickets[5].name_participant, "Esmeralda");
    strcpy(tickets[6].name_participant, "Carolina");
    strcpy(tickets[7].name_participant, "Angel");
    strcpy(tickets[8].name_participant, "Irving");
    strcpy(tickets[9].name_participant, "Ernesto");
    strcpy(tickets[10].name_participant, "Vanessa");
    strcpy(tickets[11].name_participant, "Josmar");
    strcpy(tickets[12].name_participant, "Maria");
    strcpy(tickets[13].name_participant, "Lucas");
    strcpy(tickets[14].name_participant, "Rodrigo");
    strcpy(tickets[15].name_participant, "Jafet");
    strcpy(tickets[16].name_participant, "Hanna");
    strcpy(tickets[17].name_participant, "Sin Asignar");
    strcpy(tickets[18].name_participant, "Sin Asignar");
    strcpy(tickets[19].name_participant, "Jacobo");
    strcpy(tickets[20].name_participant, "Noe");
    strcpy(tickets[21].name_participant, "Norma");
    strcpy(tickets[22].name_participant, "Santana");
    strcpy(tickets[23].name_participant, "Luisa");
    strcpy(tickets[24].name_participant, "Maaria");
    strcpy(tickets[25].name_participant, "Sin Asignar");
    strcpy(tickets[26].name_participant, "Sin Asignar");
    strcpy(tickets[27].name_participant, "Lorena");
    strcpy(tickets[28].name_participant, "Diego");
    strcpy(tickets[29].name_participant, "Sin Asignar");
    strcpy(tickets[30].name_participant, "Cynthia");
    strcpy(tickets[31].name_participant, "Gerardo");
    strcpy(tickets[32].name_participant, "Issac");
    strcpy(tickets[33].name_participant, "Ruben");
    strcpy(tickets[34].name_participant, "Harumi");
    strcpy(tickets[35].name_participant, "Moises");
    strcpy(tickets[36].name_participant, "Sin Asignar");
    strcpy(tickets[37].name_participant, "Sin Asignar");
    strcpy(tickets[38].name_participant, "Jesus");
    strcpy(tickets[39].name_participant, "Tom");
    strcpy(tickets[40].name_participant, "Yamile");
    strcpy(tickets[41].name_participant, "Adriana");
    strcpy(tickets[42].name_participant, "Sin Asignar");
    strcpy(tickets[43].name_participant, "Sin Asignar");
    strcpy(tickets[44].name_participant, "Saul");
    strcpy(tickets[45].name_participant, "Luis");
    strcpy(tickets[46].name_participant, "Mario");
    strcpy(tickets[47].name_participant, "Brandon");
    strcpy(tickets[48].name_participant, "Fernanda");
    strcpy(tickets[49].name_participant, "Sin Asignar");

    do{
        winning_ticket = random_number();
    }while(strcmp(tickets[winning_ticket].name_participant, "Sin Asignar") == 0);

    printf("El boleto %d es el ganador",winning_ticket);

    int result = binary_search_recursive(&tickets->number_ticket, 0, len_array(&tickets->number_ticket), winning_ticket);
    printf("\nresult = %d", result + winning_ticket);
    

    printf("\nEl gandor es: %s \n", tickets[result + winning_ticket].name_participant);
    

    return 0;
}