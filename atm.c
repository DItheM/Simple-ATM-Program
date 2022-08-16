#include <stdio.h>
#include <stdbool.h>

int pin_in ;
int pin = 1234 ;
bool isPinChecked ;
int value ;
int con_val;
bool isConfirmed ;


//check the pin is correct
bool pin_check () {

    printf("\n\nType your pin --> ");
    scanf("%d", &pin_in);

    if (pin == pin_in) {
        isPinChecked = true ;
    } else {
        isPinChecked = false ;
        
    }

    return isPinChecked ;    
}

//continue pin enter 2 times if pin wrong
void pin_wrong () {
    for (int i = 1 ; i < 3 ; i++) {
        if (isPinChecked == false) {
            printf("Entered pin is incorrect [%d]", i);
            pin_check();
        } 
    }
    if (isPinChecked == true) { 
        printf("Entered PIN is correct...");
    }
}

//getting transfer amount
int trans_value () {
    printf("\n\nType the value you want --> ");
    scanf("%d", &value);
    printf("You entered : Rs.%d", value);
    return value ;

}

//confirm the transfer
bool confirm () {
    printf("\n\nDo you want to continue");
    printf("\nConfirm(Yes as '1' and No as 'any number') --> ");
    scanf("%d", &con_val);

    if (con_val == 1) {
        isConfirmed = true ;
    } else {
        isConfirmed = false ;
    }

    return isConfirmed ;

}

//end the programme or start again
void end_cont () {
    printf("\n\nType 'any number' to end or '1' to start again --> ");
    scanf("%d", &con_val);
    printf("\n\n------------------------------------------------------");
}

//main function
int main () {
    do {
        pin_check();
        pin_wrong();
        if (isPinChecked == true) {
            trans_value();
            confirm();

            if(isConfirmed == true) {
                printf("\nTranfer Completed!! \n Transfered amount : Rs.%d\n\nThank You!", value);
            } else {
                printf("\n\nThank You!");
                printf("\n\n------------------------------------------------------");
            }
        } else {
            printf("\nEntered PIN is incorrect [3], please try again....");
            printf("\n\n------------------------------------------------------");
        }
        end_cont(); 
    } while (con_val == 1);   
    return 0;
}

