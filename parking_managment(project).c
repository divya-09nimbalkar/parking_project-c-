#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int bus_slot = 15, car_slot = 15, bike_slot = 20, auto_slot = 15;  // this is used for how many vehicle can  parked operations
int earnings = 0, bus_count = 0, car_count = 0, bike_count = 0, auto_count = 0;   //this is used for to check parking insight and earning
int index1 = 0, index2 = 0, index3 = 0;
struct customer // defining structure
{
    char customerName[10][20], date[10][13];   //multi-dimentional aaray
    int vehicleNumber[10];
} data;                                    
void print_receipt(int fees)
{              //this function use to print receipt
    printf("\n\t\t-------------------------------------------------------------------------");
    printf("\n\t\t|\t\t\t\tHere you receipt!\t\t\t|\n\t\t-------------------------------------------------------------------------");
    printf("\n\t\t\t			Name: %s\n",data.customerName[index1]);
    printf("\t\t\t			Vehicle numebr: %d\n", data.vehicleNumber[index2]);
    printf("\t\t\t			Date: %s\n", data.date[index3]);
    printf("\t\t\t			Your Fees :%d\n\t\t-------------------------------------------------------------------------", fees);
}
void bus_park()
{               //this function use to handle bus parking operations
    int fees;
    printf("\t\t\tEnter your name: ");
    fflush(stdin);
    gets(data.customerName[index1]);
    printf("\t\t\tEnter vehicle number: ");
    scanf("%d", &data.vehicleNumber[index2]);
    printf("\t\t\tEnter today's date: ");
    fflush(stdin);
    gets(data.date[index3]);
repeat:
    printf("\t\t\tPlease enter fees: ");
    scanf("%d", &fees);
    if (fees < 200 || fees > 200)
    {
        printf("\t\t\tPlease enter valid amount");
        goto repeat;
    }
    else
    {
        earnings = earnings + fees;
        printf("\n\t\t********************Your payment is successfully done********************\n");
    }
    print_receipt(fees);
    index1++;
    index2++;
    index3++;
    bus_count++;
}
void car_park()
{                    //this function use to handle car parking operations
    int fees;
    printf("\t\t\tEnter your name: ");
    fflush(stdin);
    gets(data.customerName[index1]);
    printf("\t\t\tEnter vehicle number: ");
    scanf("%d", &data.vehicleNumber[index2]);
    printf("\t\t\tEnter today's date: ");
    fflush(stdin);
    gets(data.date[index3]);
repeat:
    printf("\t\t\tEnter parking fees: ");
    scanf("%d", &fees);
    if (fees < 150 || fees > 150)
    {
        printf("\t\t\tPlease enter valid amount");
        goto repeat;
    }
    else
    {
        earnings = earnings + fees;
        printf("\n\t\t**********************Your payment is successfully done********************\n");
    }
    print_receipt(fees);
    index1++;
    index2++;
    index3++;
    car_count++;
}
void bike_park()
{               //this function use to handle bike parking operations
    int fees;
    printf("\t\t\tEnter your name: ");
    fflush(stdin);
    gets(data.customerName[index1]);
    printf("\t\t\tEnter vehicle number: ");
    scanf("%d", &data.vehicleNumber[index3]);
    printf("\t\t\tEnter today's date: ");
    fflush(stdin);
    gets(data.date[index3]);
repeat:
    printf("\t\t\tEnter parking fees: ");
    scanf("%d", &fees);
    if (fees < 50 || fees > 50)
    {
        printf("\t\t\tPlease enter valid amount");
        goto repeat;
    }
    else
    {
        earnings = earnings + fees;
        printf("\n\t\t******************Your payment is successfully done*********************\n");
    }
    print_receipt(fees);
    index1++;
    index2++;
    index3++;
    bike_count++;
}
void auto_park()
{                 //this function use to handle auto parking operations
    int fees;
    printf("\t\t\tEnter your name: ");
    fflush(stdin);
    gets(data.customerName[index1]);
    printf("\t\t\tEnter vehicle number: ");
    scanf("%d", &data.vehicleNumber[index2]);
    printf("\t\t\tEnter today's date: ");
    fflush(stdin);
    gets(data.date[index3]);
repeat:
    printf("\t\t\tEnter parking fees: ");
    scanf("%d", &fees);
    if (fees < 100 || fees > 100)
    {
        printf("\t\t\tPlease enter valid amount");
        goto repeat;
    }
    else
    {
        earnings = earnings + fees;
        printf("\n\t\t****************Your payment is successfully done********************\n");
    }
    print_receipt(fees);
    index1++;
    index2++;
    index3++;
    auto_count++;
}
void park_vehicle()
{                   //this function use to handle parking operations
    int choose;
again:
    printf("\n\t\t\t1.Bus                     2.Car\n");
    printf("\t\t\t3.Bike                    4.Auto\n");
    printf("\n\t\t\tWhich vehicle you want to park: ");
    scanf("%d", &choose);
    switch (choose)
    {
    case 1:
        if (bus_slot == 0)
        {
            printf("\nSorry! Bus parking slot is not available\n");
        }
        else
        {
            bus_park();
            bus_slot--;
        }
        break;
    case 2:
        if (car_slot == 0)
        {
            printf("\nSorry! Car parking slot is not available\n");
        }
        else
        {
            car_park();
            car_slot--;
        }
        break;
    case 3:
        if (bike_slot == 0)
        {
            printf("\nSorry! Bike parking slot is not available\n");
        }
        else
        {
            bike_park();
            bike_slot--;
        }
        break;
    case 4:
        if (auto_slot == 0)
        {
            printf("\nSorry! Auto parking slot is not available\n");
        }
        else
        {
            auto_park();
            auto_slot--;
        }
        break;
    default:
        printf("Invalid number try again\n");
        goto again;
    }
}
void check_vehicle()
{                //This function use to check your vehicle is available or not
    char customerName1[20], date1[13];
    int vehicleNumber;
    int i = 0, check1, check2, check3;
    printf("\n\t\t\tPlease enter some details\n");
    printf("\t\t\tEnter Name: ");
    fflush(stdin);
    gets(customerName1);
    printf("\t\t\tEnter vehicle number: ");
    scanf("%d", &vehicleNumber);
    printf("\t\t\tEnter date: ");
    fflush(stdin);
    gets(date1);
    while (1)
    {
        check1 = strcmp(customerName1, data.customerName[i]);
        check3 = strcmp(date1, data.date[i]);
        if (vehicleNumber == data.vehicleNumber[i])
        {
            check2 = 0;
        }
        if (check1 == 0 && check2 == 0 && check3 == 0)
        {
            printf("\n\t\t\tYour vehicle is available here\n");
            break;
        }
        else
        {
            if (index1 == 9)
            {
                printf("\nSorry! your vehicle is not available here\n");
                break;
            }
        }
        i++;
    }
}
void check_insight()
{                      //This function use to check parking insight
    printf("\n******Today's insight******\n");
    printf("Total Bus parked: %d\n", bus_count);
    printf("Total Car parked: %d\n", car_count);
    printf("Total Bike parked: %d\n", bike_count);
    printf("Total Auto parked: %d\n", auto_count);
     printf("Total earnings: %d\n", earnings);
}
void main()
{                   //This function use to handle start menu
    int choose;
    do
    {
        printf("\n\n\n\n\n\t\t**************** Welcome to High Rise  parking stand ********************");
        printf("\n\t\t*\t\t\t\t\t\t\t\t\t*");
        printf("\n\t\t*\t\t\tThis is vehicle fees chart\t\t\t*");
        printf("\n\t\t*\t\t\t\t\t\t\t\t\t*");
        printf("\n\t\t*\t\tBus fees=200               Car fees=150 \t\t*");
        printf("\n\t\t*\t\tBike fees=50               Auto fees=100\t\t*");
        printf("\n\t\t*\t\t\t\t\t\t\t\t\t*");
        printf("\n\t\t*\tEnter 1 for park your vehicle\t\t\t\t\t*");
        printf("\n\t\t*\t\t\t\t\t\t\t\t\t*");
        printf("\n\t\t*\tEnter 2 for check your vehicle\t\t\t\t\t*");
        printf("\n\t\t*\t\t\t\t\t\t\t\t\t*");
        printf("\n\t\t*\tEnter 3 for show today insight\t\t\t\t\t*");
        printf("\n\t\t*\t\t\t\t\t\t\t\t\t*");
        printf("\n\t\t*\tEnter 4 for exit\t\t\t\t\t\t*");
        printf("\n\t\t*\t\t\t\t\t\t\t\t\t*");
        printf("\n\t\t*-----------------------------------------------------------------------*");
    again:
        printf("\n\t\t\t\tPlease choose any option: ");
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            park_vehicle();
            break;
        case 2:
            check_vehicle();
            break;
        case 3:
            check_insight();
            break;
        case 4:
            printf("\n\t\t\t****** Thank you for using our parking stand *******\n");
            exit(0);
            break;
        default:
            printf("Invalid number try again\n");
            goto again;
            break;
        }
    } while (choose != 4);
}
