#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<time.h>
#include<windows.h>

typedef struct
{
    char name[100];
    int code;
    int quantity;
    float price;
}product;

struct login{

    char fname[100];
    char lname[20];
    char username[20];
    char password[20];
};
//global variable
double total_amount = 0;
char name[100];
int g;
int n;
//website name
title()
{
        system("COLOR 0A");
        int i = 0;
        while (i <= 100)
        {
            printf(" ");
            i++;
            if(i==1)
            {
                printf("\n\n");
            }
            if (i == 50)
            {
                printf("Welcome to sell.com\n");
                printf("\t\t\t\t\t\t*********************\n");
                break;
            }
        }
}

//if manager put wrong info in manager information page
wrong()
{
                again:
                printf("\n\n\tPress Q to go back previous page: ");
                fflush(stdin);
                char m;
                scanf("%c",&m);
                //tolower(m);
                if(m=='q' || m == 'Q')
                {
                 Sleep(100);
                }
                else
                {
                    printf("\n\tWrong Input! Please try again.\n");
                    goto again;
                }
                system("CLS");
}
//Discount
double Discount(double sum)
{
    double dis;
    if(sum>=1000 && sum<2000)
    {
        dis = 0.10;
    }
    else if(sum>=2000 && sum<4000)
    {
        dis = 0.15;
    }
    else if(sum>=4000 && sum<6000)
    {
        dis = 0.20;
    }
    else if(sum>=6000 && sum<8000)
    {
        dis = 0.30;
    }
    else if(sum>=8000)
    {
        dis = 0.40;
    }
    else
    {
        dis = 0;
    }
    return dis;
}

//total amount
total()
{
        printf("\tYour Total: %.02lf\n",total_amount);
        double discount;
        discount = Discount(total_amount);
        printf("\tDiscount: %.02lf%c\n",(discount*100),'%');
        printf("\tAmount to pay: %.02lf Taka\n", total_amount - discount*total_amount);
        printf("\tDelivery charge 80taka\n\n");
        printf("\tTotal payment(with delivery charge): %.02lf taka\n ",(total_amount - discount*total_amount)+80);
        FILE *productfile;
        productfile=fopen("result.txt","a");
        if(productfile == NULL)
        {
            printf("Error!!\n");
            exit (1);
        }

        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        fprintf(productfile,"\t\t\t%s\t %0.2lf \t%d-%02d-%02d %02d:%02d:%02d\n", name,total_amount,tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
        fclose(productfile);
}

//after complete the purchasing for manager
manager()
{
        printf("\tIf you want go back to main page then press y(Yes) or any character to exit..\n\nEnter your choice: ");
        char y;
        scanf("%s",&y);
        tolower(y);
        if(y=='y')
        {
            system("CLS");
            admin();
        }
        else
        {

        }
}
//after complete the purchasing for customer
custom()
{
        printf("\tIf you want go back to main page then press y(Yes) or n(No) to exit..\n\nEnter your choice: ");
        char y;
        scanf("%s",&y);
        tolower(y);
        if(y=='y')
        {
            system("CLS");
            admin();
        }
        else
        {

        }
}

//for sign up
registe()
{
    FILE *log;
    log=fopen("login12.txt","w");
    struct login l;
    title();
    printf("\n\n\n\t\t\t\tEnter first name: ");
    scanf("%s",l.fname);
    printf("\t\t\t\tEnter Last name: ");
    scanf("%s",l.lname);
    printf("\t\t\t\tEnter user name: ");
    scanf("%s",l.username);
    printf("\t\t\t\tEnter password: ");
    scanf("%s",l.password);
    fwrite(&l,sizeof(l),1,log);

    fclose(log);
    Sleep(600);
    printf("\n\t\t\t\tWait for a moment..");
    Sleep(600);
    printf("\n\n\tYour user name is your UserID\n");
    printf("\tNow sign in with your UserID and Password\n\n");
    printf("\tPress any key to continue...");
    getch();
    system("CLS");
    login();

}
//for sign in
login()
{
    char username[200],password[20];
    FILE *log;
    log=fopen("login12.txt","r");
    struct login l;
    user:
    system("CLS");
    title();
    printf("\n\n\n\n");
    printf("\t\t\t\tUSER ID: ");
    scanf("%s",&username);
    printf("\t\t\t\tPASSWORD: ");
    scanf("%s",&password);
    while(fread(&l,sizeof(l),1,log))
    {
        if(strcmp(username,l.username)==0 && strcmp(password,l.password)==0)
        {
            printf("\n\t\t\t\tWait for a moment..\n\n");
            Sleep(800);
            printf("\n\t\t\t\tSuccessful login\n");
            Sleep(1000);
        }
        else
        {
            printf("\n\t\t\t\tWait for a moment..\n\n");
            Sleep(600);
            printf("\t\t\t\tPlease enter correct userID and password\n");
            Sleep(1100);
            goto user;
        }
    }

    fclose(log);
}

//manager after sign in
logi()
{
    title();
    printf("\n\n");
    printf("\t\t\t\t\tHello manager, Welcome back!\n\n");
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("\t\t\t\t\tYou are logging in : %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    printf("\n\nPress any key to continue..\n");
    getch();
}

//manager funtion
admin()
{
    system("CLS");
    star:
    start:
    title();
    printf("\t\t\t\tIf you want to know about company information then press < 1 >\n");
    printf("\t\t\t\tIf you want to buy something then press < 2 >\n\n");
    printf("\t\t\t\tEnter you choice: ");
    scanf("%d", & n);
    system("CLS");
    //Manager page
    if(n==1)
    {
    /*-------------------------------Product file(manager)-------------------------------*/
        while(1)
        {
        title();
        printf("\n\n");
        printf("\t\t\t\tPress < 0 > for go back to the main page.\n");
        printf("\t\t\t\tPress < 1 > for man collection\n");
        printf("\t\t\t\tPress < 2 > for woman collection\n");
        printf("\t\t\t\tPress < 3 >for see the today's sell chart.\n\n");
        int x;
        printf("\t\tEnter you choice: ");
        scanf("%d",&x);
        fflush(stdin);
        while(1)
        {
            if (x == 1)
            {
                system("CLS");
                FILE *productfile;
                product input;
                productfile = fopen("men.txt","r");
                if(productfile == NULL)
                {
                    printf("Error!!\n");
                    exit (1);
                }
                int count = 0;
                product shop_product[100];
                while(1)
                {
                    int status = fscanf(productfile,"%s %d %d %f", &shop_product[count].name,
                                &shop_product[count].code,&shop_product[count].quantity,
                                &shop_product[count].price);
                    if(status == -1)
                        {
                            break;
                        }
                    count++;
                }
                fclose(productfile);
                title();
                printf("\n\n\t\tHere is list of product of man collection in our shop:\n\n");
                int i;
                for(i = 0 ; i <count ;i++)
                {
                    printf("\t\t\t%s\t%d\t%d\t%.2f",shop_product[i].name,shop_product[i].code,shop_product[i].quantity,shop_product[i].price);
                    printf("\n\n");
                }
                fclose(productfile);
                wrong();

                break;
            }
            else if(x==2)
            {
                system("CLS");
                FILE *productfile;
                product input;
                productfile = fopen("women.txt","r");
                if(productfile == NULL)
                {
                    printf("Error!!\n");
                    exit (1);
                }
                int count = 0;
                product shop_product[100];
                while(1)
                {
                int status = fscanf(productfile,"%s %d %d %f", &shop_product[count].name,
                                &shop_product[count].code,&shop_product[count].quantity,
                                &shop_product[count].price);
                if(status == -1)
                    {
                        break;
                    }
                    count++;
                }
                fclose(productfile);
                title();
                printf("\n\n\t\tHere is list of product of women collection in our shop : \n\n");
                int i;
                for(i = 0 ; i <count ;i++)
                {
                    printf("\t\t\t\t%s\t%d\t%d\t%.2f",shop_product[i].name,shop_product[i].code,shop_product[i].quantity,shop_product[i].price);
                    printf("\n\n");
                }

                fclose(productfile);
                wrong();
                break;

            }
            else if (x==3)
            {
                system("CLS");
                FILE *productfile;
                product input;
                productfile = fopen("result.txt","r");
                if(productfile == NULL)
                {
                    printf("Error!!\n");
                    exit (1);
                }
                int count = 0;
                char ch;
                product shop_product[100];
                title();
                printf("\n\n\t\t\t\tHere is list of today's sell : \n\n");

                ch=fgetc(productfile);

                while(!feof(productfile))
                {
                    printf("%c",ch);
                    ch=fgetc(productfile);

                }
                fclose(productfile);
                wrong();
                break;
            }
            else if(x==0)
            {
                system("CLS");
                goto start;
            }
            else
            {
                printf("\n\tWrong input");
                Sleep(550);
                system("CLS");
                goto start;
            }

        }

        }
    }
    //Customer page
    else if(n==2)
    {
        title();
        printf("\n\t\t\tFor man collection then press < 1 >\n\t\t\tFor woman collection press < 0 >\n");
        printf("\t\t\tEnter your choice: ");
        int d;
        scanf("%d",&d);
        if(d==1)
        {
            system("CLS");
            title();
            printf("\n\n\tHello %s\n\n\tI hope you are having a good day.Welcome to sell.com Shopping.\n\n",name);
            printf("\n\t\t\t\tSpecial Offer going on!!!!!!\n\n");
            printf("\n\t\t\t\tBig Sale upto 40%c off\n\n\n",'%');

            FILE *productfile;
            product input;
            productfile = fopen("men.txt","r");
            if(productfile == NULL)
            {
                printf("Error!!\n");
                exit (1);
            }
            int count = 0;
            product shop_product[100];
            while(1)
            {
                int status = fscanf(productfile,"%s %d %d %f", &shop_product[count].name,
                                &shop_product[count].code,&shop_product[count].quantity,
                                    &shop_product[count].price);
                if(status == -1)
                {
                    break;
                }
                count++;
            }
            fclose(productfile);

            printf("\tOur Available Products : \n");
            printf("\t.............................\n\n");
            int i;
            for(i = 0 ; i <count ;i++)
            {
                printf("\t%s\t%.2f",shop_product[i].name,shop_product[i].price);
                printf("\n\n");
            }
            while(1)
            {
                char p_name[100];
                fflush(stdin);
                printf("\tEnter Product name: ");
                gets(p_name);
                int flag=0;
                int i;
                for(i=0;i<count;i++)
                {
                    if(strcmp(shop_product[i].name,p_name)==0)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)
            {
                printf("\tSorry Sir, we don't have this product right now. We will try to bring it back asap.\n");
            }
            else
            {
                int q;
                printf("\tEnter Quantity : ");
                scanf("%d",&q);
                fflush(stdin);
                if(q <= shop_product[i].quantity)
                {
                    total_amount = total_amount + q * shop_product[i].price;
                    shop_product[i].quantity = shop_product[i].quantity -q;
                }
                else
                {
                    printf("\n\n\tSorry, Sir. We don't have this amount of product right now.\n");
                }

            }
            printf("\n\tPress C for continue and others for exit\n");
            printf("\tEnter your choice: ");
            char t;
            scanf("%c",&t);
            tolower(t);
            fflush(stdin);
            if(t!= 'c')
            {
                break;
            }
        }
        productfile=fopen("men.txt","w");
        if(productfile == NULL)
        {
            printf("Error!!\n");
            exit (1);
        }
        for(i=0; i<count ; i++)
        {
            fprintf(productfile,"%s\t%d\t%d\t%.2f\n", shop_product[i].name,
                            shop_product[i].code,shop_product[i].quantity,
                            shop_product[i].price);
            printf("\n");
        }
        fclose(productfile);
        }
        else if(d==0)
        {
            system("CLS");
            title();
            printf("\n\n\tHello %s\n\n\tI hope you are having a good day.Welcome to sell.com Shopping.\n\n",name);
            printf("\n\t\t\t\tSpecial Offer going on!!!!!!\n\n");
            printf("\n\t\t\t\tBig Sale upto 40%c off\n\n\n",'%');
            FILE *productfile;
            product input;
            productfile = fopen("women.txt","r");
            if(productfile == NULL)
            {
                printf("Error!!\n");
                exit (1);
            }
            int count = 0;
            product shop_product[100];
            while(1)
            {
                int status = fscanf(productfile,"%s %d %d %f", &shop_product[count].name,
                                &shop_product[count].code,&shop_product[count].quantity,
                                    &shop_product[count].price);
                if(status == -1)
                {
                    break;
                }
                count++;
            }
            fclose(productfile);
            printf("\tOur Available Products : \n");
            printf("\t.............................\n\n");
            int i;
            for(i = 0 ; i <count ;i++)
            {
                printf("\t%s\t%.2f",shop_product[i].name,shop_product[i].price);
                printf("\n\n");
            }
            while(1)
            {
                char p_name[100];
                fflush(stdin);
                printf("\tEnter Product name: ");
                gets(p_name);
                int flag=0;
                int i;
                for(i=0;i<count;i++)
                {
                    if(strcmp(shop_product[i].name,p_name)==0)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)
            {
                printf("\t\nSorry Sir, we don't have this product right now. We will try to bring it back asap.\n");
            }
            else
            {
                int q;
                printf("\tEnter Quantity : ");
                scanf("%d",&q);
                fflush(stdin);
                if(q <= shop_product[i].quantity)
                {
                    total_amount = total_amount + q * shop_product[i].price;
                    shop_product[i].quantity = shop_product[i].quantity -q;
                }
                else
                {
                    printf("\n\tSorry, Sir. We don't have this amount of product right now\n");
                }

            }
            printf("\n\tPress C for continue and others for exit\n");
            printf("\tEnter your choice: ");
            char t;
            scanf("%c",&t);
            tolower(t);
            fflush(stdin);
            if(t!= 'c')
            {
                break;
            }
        }
        productfile=fopen("women.txt","w");
        if(productfile == NULL)
        {
            printf("Error!!\n");
            exit (1);
        }
        for(i=0; i<count ; i++)
        {
            fprintf(productfile,"%s\t%d\t%d\t%.2f\n", shop_product[i].name,
                            shop_product[i].code,shop_product[i].quantity,
                            shop_product[i].price);
            printf("\n");
        }
        fclose(productfile);
        }
    }

}

//for name after login
nam()
{
        title();
        printf("\n\t\t\tPlease Enter Your Name: ");
        scanf("%s",&name);
        system("CLS");
}
//customer main function
customer()
{
        title();
        printf("\n\n\n\n");
        printf("\t\t\tFor man collection then press < 1 >\n\t\t\tFor woman collection press < 0 >\n\n");
        printf("\t\t\t\tEnter your choice: ");
        int d;
        scanf("%d",&d);
        if(d==1)
        {
            system("CLS");
            title();
            printf("\n\n\n**********************************************************************************************************\n");
            printf("       Welcome to our shop %s, I hope you are having a good day. Welcome to our sell.com Shopping.\n\n",name);
            printf("*********************************************************************************************************\n\n");
            printf("\t\t\t\tSpecial Offer going on!!!!!!\n\n");
            printf("\t\t\t\t  Big Sale upto 40%c off\n\n",'%');

            FILE *productfile;
            product input;
            productfile = fopen("men.txt","r");
            if(productfile == NULL)
            {
                printf("Error!!\n");
                exit (1);
            }
            int count = 0;
            product shop_product[100];
            while(1)
            {
                int status = fscanf(productfile,"%s %d %d %f", &shop_product[count].name,
                                &shop_product[count].code,&shop_product[count].quantity,
                                    &shop_product[count].price);
                if(status == -1)
                {
                    break;
                }
                count++;
            }
            fclose(productfile);
            printf("\tOur Available Products : \n");
            printf("\t.............................\n\n");
            int i;
            for(i = 0 ; i <count ;i++)
            {
                printf("\t\t%s\t%.2f",shop_product[i].name,shop_product[i].price);
                printf("\n\n");
            }
            while(1)
            {
                char p_name[100];
                fflush(stdin);
                printf("\tEnter Product name: ");
                gets(p_name);
                int flag=0;
                int i;
                for(i=0;i<count;i++)
                {
                    if(strcmp(shop_product[i].name,p_name)==0)
                    {
                    flag = 1;
                    break;
                    }
                }
                if(flag == 0)
                {
                printf("\tSorry Sir, we don't have this product right now. We will try to bring it back asap.\n");
                }
                else
                {
                    int q;
                    printf("\tEnter Quantity : ");
                    scanf("%d",&q);
                    fflush(stdin);
                    if(q <= shop_product[i].quantity)
                    {
                        total_amount = total_amount + q * shop_product[i].price;
                        shop_product[i].quantity = shop_product[i].quantity -q;
                    }
                    else
                    {
                        printf("\n\n\tSorry, Sir. We don't have this amount of product right now.\n");
                    }

                }
                printf("\n\tPress C for continue and others for exit\n");
                printf("\tEnter your choice: ");
                char t;
                scanf("%c",&t);
                tolower(t);
                fflush(stdin);
                if(t!= 'c')
                {
                    break;
                }
            }
            productfile=fopen("men.txt","w");
            if(productfile == NULL)
            {
                printf("Error!!\n");
                exit (1);
            }
            for(i=0; i<count ; i++)
            {
                fprintf(productfile,"%s\t%d\t%d\t%.2f\n", shop_product[i].name,
                            shop_product[i].code,shop_product[i].quantity,
                            shop_product[i].price);
                printf("\n");
            }
            fclose(productfile);
        }
        else if(d==0)
        {
            system("CLS");
            title();
            printf("\n\n\n**********************************************************************************************************\n");
            printf("       Welcome to our shop %s, I hope you are having a good day. Welcome to our sell.com Shopping.\n\n",name);
            printf("*********************************************************************************************************\n\n");

            printf("\t\t\t\tSpecial Offer going on!!!!!!\n\n");
            printf("\t\t\t\t  Big Sale upto 40%c off\n\n",'%');
            FILE *productfile;
            product input;
            productfile = fopen("women.txt","r");
            if(productfile == NULL)
            {
                printf("Error!!\n");
                exit (1);
            }
            int count = 0;
            product shop_product[100];
            while(1)
            {
                int status = fscanf(productfile,"%s %d %d %f", &shop_product[count].name,
                                &shop_product[count].code,&shop_product[count].quantity,
                                    &shop_product[count].price);
                if(status == -1)
                {
                    break;
                }
                count++;
            }
            fclose(productfile);
            printf("\tOur Available Products : \n");
            printf("\t.............................\n\n");
            int i;
            for(i = 0 ; i <count ;i++)
            {
                printf("\t%s\t%.2f",shop_product[i].name,shop_product[i].price);
                printf("\n\n");
            }
            while(1)
            {
                char p_name[100];
                fflush(stdin);
                printf("\tEnter Product name: ");
                gets(p_name);
                int flag=0;
                int i;
                for(i=0;i<count;i++)
                {
                    if(strcmp(shop_product[i].name,p_name)==0)
                    {
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0)
                {
                    printf("\n\n\tSorry, Sir. We don't have this amount of product right now.\n");
                }
                else
                {
                    int q;
                    printf("\tEnter Quantity : ");
                    scanf("%d",&q);
                    fflush(stdin);
                    if(q <= shop_product[i].quantity)
                    {
                        total_amount = total_amount + q * shop_product[i].price;
                        shop_product[i].quantity = shop_product[i].quantity -q;
                    }
                    else
                    {
                        printf("\n\n\tSorry, Sir. We don't have this amount of product\n");
                    }

                }
                printf("\n\tPress C for continue and others for exit\n");
                printf("\tEnter your choice: ");
                char t;
                scanf("%c",&t);
                tolower(t);
                fflush(stdin);
                if(t!= 'c')
                {
                    break;
                }
            }
            productfile=fopen("women.txt","w");
            if(productfile == NULL)
            {
                printf("Error!!\n");
                exit (1);
            }
            for(i=0; i<count ; i++)
            {
                fprintf(productfile,"%s\t%d\t%d\t%.2f\n", shop_product[i].name,
                            shop_product[i].code,shop_product[i].quantity,
                            shop_product[i].price);
                printf("\n");
            }
            fclose(productfile);
    }
}

int main()
{
    title();
    printf("\n");
    Sleep(1500);
    printf("\nA project by: \n");
    printf("      =================================================================================================================\n");


    printf("\tName1: Kazi Shawpnil");
    printf("                      Name2: Sahid Hossain Mustakim");
    printf("                      Name3: Hriday Das\n");
    printf("\tID: 011201125");

    printf("                             ID: 011201274");
    printf("                                      ID: 011201278\n");
    printf("      =================================================================================================================\n\n");

    Sleep(3000);
    printf("Guided by:\n");
    printf("\t_______________________________________________________________________________________________________________\n\n");
    printf("\tName: Mr. Ahmed Fahmin\n\tLecturer,CSE Department\n\tUnited International University\n");
    printf("\t_______________________________________________________________________________________________________________\n\n");

    printf("\nEnter any key to continue...");
    getch();
    login:
    system("CLS");
    title();
    printf("\n\n\n\n\n");
    printf("\t\t\t\tIf you want log in as a manager then press < 1 >\n\t\t\t\tIf you want to visit our shop then press < 2 >\n\n");
    printf("\t\t\t\tEnter your choice: ");
    int v;
    scanf("%d",&v);
    system("CLS");
    if(v==1)
    {
        char User_name[20];
        char Password[15];
        log:
        title();
        printf("\n\n\n");
        printf("\t\t\t\t\tLog in..\n\n");
        printf("\t\t\t\t\tEnter your user name: ");
        fflush(stdin);
        gets(User_name);
        printf("\t\t\t\t\tEnter your password: ");
        gets(Password);

        if(strcmp(User_name, "sellcom")==0)
        {
            if(strcmp(Password, "1234")==0)
            {
                printf("\t\t\t\t\tWait for a moment...\n\n");
                Sleep(700);
                printf("\t\t\t\t\tSuccessfully Sign in\n\n");
                Sleep(580);
                system("CLS");
            }
            else
            {
                printf("\n\t\t\t\tInvalid Password. Please try again\n");
                Sleep(1000);
                system("CLS");
                goto log;

            }
        }
        else
        {
            printf("\n\t\t\t\tInvalid User name. Please try again\n");
            Sleep(1000);
            system("CLS");
            goto log;

        }
        nam();
        logi();
        while(1)
        {
            admin();
            fflush(stdin);
            total();

            printf("\n\tIf you want go back to main page then press y or press n to exit..\n\n\tEnter your choice: ");
            char y;
            scanf("%s",&y);
            tolower(y);
            if(y=='y')
            {
                system("CLS");
            }
            else
            {
                break;
            }
        }

    }
    else if(v==2)
    {
        int cho;
        title();
        printf("\n\n\n\n");
        printf("\t\t\t\tPress < 1 > for sign up\n\t\t\t\tPress < 2 > for sign in\n\n");
        printf("\t\t\t\tEnter your choice: ");
        scanf("%d",&cho);
        if(cho == 1)
        {
            system("CLS");
            registe();
        }
        else if(cho==2)
        {
            system("CLS");
            login();
            printf("\n\n\n\t\t\t\tWait for a moment..\n\n");
            Sleep(650);
            printf("\t\t\t\tSuccessfully login!\n");
            Sleep(600);
            system("CLS");
        }
        else
        {
            printf("\n\t\t\t\tInvalid User name. Please try again\n");
            Sleep(800);
            goto login;
        }
            system("CLS");
            nam();
            while(1)
            {
                fflush(stdin);
                customer();
                fflush(stdin);
                total();

                printf("\n\tIf you want go back to main page then press y or press n to exit..\n\n\tEnter your choice: ");
                char y;
                scanf("%s",&y);
                tolower(y);
                if(y=='y')
                {
                    system("CLS");
                }
                else
                {
                    break;
                }
            }
        }
        total();
        system("CLS");
        title();
        printf("\n\n\t\t\t\t\t\t  Your Invoice\n");
        printf("\t\t\t\t\t\t-----------------\n\n\n");
        printf("\tYour Total: %.02lf\n",total_amount);
        double discount;
        discount = Discount(total_amount);
        printf("\tDiscount: %.02lf%c\n",(discount*100),'%');
        printf("\tAmount to pay: %.02lf Taka\n", total_amount - discount*total_amount);
        printf("\tDelivery charge 80taka\n\n");
        printf("\tTotal payment(with delivery charge): %.02lf taka\n ",(total_amount - discount*total_amount)+80);

        printf("\t\t\n\nThank you,Sir for purchasing product from our shop. Hope you will visit again.\n\n\t\t\t\t\tHappy shopping!!!\n\n");
        return 0;
}
