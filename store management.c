//store management system
#include <stdio.h>
#include<stdlib.h>
#include<conio.h>

void addproduct();
void addemployee();
void addregular();
void productrecord();
void employeerecord();
void regularrecord();
void searchpro();
void searchreg();
void delete();
void billing();
void cls();

//inventory of products in store
struct pro{
    char name[30];
    int code;
    int price;
    int quantity;
    float discount;
};

 //details of employees in store
 struct emp{
    char fname[30];
    char lname[30];
    char position[30];
    long long int contact;
};

//regular customers data
struct reg{
    char finame[30];
    char laname[30];
    long long int contactno;
};

//main code begins to print menu
int main(){
int choice;

while(choice!=10){
        printf("\n\t====================STORE MANAGEMENT SYTEM====================");
        printf("\n\t\t\t\tINVENTORY MANAGER");
        printf("\n\t\t\t\t1.add new product");
        printf("\n\t\t\t\t2.view product records");
        printf("\n\t\t\t\t3.search product by product code");
        printf("\n\t\t\t\t4.delete a product");
        printf("\n\n\t\t\t\tEMPLOYEES MANAGER");
        printf("\n\t\t\t\t5.add new employee");
        printf("\n\t\t\t\t6.view employee records"); 
        printf("\n\n\t\t\t\tREGULAR CUSTOMER MANAGER");
        printf("\n\t\t\t\t7.add new regular customer");
        printf("\n\t\t\t\t8.view regular customer records");
        printf("\n\t\t\t\t9.search regular customer by phone no");
        printf("\n\n\t\t\t\tBILLING");
        printf("\n\t\t\t\t0.billing");
        printf("\n\n\t\t\t\t10.EXIT\n");
        printf("\n\t_______________________________________________________________\n");
        scanf("\n%d",&choice);
       
        switch (choice){
            case 1:
              //to add a new product and its detail in the inventory
              cls();
              addproduct();
              cls();
            break;
            
            case 2:
              //to display all the products and their details in inventory
              productrecord();
              printf("\t\t\t\t  press any key to exit..... \n");
              getch();
              cls();
            break;
           
            case 3:
              cls();
              //to search product by product code enetered by user
              searchpro();
              printf("\n\t\t\t\t  Press any key to exit.......\n");
              getch();
              cls();
            break;
           
            case 4:
              cls();
              //delete a given product and its details by inputting product code
              delete();
              printf("\n\t\t\t\tPress any key to exit.......\n");
              getch();
              cls();
              break;

            case 5:
              cls();
              //add a new employee and their details
              addemployee();
              cls();
            break;

            case 6:
              //to add a new employee and its details
              employeerecord();
              printf("\t\t\t\t  press any key to exit..... \n");
              getch();
              cls();
            break;

            case 7:
              cls();
              //to add new regular customer and their details
              addregular();
              cls();
            break;

            case 8:
              //to display regular customers records 
              regularrecord();
              printf("\t\t\t\t  press any key to exit..... \n");
              getch();
              cls();
              break;

            case 9:
              cls();
              //to search the details of regular customer by their contact no
              searchreg();
              printf("\n\t\t\t\t  Press any key to exit.......\n");
              getch();
              cls();
              break;
            
            case 10:
            break;

            case 0:
              cls();
              //billing
              billing();
              cls();
              break;

            default:
              //if user enters a value other than 1-10
              printf("INVALID CHOICE!\n");
              break;
            }
        }

    return 0;
}

/* Clearing the output screen */
void cls(){
    #ifdef _linux_
    /* If the user's OS is linux based */
        system("clear");
    #else
    /* If the user's OS is Windows */
        system("cls");
    #endif
}

//addition of new product's information in inventory
void addproduct(){

    FILE *fptr;
    struct pro p;
    char another;
    
    do{
        cls();
        printf("\t\t\t\t=======Add Product's Info=======\n\n\n"); 
        fptr = fopen("pro.txt", "a");  

        printf("\n\t\t\t\tenter product code :");
        scanf("%d",&p.code);

        printf("\n\t\t\t\tenter product name :");
        fflush(stdin);  //clearing the input stream
        gets(p.name);
    
        printf("\n\t\t\t\tenter product price :");
        scanf("%d",&p.price);
    
        printf("\n\t\t\t\tenter product discount :");
        scanf("%f",&p.discount);
    
        printf("\n\t\t\t\tenter product quantity :");
        scanf("%d",&p.quantity);
        printf("\n\t\t______________________________\n");
        
        //checking if file exists in the given location
        if(fptr==NULL){
            printf("file doesn't exist");
            exit(1);
            }
        //storing values in file
        fwrite(&p,sizeof(struct pro),1,fptr);
        fclose(fptr);
        printf("\n");
        printf("\n\t\t\t\trecord sucessfully saved");
        //if user wishes to enter another record
        printf("\n\t\t\tYou want to add another record?(y/n) : ");
        scanf("%s",&another);
        printf("\n");
    }
    
    while(another=='y'||another=='Y');
}

//to add new employee details to existing database
void addemployee(){
    
    FILE *fptr;
    struct emp e;
    char another;
    
    do{
        cls();
        printf("\t\t\t\t=======Add Employee's Info=======\n\n\n"); 
        fptr = fopen("empl.txt", "a");

        printf("\n\t\t\t\tenter first name :");
        fflush(stdin);  // Clearing the input stream
        gets(e.fname);

        printf("\n\t\t\t\tenter last name :");
        fflush(stdin);  // Clearing the input stream
        gets(e.lname);
    
        printf("\n\t\t\t\tenter postion :");
        fflush(stdin);  // Clearing the input stream
        gets(e.position);
    
        printf("\n\t\t\t\tenter contact no :");
        scanf("%lld",&e.contact);
        printf("\n\t\t______________________________\n");

        //checking if file exists in the given location
        if(fptr==NULL)
        {
           printf("file doesn't exist");
           exit(1);
        }
        //storing values in file
        fwrite(&e,sizeof(struct emp),1,fptr);
        fclose(fptr);

        printf("\n");
        printf("\n\t\t\t\trecord sucessfully saved");
        //if user wishes to enter another record
        printf("\n\t\t\tYou want to add another record?(y/n) : ");
        scanf("%s",&another);
        printf("\n");

    }

    while(another=='y'||another=='Y');
}

//to add new regular customer details to existing database
void addregular(){

    FILE *fptr;
    struct reg r;
    char another;

    do
    {
        cls();
        printf("\t\t\t\t=======Add Regular Customer's Info=======\n\n\n"); 
        fptr = fopen("reg.txt", "a");   
        printf("\n\t\t\t\tenter first name :");
        fflush(stdin);  // Clearing the input stream
        gets(r.finame);

        printf("\n\t\t\t\tenter last name :");
        fflush(stdin);  // Clearing the input stream
        gets(r.laname);
    
        printf("\n\t\t\t\tenter conatct number :");
        fflush(stdin);  // Clearing the input stream
        scanf("%lld",&r.contactno);
        printf("\n\t\t______________________________\n");

        //checking if file exists in the given location
        if(fptr==NULL)
        {
            printf("file doesn't exist");
            exit(1);
        }

       //storing values in file
       fwrite(&r,sizeof(struct reg),1,fptr);
       fclose(fptr);
       printf("\n");
       printf("\n\t\t\t\trecord sucessfully saved");
       
       //if user wishes to enter another record
       printf("\n\t\t\tYou want to add another record?(y/n) : ");
       scanf("%s",&another);
       printf("\n");
    }

    while(another=='y'||another=='Y');
}

//displaying of inventory
void productrecord(){

    FILE *fptr;

    fptr=fopen("pro.txt","r");
    printf("\t\t\t\t=======PRODUCTS RECORD=======\n\n\n");

    //checking if file exists in the given location
    if(fptr==NULL)
    {
        printf("can't open file\n");
        exit(1);
    }
    else
    {
        printf("\t\t\t\tRECORDS :\n");
        printf("\t\t\t\t___________\n\n");
    }

    while(1){
        struct pro p;
        fread(&p, sizeof(struct pro), 1,fptr);

        //on loop until end of file is reached
        if ( feof(fptr) ){
                        fclose(fptr);
                        return;
                    }

        //displaying all stored details of a product 
        printf("\n\t\t\t\t Code          : %d",p.code);
        printf("\n\t\t\t\t Product Name  : %s",p.name);
        printf("\n\t\t\t\t Price         : %d",p.price);
        printf("\n\t\t\t\t Discount      : %f",p.discount);
        printf("\n\t\t\t\t Quantity      : %d",p.quantity);
        printf("\n\t\t\t\t ________________________________\n");
        
    }
}

//add a new employee and their details to existing database
void employeerecord(){

   FILE *fptr;
   fptr=fopen("empl.txt","r");

   printf("\t\t\t\t=======EMPLOYEE'S RECORD=======\n\n\n");
      
      if(fptr==NULL){
        //checking if file exists in the given location
        printf("can't open file\n");
        exit(1);
    }
    else
    {
        printf("\t\t\t\tRECORDS :\n");
        printf("\t\t\t\t___________\n\n");
    }
    while(1)
    {
        struct emp e;
        fread(&e, sizeof(struct emp), 1,fptr);

        //on loop until end of file is reached
        if ( feof(fptr) ){
                        fclose(fptr);
                        return;
                    }

        //displaying all stored details of an employee            
        printf("\n\t\t\t\t Fisrt Name    : %s",e.fname);
        printf("\n\t\t\t\t Last Name     : %s",e.lname);
        printf("\n\t\t\t\t Position      : %s",e.position);
        printf("\n\t\t\t\t Contact       : %lld",e.contact);
        printf("\n\t\t\t\t ________________________________\n");
    }
}

//to veiw the details of regular empolyee stored by user
void regularrecord(){
    
    FILE *fptr;
    fptr=fopen("reg.txt","r");
    
    printf("\t\t\t\t=======REGULAR CUSTOMER'S RECORD=======\n\n\n");
      
    //checking if file exists in the given location
    if(fptr==NULL)
        {
        fprintf(stderr,"can't open file\n");
        exit(0);
        }
    else
        {
        printf("\t\t\t\tRECORDS :\n");
        printf("\t\t\t\t___________\n\n");
        }
    while(1){

        struct reg r;
        fread(&r, sizeof(struct reg), 1,fptr);

        //on loop until end of file is reached
        if ( feof(fptr) ){
                        fclose(fptr);
                        return;
                    }

        //displaying all stored details of a regular customer
        printf("\n\t\t\t\t Fisrt Name    : %s",r.finame);
        printf("\n\t\t\t\t Last Name     : %s",r.laname);
        printf("\n\t\t\t\t Contact       : %lld",r.contactno);
        printf("\n\t\t\t\t ________________________________\n");
    }
}

//to search product by product code entered by user and display its details
void searchpro(){
    
    struct pro p;
    FILE *fptr;
    int p_code,found=0;
     
    fptr=fopen("pro.txt","r");
    printf("\t\t\t\t=======Search Products Record=======\n\n\n");
    
    printf("\t\t\tEnter the product code : ");
    scanf("%d",&p_code);
    
    while(fread(&p,sizeof(struct pro),1,fptr)>0){

        //comparing to find a product code matching as that entered by user 
        if(p.code==p_code)
        {
            found=1;
            printf("\n\n\t\t\tProduct Code : %d",p.code);
            printf("\n\t\t\tProduct Name   : %s",p.name);
            printf("\n\t\t\tPrice          : %d",p.price);
            printf("\n\t\t\tDiscount       : %f",p.discount);
            printf("\n\t\t\tQuantity       : %d",p.quantity);
            printf("\n\t\t\t______________________________________\n");
        }
    }
    //if the product code entered by the user is not in inventory    
    if(!found)
    {
       printf("\n\t\t\tRecord not found\n");
    }
    fclose(fptr);
}

//to search a regular customer entered by user and display their full name
void searchreg(){

    struct reg r;
    FILE *fptr;

    long long int r_no;
    int found=0;
     
    fptr=fopen("reg.txt","r");
    printf("\t\t\t\t=======Search Regulars Record=======\n\n\n");
    
    printf("\t\t\tEnter the contact no : ");
    scanf("%lld",&r_no);
    
    while(fread(&r,sizeof(struct reg),1,fptr)>0){

        //comparing to find a contact no. matching as that entered by user  
        if(r.contactno==r_no){
           
        found=1;
        printf("\n\n\t\t\tContact NO: %lld",r.contactno);
        printf("\n\t\t\tName        : %s %s",r.finame,r.laname);
        printf("\n\t\t\t______________________________________\n");
        }
    }
    //if the product code entered by the user is not in inventory 
    if(!found)
    {
       printf("\n\t\t\tRecord not found\n");
    }
    fclose(fptr);
}

//to delete a product and its information from inventory records
void delete(){

    struct pro p;
    FILE *fptr, *fp;
    int p_code,found=0;
    
    printf("\t\t\t\t=======DELETE PRODUCTS RECORD=======\n\n\n");
    //opening orignal file in read mode and temporary file in write mode to make copy of all expect the product to be deleted
    fptr=fopen("pro.txt","r");
    fp=fopen("temp.txt","w");

    printf("\t\t\t\tEnter product code : ");
    scanf("%d",&p_code);
    //checking if file exists in the given location
    if(fptr==NULL)
    {
        printf("can't open file\n");
         exit(1);
    }
    
    while(fread(&p,sizeof(struct pro),1,fptr))
    {   //comparing to find a product code matching as that entered by user  
        if(p.code == p_code)
        {
           found=1;
        }
        else
        {   //copying data if not matched to another file
            fwrite(&p,sizeof(struct pro),1,fp);
        }
    }
    fclose(fptr);
    fclose(fp);

    if(!found)
    {   //the product code to be deleted doesnt exist in the inventory
        printf("\n\t\t\t\tRecord not found\n");
    }
    if(found)
    {   //removing orignal file containing all the records
        remove("pro.txt");
        //the new file with a deleted record is renamed to replace orignal 
        rename("temp.txt","pro.txt");
        
        printf("\n\t\t\t\tRecord deleted succesfully\n");
    }
}
  
//automated discounted bill generation by entering product code and quantity to be bought by customer
void billing(){

    FILE *fptr;
    struct pro p;
    float bill=0;
    char another;
    int p_code, quantity, found=0;

    fptr=fopen("pro.txt","r");
    printf("\t\t\t\t=======BILLING WINDOW=======\n\n\n");

    //checking if file exists in the given location
    if(fptr==NULL)
        {
            printf("can't open file\n");
            exit(1);
        }
    fclose(fptr);
    
    do{
        printf("\n\t\t\tEnter the product code    : ");
        scanf("%d",&p_code);

        printf("\t\t\tEnter quantity of product : ");
        scanf("%d",&quantity);

        fptr=fopen("pro.txt","r");

        while(fread(&p,sizeof(struct pro),1,fptr)>0)
        {
            if(p.code==p_code){
                found=1;
                bill=bill+(p.price*((100-p.discount)/100))*quantity;
                fclose(fptr);
            }
        }
        //if the product code entered is invalid
        if(!found){
            printf("\n\t\t\tRecord not found\n");
            fclose(fptr);
        }
        //if user wishes to purchase another product 
        printf("\n\t\t\tYou want to add another product?(y/n) : ");
        found=0;
        scanf("%s",&another);
        printf("\n");
    }

    while(another=='y'||another=='Y');
    
    //total billing amount to be paid after applying all discounts
    printf("\n\t\t\tTotal Billing Amount       : %f",bill);
    printf("\n\t\t\t______________________________________\n");
    printf("\n\t\t\t\tTHANKS! VISIT AGAIN!");
    printf("\n\t\t\t______________________________________\n");

    printf("\n\t\t\t\tpress any key to exit.");
    getch();
}