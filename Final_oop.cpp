#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<cstdlib>
using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
char rest[20];
class Restaurant;
class Admin;
class Customer;
void ChooseCategory();
int main();
class Customer
{
    protected:
    char user_name[15];
    char password[15];
    long int Phone_Num;
    string address;
    char un[15], p[15];
    char location[30];                  // new address
    int flag;
    public:
        Customer()
        {
            user_name[15]={};
            password[15]={};
            address={};
            location[30]={};
            Phone_Num = 0;
            un[15]={};
            p[15]={};
            flag = 0;
        }
        void SetCustomerData()
        {
            system("cls");
            fstream CustID;
            CustID.open("IDs.dat",ios::app |ios::binary);
            cout << "Enter Username: ";
            fflush(stdin);
            cin >> user_name;
            cout << "Enter Password: ";
            fflush(stdin);
            cin >> password;
            up:
            cout << "Enter your Phone Number : (+92) ";
            cin >> Phone_Num;
            if(Phone_Num <= 0 || Phone_Num > 1000000000)
            {
                try
                {
                    throw Phone_Num;
                }
                catch(...)
                {
                    cout << "Exception Caught\n";
                    cin.clear();
                    cin.ignore();
                    goto up;
                }    
            }
            cout << "Enter your permanent address: ";
            fflush(stdin);
            cin >> address;
            CustID.write((char*)this,sizeof(*this));
            CustID.close();  
        }
        char* getname()
        {
            return user_name;
        }
        char* getpass()  
        {
            return password;
        }
        char* getun()
        {
            return un;
        }
        char* getp()
        {
            return p;
        }
        void LoginCustomer(char id[],char passward[])
        {
            char cha=219;
           
            strcpy(un,id);
            strcpy(p,passward);
            flag = 0;
            fstream freader;
            freader.open("IDs.dat",ios::in|ios::binary);
            if(freader.is_open())
            {
                while(!freader.eof())
                {
                    freader.read((char*)this,sizeof(*this));
                    if(strcmp(id,getname())==0 && strcmp(getpass(),passward)==0)
                    {
                        SetConsoleTextAttribute(hConsole, 2);
                        cout<<"\t\t\t\t\n________________________________\n";
                        cout<<"\t\t\t\t\nYou have successfuly Signed up!!";
                        cout<<"\t\t\t\t\n________________________________\n";
                        SetConsoleTextAttribute(hConsole, 15);
                        flag=1;
                        freader.close();
                        Sleep(1000);
                        system("cls");
//                        ChooseCategory();
                        break;
                    }
                    ele 
                    
                }
            }
            if(flag!=1)
            {
                cout << "\nWrong ID or Password. ";
                cout << "\nAccess Denied!!";
                cout << "\nIf you do not have an account on FOOD DELIVERO, kindly create it\n";
                main();
            }
            if(flag==1)
            ChooseCategory();
        }
        ~Customer(){};
    }c;
    class Restaurant :public Customer
    {
        protected:
        char coupen[6];
        double coupen_price;          //coupen ammont
        double static total;
        int rating;
        double profit;
        private:
        char item_name[40];
        char item_size[40];
        double item_price;
        char item_code[10];
        char comment[30];
        int count;
        double sumofrating;
        double avgRating;
        
        public:    
       
        Restaurant()
        {
            count = 0;
            sumofrating = 0;
            avgRating = 0;
            profit = 0;
            item_price = 0;
        }
        void InputData(string filename)
        {
            int i =0 , count=0;
            char c;
            fstream store;
            store.open(filename.c_str(), ios::app | ios :: binary);
            cout << "Product Code : ";
            fflush(stdin);
            cin.getline(item_code,10);
            cout << "Product Name : ";
            fflush(stdin);
            cin.getline(item_name,40);
            cout << "Size / Qauntity : ";
            cin.getline(item_size,40);
            one:
            cout << "Price : ";
            cin >> item_price;
            if(item_price <= 0 || item_price > 10000)
            {
                try
                {
                        throw item_price;
                }
                catch(...)
                {
                    cout << "Exception Caught\n";
                    cin.clear();
                    cin.ignore();
                    goto one;
                }    
            }
            cout << endl;
            store.write((char *)this,sizeof(*this));        
            store.close();
        }
        void getdata()
        {
            cout << "Product Code : ";
            fflush(stdin);
            cin.getline(item_code,10);
            cout << "Product Name : ";
            fflush(stdin);
            cin.getline(item_name,40);
            cout << "Size / Quantity :";
            cin.getline(item_size,15);
            cout << "Price : ";
            cin >> item_price;
        }
        void showRecord()const
        {
            int flag1=0;
            int flag2=0;
            for(int i=0;i<strlen(item_name);i++)
            {
                if (item_name[i]==' ')
                {
                    flag1=1;
                }
                if(item_size[i]==' ')
                {
                    flag2=2;
                }
            }
            if(flag1==1  && flag2!=2)
            {
                cout << item_code << "\t\t" << item_name << "\t\t" << item_size << "\t\t" << item_price << endl;
            }
            if(flag2==2 && flag1!=1)
            {
                cout << item_code << "\t\t" << item_name << "\t\t\t" << item_size << "\t\t\t" << item_price << endl;
            }
            else if (flag2==2  && flag1==1)
            {
                cout << item_code << "\t\t" << item_name << "\t\t" << item_size << "\t\t" << item_price << endl;
            }
            else if(flag2!=2 && flag1!=1)
            {
                cout << item_code << "\t\t" << item_name << "\t\t\t" << item_size << "\t\t\t" << item_price << endl;
            }
        }
        void ViewAllRecords(string filename)const
        {
            fstream input;
            cout << endl;
            input.open(filename.c_str(),ios::in | ios :: binary);
            if(!input.is_open())
            {
                cout<<"\nRestaunrant Menu Has not been Added Yet..";
                main();
            }
            else
            {
                cout<<"\nItem Code\tItem Name\t\tItem Size\t\tItem Price\n";
                input.read((char*)this,sizeof(*this));
                while(!input.eof())
                {  
                    showRecord();
                    input.read((char*)this,sizeof(*this));
                }   
                input.close();
            }
        }
        void updateRecord(string filename)
        {
            char code[10];
            cout << "\nEnter code of the product that you want to update : ";
            fflush(stdin);
            cin.getline(code,10);
            fstream updation;
            updation.open(filename.c_str(),ios::in |ios::ate|ios::out|ios::binary);
            updation.seekg(0);
            updation.read((char*)this,sizeof(*this));
            if(updation.is_open())
            {
                while(!updation.eof())
                {
                    if(strcmp(code,item_code)==0)
                    {
                        getdata();
                        updation.seekp(updation.tellp() - sizeof(*this));
                        updation.write((char*)this,sizeof(*this));
                    }
                    updation.read((char*)this,sizeof(*this));
                }
                updation.close();
            }
            else
            cout << "No records found\n";
        }
        void deleteRecord(string filename)const
        {  
            int check=0;
            char code[10];
            cout << "Input code that you want to delete with ? ";
            fflush(stdin);
            cin.getline(code,10);
            fstream reader;
            fstream writer;
            reader.open(filename.c_str(),ios::in | ios :: binary);
             while(!reader.eof())
                {
                    reader.read((char *)this,sizeof(*this));
                    if(strcmp(code,item_code)==0)
                    {
                        check=1;
                    }
                }
                reader.close();
            reader.open(filename.c_str(),ios::in | ios :: binary);
            writer.open("Temp.dat",ios::app | ios :: binary);
            if(reader.is_open())
            {
                while(!reader.eof())
                {
                    reader.read((char *)this,sizeof(*this));
                    if(strcmp(code,item_code)!=0)
                    {
                        writer.write((char*)this,sizeof(*this));
                        reader.read((char*)this,sizeof(*this));
                    }
                }  
                reader.close();
                writer.close();
                remove(filename.c_str());
                rename("Temp.dat",filename.c_str());
                if(check!=1)
                {
                    cout<<"\nCode you Entered Does not Match!!";
                }
                else if(check==1)
                {
                    cout<<"\nItem Deleted!!";
                }
            }
            else
            {
                cout << "\nYour Inventory is Empty";
            }
            
        }
        void PlaceOrder(string filename)
        {
            repeat1:
            char code[10];
            flag=0;
            int n;
            cout << "Enter item code u want to add to order ...\n";
            fflush(stdin);
            cin.getline(code,10);
            fstream reader,order;
            cout << endl;
            reader.open(filename.c_str(),ios::in | ios::binary);
            order.open("Order.dat",ios::app | ios :: binary);
            if(reader.is_open())
            {
                while(!reader.eof())
                {
                    reader.read((char*)this,sizeof(*this));
                    if(strcmp(code,item_code)==0)
                    {
                        order.write((char*)this,sizeof(*this));
                        flag=1;
                        break;
                    }  
                }
                reader.close();
                order.close();
                if(flag!=1)
                {
                    cout<<"\nNo such Code found ";
                    cout<<"\nEnter Code Again ";
                }
            }
            two:
            cout << "\n1 <<< To add more to cart ";
            cout << "\n2 <<< Delete item from the cart ";
            cout << "\n3 <<< Calculate the Bill..";
            cout << "\n4 <<< Show Cart";
            cout << "\n<< <<< Any other key to exit \n";
            cin >> n;
            if(!cin)
            {
                try
                {
                    throw 1;
                }
                catch(...)
                {
                    cout << "Exception caught!\n";
                    cout << "Input Valid Choice\n";
                    cin.clear();
                    cin.ignore();
                    goto two;
                }
            }
            else if(n==1)
            {
                system("cls");
                ViewAllRecords(filename.c_str());
                goto repeat1;
            }
            else if(n==2)
            {
                ViewAllRecords("Order.dat");
                deleteRecord("Order.dat");
                goto two;
            }
            else if(n==3)
            {
                CalculateBill();
            }
            else if(n==4)
            {
               ViewAllRecords("Order.dat");
                goto two; 
            }
            else if(n==0)
            {
                cout << "\nProgram terminated!";
                exit;
            }
            else
            {
                cout<<"\nChoose Right Choice..";
                goto two;
            }
            cout << "\nYour Total Bill Is : " << total;
        }
        void CalculateBill()
        { 
            total=0;
            fstream o;
            o.open("Order.dat");
            o.seekg (0, ios::end);
            if(o.tellg() == 0)
            {
               cout<<"Your cart is empty ,So plz order first!!";
               o.close();
               remove("Order.dat");
               ChooseCategory();
            }
            else
            {
                fstream order;
                cout << endl << "\t\t---Your Order---\n";
                cout << "\nItem Name\tItem Size\tItem Price\n";          
                order.open("Order.dat",ios::in | ios :: binary);
                order.read((char*)this,sizeof(*this));
                while(!order.eof())
                {
                    cout << item_name <<"\t\t"<< item_size<<"\t\t"<< item_price << endl;
                    total = total + item_price;
                    order.read((char*)this,sizeof(*this));
                }
                order.close();
                c:
                three:
                cout << "\nDo you Have any Coupen Number..(Y/N)";
                char chr;
                cin >> chr;
                if(chr != 'y'&& chr != 'Y'&& chr != 'n' && chr != 'N')
                {
                    try{
                        throw chr;
                    }
                    catch(...)
                    {
                        cout << "Exception Caught\n";
                        cout << "Input Valid Option\n";
                        cin.clear();
                        cin.ignore();
                        goto three;
                    }
                }
                if(chr == 'y' || chr == 'Y')
                {
                    char cou_num[6];
                    cout << "Enter Coupen Number:";
                    cin >> cou_num;
                    fstream cou;
                    cou.open("Coupen.dat",ios::in | ios ::binary );
                    while(cou >> coupen>> coupen_price)
                    {
                        if(strcmp(coupen,cou_num)==0)
                        {
                            cout<<coupen_price;
                            flag = 1;
                            cout << "\nYou Got a discount of Rs."<<coupen_price;
                            total -= coupen_price;
                            break;
                        }
                    }
                    if(flag != 1)
                    {
                        cout << "\nNo such A coupen Found ..Write the correct one..";
                        goto c;
                    }
                    cou.close();
                }
                else if(chr == 'n'||chr == 'N')
                {
                    cout << "You have got no coupen!\n";
                }
            }
        }
        double getTotal()const
        {
            return total;
        }
        void CalculateProfit(string filename)
        {
            profit = (getTotal()*10)/100;
            fstream pro;
            pro.open(filename.c_str(),ios :: app | ios :: binary);
            pro << endl << profit;
            pro.close();
        }
        void Rating(string filename)
        {
            fstream rate;
            rate.open(filename.c_str(),ios :: app|ios :: binary);
            rate:
            cout << "\nRate the Restaurant Out of 6:";
            cin >> rating;
            if(rating <0 || rating>6)
            {
                try{
                    throw rating;
                }
                catch(...)
                {
                    cout<<"\n Choose Rating with in 6.";
                    cin.clear();
                    cin.ignore();
                    goto rate;
                }
            }
            cout << "\nAny comments:";
            fflush(stdin);
            cin.getline(comment,30);        
            rate << rating << "\t" << comment << endl;
            rate.close();
            int a;
            cout << "\nYou Rated : ";
            if(rating>4)
            {
                a=2;
            }
            else if(rating>2 && rating<5)
            {
                a=14;
            }
            else if(rating<3 && rating>=0)
            {
                a=4;
            }
            SetConsoleTextAttribute(hConsole,a);
            for(int i=0;i<rating;i++)
            {
                cout << "* ";
            }
            SetConsoleTextAttribute(hConsole, 15);
            cout << "\nYour comment : " << comment;
            z:
            cout <<"\n Do you To continue or Terminate the program." << endl;
            cout << "C <<< Continue" << endl << "T <<< Terminate" << endl << "Enter Choice :";
            char ct;
            cin >> ct;
            switch(ct)
            {
                case 'c':
                case 'C':
                {
                    system("cls");
                    main();
                    break;
                }
                case 't':
                case 'T':
                {
                    exit(1);
                    break;
                }
                default:
                {
                    cout << "\nChoose a Right Choice";
                    goto z;
                }
            }

        }
        void ShowRating(string filename)
        {
            count=0;
            avgRating=0;
            sumofrating=0;
            fstream rate;
            rate.open(filename.c_str(),ios :: in |ios :: binary);
            if(!rate.is_open())
            {
                cout << "Order to this restaurant has not been placed yet.\n";
            }
            else
            {
                while(rate >> rating >> comment)
                {
                    cout << rating << "\t\t" << comment << endl;
                    count++;
                }
                rate.close();
                rate.open(filename.c_str(),ios::in |ios::binary);
                while(rate >> rating >> comment)
                {
                    sumofrating += rating;
                }
                rate.close();
                avgRating = sumofrating/count;
                cout << "\nAverage Rating of the Restaurant is : " << avgRating;
            }
        }
        void DeliveryNotfications()const
        {
            char cha=219;
            SetConsoleTextAttribute(hConsole, 15);
            cout << "\nThe order will be at your place in 30 minutes!\n";
            Sleep(3000);
            cout << "\n5. The chef has started cooking your order\n";
            Sleep(3000);
            SetConsoleTextAttribute(hConsole, 3);
             for(int i=0;i<10;i++) 
            {
                Sleep(10);
                cout<<cha;
            }
             SetConsoleTextAttribute(hConsole, 15);
            cout << "\n4. Now, your order is about to depart from the restaurant\n";
            Sleep(3000);
            SetConsoleTextAttribute(hConsole, 3);
             for(int i=0;i<20;i++) 
            {
                Sleep(10);
                cout<<cha;
            }
             SetConsoleTextAttribute(hConsole, 15);
            cout << "\n3. Now, rider has departed with your order\n";
            Sleep(3000);
            SetConsoleTextAttribute(hConsole, 3);
             for(int i=0;i<30;i++) 
            {
                Sleep(10);
                cout<<cha;
            }
             SetConsoleTextAttribute(hConsole, 15);
            cout << "\n2. Now, rider is at the corner of your location\n";
            Sleep(3000);
            SetConsoleTextAttribute(hConsole, 3);
             for(int i=0;i<40;i++) 
            {
                Sleep(10);
                cout<<cha;
            }
            SetConsoleTextAttribute(hConsole, 15);
            cout << "\n1. Order has been completed!\n";
            Sleep(3000);
            SetConsoleTextAttribute(hConsole, 3);
            for(int i=0;i<50;i++) 
            {
                Sleep(10);
                cout<<cha;
            }
           
            SetConsoleTextAttribute(hConsole, 15);
            cout << "\nKindly, review the restaurant services\n";
        }
    ~Restaurant(){};
};

class Admin : public Restaurant  
{
    private:
    double amount;
    public:
        Admin()
        {
            amount=0;
        }
        void AddCoupen()
        {
            cout << "\nEnter Coupen Number : ";
            cin >> coupen;
            four:
            cout << "Enter amount of the coupen :";
            cin >> coupen_price;
            if(coupen_price < 0 || coupen_price > 10000)
            {
                try{
                    throw coupen_price;
                }
                catch(...)
                {
                    cout << "Exception Caught\n";
                    cout << "Input an integer value\n";
                    cin.clear();
                    cin.ignore();
                    goto four;
                }
            }
            fstream coup;
            coup.open("Coupen.dat",ios :: app | ios :: binary);
            coup << coupen << "\t" << coupen_price << endl;        
            coup.close();
        }
        void deleteCoupen()
        {
            char dltcoupen[6];
            cout << "\nEnter Coupen number you want to delete : ";
            cin >> dltcoupen;
            fstream cou,tmp;
            cou.open("Coupen.dat",ios :: in | ios :: binary);
            tmp.open("Temp1.dat",ios :: app | ios :: binary);
            if(cou.is_open())
            {
                while(cou >> coupen >> coupen_price)
                {
                    if(strcmp(dltcoupen,coupen)!=0)
                    {
                        tmp << coupen << "\t" << coupen_price << endl;
                    }
                }
                cou.close();
                tmp.close();
                remove("Coupen.dat");
                rename("Temp1.dat","Coupen.dat");
            }
            else
            {
                cout << "\nFile not found\n";
            }
        }
        void ViewAllCoupens()
        {
            system("cls");
            fstream cou;
            cou.open("Coupen.dat",ios::in | ios:: binary);
            if(cou.is_open())
            {
                while(cou >> coupen>> coupen_price)
                {
                    cout<< coupen << "\t" << coupen_price << endl;
                }
                cou.close();
            }
            else
            cout << "\nNo coupens added yet.\n";
           
        }
        void ViewRestaurantsRating()
        {
            cout << "Average Pizza Hut Ratings \n";
            ShowRating("PizzaHutRatings.dat");
            cout<<"\n************************************************************************\n";
            cout << endl << "Average Broadway Pizza Ratings\n";
            ShowRating("BroadwayRatings.dat");
            cout<<"\n************************************************************************\n";
            cout << endl << "Average New York Pizza Ratings\n";
            ShowRating("NewyorkRatings.dat");
            cout<<"\n************************************************************************\n";
            cout << endl << "Average California Pizza Ratings\n";
            ShowRating("CaliforniaRatings.dat");
            cout<<"\n************************************************************************\n";
            cout << endl << "Average Delizia Ratings\n";
            ShowRating("DeliziaRatings.dat");
            cout<<"\n************************************************************************\n";
            cout << endl << "Average Delfrio Ratings\n";
            ShowRating("DelfrioRatings.dat");
            cout<<"\n************************************************************************\n";
            cout << endl << "Average Vintage Ratings\n";
            ShowRating("VintageRatings.dat");
            cout<<"\n************************************************************************\n";
            cout << endl << "Average Dunkin Donut Ratings\n";
            ShowRating("DunkinDonutsRatings.dat");
            cout<<"\n************************************************************************\n";
            cout << endl << "Average Burger Lab Ratings\n";
            ShowRating("BurgerLabRatings.dat");
            cout<<"\n************************************************************************\n";
            cout << endl << "Average Burger Shake Ratings\n";
            ShowRating("BurgerShakeRatings.dat");
            cout<<"\n************************************************************************\n";
            cout << endl << "Average Burger King Ratings\n";
            ShowRating("BurgerKingRatings.dat");
            cout<<"\n************************************************************************\n";
            cout << endl << "Average Burger'O Clock Ratings\n";
            ShowRating("BurgerOClockRatings.dat");
            cout<<"\n************************************************************************\n";
            cout << endl << "Average Kababjees Ratings\n";
            ShowRating("KababJeesRatings.dat");
            cout<<"\n************************************************************************\n";
            cout << endl << "Average Foods In Ratings\n";
            ShowRating("FoodsInRatings.dat");
            cout<<"\n************************************************************************\n";
            cout << endl << "Average Bamboo Ratings\n";
            ShowRating("BambooRatings.dat");
            cout<<"\n************************************************************************\n";
            cout << endl << "Average Sizzlers Ratings\n";
            ShowRating("SizzlersRatings.dat");
            cout<<"\n************************************************************************\n";
        }
        void Profit()
        {
            cout << "Profit From Pizza Hut  \n";
            ProfitFile("PizzahutProfit.dat");
            cout<<"\n************************************************************************\n";
            cout << endl << "Profit From Broadway Pizza \n";
            ProfitFile("BroadwayProfit.dat");
            cout<<"\n************************************************************************\n";
            cout << endl << "Profit From New York Pizza \n";
            ProfitFile("NewyorkProfit.dat");
            cout<<"\n************************************************************************\n";
            cout << endl << "Profit From California Pizza \n";
            ProfitFile("CaliforniaProfit.dat");
            cout<<"\n************************************************************************\n";
            cout << endl << "Profit From Delizia \n";
            ProfitFile("DeliziaProfit.dat");
            cout<<"\n************************************************************************\n";
            cout << endl << "Profit From Delfrio \n";
            ProfitFile("DelfrioProfit.dat");
            cout<<"\n************************************************************************\n";
            cout << endl << "Profit From Vintage \n";
            ProfitFile("VintageProfit.dat");
            cout<<"\n************************************************************************\n";
            cout << endl << "Profit From Dunkin Donut \n";
            ProfitFile("DunkinDonutProfit.dat");
            cout<<"\n************************************************************************\n";
            cout << endl << "Profit From Burger Lab \n";
            ProfitFile("BurgerLabProfit.dat");
            cout<<"\n************************************************************************\n";
            cout << endl << "Profit From Burger Shake \n";
            ProfitFile("BurgerShakeProfit.dat");
            cout<<"\n************************************************************************\n";
            cout << endl << "Profit From Burger King \n";
            ProfitFile("BurgerKingProfit.dat");
            cout<<"\n************************************************************************\n";
            cout << endl << "Profit From Burger'O Clock \n";
            ProfitFile("BurgerOClockProfit.dat");
            cout<<"\n************************************************************************\n";
            cout << endl << "Profit From Kababjees \n";
            ProfitFile("KababjeesProfit.dat");
            cout<<"\n************************************************************************\n";
            cout << endl << "Profit From Foods In \n";
            ProfitFile("FoodsInProfit.dat");
            cout<<"\n************************************************************************\n";
            cout << endl << "Profit From Bamboo \n";
            ProfitFile("BambooProfit.dat");
            cout<<"\n************************************************************************\n";
            cout << endl << "Profit From Sizzlers \n";
            ProfitFile("SizzlersProfit.dat");
            cout<<"\n************************************************************************\n";
        }
        void ProfitFile(string filename)
        {
            double monthly_amount;
            fstream pro;
            pro.open(filename.c_str(),ios::in | ios::binary);
            if(pro.is_open())
            {
                while(pro >> profit)
                {
                    monthly_amount += profit;
                }
                pro.close();
                cout << "\nYour Monthly Profit is:" << monthly_amount;  
            }
            else
            cout << "No order has been placed to this restaurant yet.\n";
        }
        void CustomerDetails()
        {  
            char ad;
            five:
            cout << "\nDo you want the food to be delivered at your permanent address, or would you like to change it?\n";
            cout << "Y <<< Permanent\n";
            cout << "N <<< Change\n";
            cin >> ad;
            if(ad != 'y' && ad != 'Y' && ad != 'n' && ad != 'N')
            {
                try{
                    throw ad;
                }
                catch(...)
                {
                    cout << "Exception Caught!\n";
                    cout << "Input Valid Option!\n";
                    cin.clear();
                    cin.ignore();
                    goto five;
                }
            }
            if(ad == 'y'||ad == 'Y')
            {
                cout << "Permanent address used!\n";
            }
            else
            {
                cout << "Enter the location of delivery : ";
                fflush(stdin);
                cin.getline(location,30);
                cout << "New address for this particular order noted!\n";
            }  
        }
        void OrderDetails()const
        {
            //system("cls");
            cout << "\nYour order is confirmed!\n";
            cout << "\t\t-----YOUR ORDER----\n";
            ViewAllRecords("Order.dat");
            cout << "Total Amount to be payed : " << total;
            remove("Order.dat");
        }
        void KickOut()const
        {
            six:
            system("cls");
            cout << "1 <<< Pizza Hut\n";
            cout << "2 <<< Broadway Pizza\n";
            cout << "3 <<< New York Pizza\n";
            cout << "4 <<< California Pizza\n";
            cout << "5 <<< Burger Lab\n";
            cout << "6 <<< Burger Shake\n";
            cout << "7 <<< Burger'O Clock\n";
            cout << "8 <<< Burger King\n";
            cout << "9 <<< Sizzlers\n";
            cout << "10 <<< Bamboo\n";
            cout << "11 <<< Foods In\n";
            cout << "12 <<< Kababjees\n";
            cout << "13 <<< Delizia\n";
            cout << "14 <<< Delfrio\n";
            cout << "15 <<< Dunkin Donut\n";
            cout << "16 <<< vintage\n";
            int choices;
            cout<<"\nEnter Your Choice For the Restaurant U want to KickOut From Food Dilivirio.. ";
            cin >> choices;
            if(choices < 1 || choices > 16)
            {
                try{
                    throw choices;
                }
                catch(...)
                {
                    cout << "Exception caught\n";
                    cout << "Input valid Option!\n";
                    cin.clear();
                    cin.ignore();
                    goto six;
                }
            }
            switch(choices)
            {
                case 1 :
                {
                    remove("PizzahutMenu.dat");
                    remove("PizzahutProfit.dat");
                    remove("PizzaHutRatings.dat");
                    strcpy(rest,"Pizzahut");
                    fstream kick;
                    kick.open("KickOutList.dat",ios::app |ios::binary);
                    kick<<rest<<endl;
                    kick.close();
                    break;
                }
                 case 2 :
                {
                    remove("BroadwayMenu.dat");
                    remove("BroadwayProfit.dat");
                    remove("BroadwayRatings.dat");
                    strcpy(rest,"Broadway");
                    fstream kick;
                    kick.open("KickOutList.dat",ios::app |ios::binary);
                    kick<<rest<<endl;
                    kick.close();
                    break;
                }
                 case 3 :
                {
                    remove("NewYorkMenu.dat");
                    remove("NewyorkProfit.dat");
                    remove("NewyorkRatings.dat");
                    strcpy(rest,"NewYork");
                    fstream kick;
                    kick.open("KickOutList.dat",ios::app |ios::binary);
                    kick<<rest<<endl;
                    kick.close();
                    break;
                }
                 case 4 :
                {
                    remove("CaliforniaMenu.dat");
                    remove("CaliforniaProfit.dat");
                    remove("CaliforniaRatings.dat");
                    strcpy(rest,"California");
                    fstream kick;
                    kick.open("KickOutList.dat",ios::app |ios::binary);
                    kick<<rest<<endl;
                    kick.close();
                    break;
                }
                 case 5 :
                {
                    remove("BurgerLabMenu.dat");
                    remove("BurgerLabProfit.dat");
                    remove("BurgerLabRatings.dat");
                    strcpy(rest,"BurgerLab");
                    fstream kick;
                    kick.open("KickOutList.dat",ios::app |ios::binary);
                    kick<<rest<<endl;
                    kick.close();  
                    break;
                }
                 case 6 :
                {
                    remove("BurgerShakeMenu.dat");
                    remove("BurgerShakeProfit.dat");
                    remove("BurgerShakeRatings.dat");
                    strcpy(rest,"BurgerShake");
                    fstream kick;
                    kick.open("KickOutList.dat",ios::app |ios::binary);
                    kick<<rest<<endl;
                    kick.close();
                    break;
                }
                 case 7 :
                {
                    remove("BurgerOClockMenu.dat");
                    remove("BurgerOClockProfit.dat");
                    remove("BurgerOClockRatings.dat");
                    strcpy(rest,"BurgerOClock");
                    fstream kick;
                    kick.open("KickOutList.dat",ios::app |ios::binary);
                    kick<<rest<<endl;
                    kick.close();
                    break;
                }
                 case 8 :
                {
                    remove("BurgerKingMenu.dat");
                    remove("BurgerKingProfit.dat");
                    remove("BurgerKingRatings.dat");
                    strcpy(rest,"BurgerKing");
                    fstream kick;
                    kick.open("KickOutList.dat",ios::app |ios::binary);
                    kick<<rest<<endl;
                    kick.close();
                    break;
                }
                 case 9 :
                {
                    remove("SizzlersMenu.dat");
                    remove("SizzlersProfit.dat");
                    remove("SizzlersRatings.dat");
                    strcpy(rest,"Sizzlers");
                    fstream kick;
                    kick.open("KickOutList.dat",ios::app |ios::binary);
                    kick<<rest<<endl;
                    kick.close();
                    break;
                }
                 case 10 :
                {
                    remove("BambooMenu.dat");
                    remove("BambooProfit.dat");
                    remove("BambooRatings.dat");
                    strcpy(rest,"Bamboo");
                    fstream kick;
                    kick.open("KickOutList.dat",ios::app |ios::binary);
                    kick<<rest<<endl;
                    kick.close();
                    break;
                }
                 case 11 :
                {
                    remove("FoodsInMenu.dat");
                    remove("FoodsInProfit.dat");
                    remove("FoodsInRatings.dat");
                    strcpy(rest,"FoodsIn");
                    fstream kick;
                    kick.open("KickOutList.dat",ios::app |ios::binary);
                    kick<<rest<<endl;
                    kick.close();
                    break;
                }
                 case 12 :
                {
                    remove("KababjeesMenu.dat");
                    remove("KababjeesProfit.dat");
                    remove("KababJeesRatings.dat");
                    strcpy(rest,"Kababjees");
                    fstream kick;
                    kick.open("KickOutList.dat",ios::app |ios::binary);
                    kick<<rest<<endl;
                    kick.close();
                    break;
                }
                 case 13 :
                {
                    remove("DeliziaMenu.dat");
                    remove("DeliziaProfit.dat");
                    remove("DeliziaRatings.dat");
                    strcpy(rest,"Delizia");
                    fstream kick;
                    kick.open("KickOutList.dat",ios::app |ios::binary);
                    kick<<rest<<endl;
                    kick.close();
                    break;
                }
                 case 14 :
                {
                    remove("DelfrioMenu.dat");
                    remove("DelfrioProfit.dat");
                    remove("DelfrioRatings.dat");
                    strcpy(rest,"Delfrio");
                    fstream kick;
                    kick.open("KickOutList.dat",ios::app |ios::binary);
                    kick<<rest<<endl;
                    kick.close();
                    break;
                }
                 case 15 :
                {
                    remove("DunkinDonutMenu.dat");
                    remove("DunkinDonutProfit.dat");
                    remove("DunkinDonutsRatings.dat");
                    strcpy(rest,"DunkinDonut");
                    fstream kick;
                    kick.open("KickOutList.dat",ios::app |ios::binary);
                    kick<<rest<<endl;
                    kick.close();
                    break;
                }
                case 16 :
                {
                    remove("VintageMenu.dat");
                    remove("VintageProfit.dat");
                    remove("VintageRatings.dat");
                    strcpy(rest,"Vintage");
                    fstream kick;
                    kick.open("KickOutList.dat",ios::app |ios::binary);
                    kick<<rest<<endl;
                    kick.close();
                    break;
                }
            }
        }
        private:
        void Login()
        {
            again1:
            Sleep(2000);
            system("cls");
            string dltcoupen;
            char ch;
            a:
            char id[20],pass[20]={0}; 
            int c;
            static int n=0;
            n=0;
                    cout << "\nInput ID : ";
                    cin >> id;
                    cout << "Enter passward : ";
                    asd:
                    char cha;
                    if(strcmp(id,"admin")==0)
                    {
                        cha = getch();
                        if(cha == 8)
                        {
                            system("cls");
                            goto a;
                        }
                        else
                        {
                            if(cha != 13)
                            {
                                cout << "*";
                                pass[n] = cha;
                                n++;
                                goto asd;
                            }
                            else
                            {
                                if(n>5)
                                {
                                    goto again1;
                                }
                                if(strcmp(pass,"admin")==0)
                                {
                                    twoway:
                                    char pass2[6]={0};
                                    cout << "\nEnter 2 way verification password : ";
                                    n = 0;
                                    bsd:
                                    cha = getch();
                                    if(cha == 8)
                                    {
                                        system("cls");
                                        goto twoway;
                                    }
                                    else
                                    {
                                        if(cha != 13)
                                        {
                                            cout << "*";
                                            pass2[n] = cha;
                                            n++;
                                            goto bsd;
                                        }
                                        else
                                        {
                                            for(int i=0;i<strlen(pass2);i++)
                                            {
                                                pass2[i] -= 3;
                                            }
                                            if(strcmp(pass2,"admin") == 0)//pass is dgplq
                                            {
                                                SetConsoleTextAttribute(hConsole, 2);
                                                cout<<"\n\t\t\t\t________________________________\n";
                                                cout<<"\t\t\t\tYou have successfuly Signed up!!\n";
                                                cout<<"\t\t\t\t________________________________\n";
                                                SetConsoleTextAttribute(hConsole, 15);
                                                Sleep(2000);
                                                AdminManagement();
                                            }
                                            else
                                            {
                                                SetConsoleTextAttribute(hConsole, 4);
                                                cout<<"\n\t\t\t\t ________________________________\n";
                                                cout<<"\t\t\t\t You Entered Wrong Password!!    \n";
                                                cout<<"\t\t\t\t ________________________________\n";
                                                SetConsoleTextAttribute(hConsole, 15);
                                                goto twoway;
                                            }  
                                        }
                                    }
                                }    
                                else
                                {
                                    cout << "\nwrong pass;";
                                    goto a;
                                }
                            }
                        }
                    }
                    else if(strcmp(id,"restaurant") == 0)
                    {
                        //pass[20]=0;
                        mno:
                        n=0;
                        csd:
                        cin.clear();
                        cha = getch();
                        if(cha == 8)
                        {
                            pass[20]=0;
                            system("cls");
                            cout << "\nInput ID : ";
                            cin >> id;
                            cout << "Enter passward : ";
                            goto mno;
                        }
                        else
                        {
                            if(cha!=13)
                            {
                                cout << "*";
                                pass[n] = cha;
                                n++;
                                goto csd;
                            }
                            else
                            {
                                if(strcmp(pass,"hutpizza")==0)
                                {
                                    cout << "\n\t\t---WELCOME TO PIZZAHUT---\n\n";
                                    Restaurant pizzahut;
                                    AllRestaurants("PizzahutMenu.dat",pizzahut);    
                                }
                                else if(strcmp(pass,"forniacali")==0)
                                {
                                    cout << "\n\t\t---WELCOME TO CALIFORNIA---\n\n";
                                    Restaurant california;
                                    AllRestaurants("CaliforniaMenu.dat",california);        
                                }
                                else if(strcmp(pass,"waybroad")==0)
                                {
                                    cout << "\n\t\t---WELCOME TO BROADWAY---\n\n";
                                    Restaurant broadway;
                                    AllRestaurants("BroadwayMenu.dat",broadway);      
                                }
                                else if(strcmp(pass,"yorknew")==0)
                                {
                                    cout << "\n\t\t---WELCOME TO NEW YORK---\n\n";
                                    Restaurant newyork;
                                    AllRestaurants("NewYorkMenu.dat",newyork);      
                                }
                                else if(strcmp(pass,"labburger")==0)
                                {
                                    cout << "\n\t\t---WELCOME TO BURGER LAB---\n\n";
                                    Restaurant burgerlab;
                                    AllRestaurants("BurgerLabMenu.dat",burgerlab);      
                                }
                                else if(strcmp(pass,"clockoburger")==0)
                                {
                                    cout << "\n\t\t---WELCOME TO BURGER'O CLOCK---\n\n";
                                    Restaurant burgeroclock;
                                    AllRestaurants("BurgerOClockMenu.dat",burgeroclock);      
                                }
                                else if(strcmp(pass,"kingburger")==0)
                                {
                                    cout << "\n\t\t---WELCOME TO BURGER KING---\n\n";
                                    Restaurant burgerking;
                                    AllRestaurants("BurgerKingMenu.dat",burgerking);      
                                }
                                else if(strcmp(pass,"shakeburger")==0)
                                {
                                    cout << "\n\t\t---WELCOME TO BURGER SHAKE---\n\n";
                                    Restaurant burgershake;
                                    AllRestaurants("BurgerShakeMenu.dat",burgershake);      
                                }
                                else if(strcmp(pass,"friodel")==0)
                                {
                                    cout << "\n\t\t---WELCOME TO DEL FRIO---\n\n";
                                    Restaurant delfrio;
                                    AllRestaurants("DelfrioMenu.dat",delfrio);      
                                }
                                else if(strcmp(pass,"ziadeli")==0)
                                {
                                    cout << "\n\t\t---WELCOME TO DELIZIA---\n\n";
                                    Restaurant delizia;
                                    AllRestaurants("DeliziaMenu.dat",delizia);                          
                                }
                                else if( strcmp(pass,"agevint")==0)
                                {
                                    cout << "\n\t\t---WELCOME TO VINATAGE---\n\n";
                                    Restaurant vintage;
                                    AllRestaurants("VintageMenu.dat",vintage);                  
                                }
                                else if(strcmp(pass,"donutndunk")==0)
                                {
                                    cout << "\n\t\t---WELCOME TO DUNKIN DONUT---\n\n";
                                    Restaurant dunkindonut;
                                    AllRestaurants("DunkinDonutMenu.dat",dunkindonut);    
                                }
                                else if(strcmp(pass,"lerssizz")==0)
                                {
                                    cout << "\n\t\t---WELCOME TO SIZZLERS---\n\n";
                                    Restaurant sizzlers;
                                    AllRestaurants("SizzlersMenu.dat",sizzlers);      
                                }
                                else if(strcmp(pass,"sinfood")==0)
                                {
                                    cout << "\n\t\t---WELCOME TO FOODS IN---\n\n";
                                    Restaurant foodsin;
                                    AllRestaurants("FoodsInMenu.dat",foodsin);  
                                }
                                else if(strcmp(pass,"boobam")==0)
                                {
                                    cout << "\n\t\t---WELCOME TO BAMBOO---\n\n";
                                    Restaurant bamboo;
                                    AllRestaurants("BambooMenu.dat",bamboo);  
                                }
                                else if( strcmp(pass,"jeeskabab")==0)
                                {
                                    cout << "\n\t\t---WELCOME TO KABABJEES---\n\n";
                                    Restaurant kababjees;
                                    AllRestaurants("KababjeesMenu.dat",kababjees);  
                                }
                                else
                                {
                                    cout<<"\nWrong ID or Password";
                                    goto again1;
                                }
                           
                            }
                        }
                    }
                    else
                    {
                        cout<<"\nWrong ID or Password";
                        goto again1;
                    }
                }
                void AllRestaurants(string filename,Restaurant resto)
                {
                    int choice, i;
                    start:
                    cout << "What do you want to do? \n";
                    cout << "1 <<< Add records\n";
                    cout << "2 <<< Delete a record\n";
                    cout << "3 <<< Update any record\n";
                    cout << "4 <<< Show Records\n";
                    cout << "5 <<< Back to Start.\n";
                    cout << "0 <<< Exit\n";
                    try
                    {
                        cin >> choice;
                        if(!cin)
                        {
                            throw "Exception Handled ,Please Input Again to Proceed";
                        }
                        else
                        {
                            if(choice==1)
                            {
                                int num;
                                cout << "How many records you want to add ? ";
                                cin >> num;
                                for(i=1;i<=num;i++)
                                resto.InputData(filename);
                                cout << "Congratulations! Record Successfully added!\n\n";
                                goto start;
                            }
                            else if(choice==2)
                            {
                                resto.ViewAllRecords(filename);
                                resto.deleteRecord(filename);
                                cout << "Updated Records\n";
                                resto.ViewAllRecords(filename);
                                goto start;
                            }  
                            else if(choice==3)
                            {
                                resto.updateRecord(filename);
                                cout << "Updated Records\n";    
                                resto.ViewAllRecords(filename);
                                goto start;
                            }
                            else if(choice==4)
                            {
                                resto.ViewAllRecords(filename);
                                goto start;
                            }
                            else if(choice==5)
                            {
                                main();
                            }
                            else if(choice==0)
                            {
                                exit (0);
                            }
                        }
                    }
                    catch(char const* a)
                    {
                        system("cls");
                        cout<<endl<<a;
                        cin.clear();
                        cin.ignore();
                        goto start;
                    }  
                }
                void AdminManagement()
                {
                    system("cls");
                    int c;  
                    O:
                    Admin admin;
                    cout << "\n\t\t---WELCOME ADMIN!---\n";
                    cout << "\n1 <<< Add coupen Number";
                    cout << "\n2 <<< Delete coupen Number";
                    cout << "\n3 <<< Show All coupen Numbers";
                    cout << "\n4 <<< Review Restaurant Avg Ratings.";
                    cout << "\n5 <<< Review Profit.";
                    cout << "\n6 <<< Kick Out the Restaurant!!";
                    cout << "\n7 <<< back to Main Menu.";
                    try
                    {
                        cin >> c;
                        if(!cin)
                        {
                            throw "Exception Handled ,Plz Input Again to Proceed";
                        }
                        else
                        {
                            switch(c)
                            {
                                case 1:
                                {
                                    admin.AddCoupen();
                                    goto O;
                                }
                                case 2:
                                {
                                    admin.ViewAllCoupens();
                                    admin.deleteCoupen();
                                    goto O;
                                }
                                case 3:
                                {
                                    admin.ViewAllCoupens();
                                    goto O;
                                }
                                case 4:
                                {
                                    admin.ViewRestaurantsRating();
                                    goto O;
                                }                
                                case 5:
                                {
                                    admin.Profit();
                                    goto O;
                                }
                                case 6:
                                {
                                    admin.KickOut();
                                    goto O;
                                }
                                case 7:
                                {
                                    main();
                                }
                                default:
                                goto O;
                                           
                            }      
                        }
                    }
                    catch(char const* a)
                    {
                        system("cls");
                        cout<<endl<<a;
                        cin.clear();
                        cin.ignore();
                        goto O;
                    }  
                }
                public:
                void getLogin()
                {
                    Login();
                }
                ~Admin(){};
 
}am;
double Restaurant::total=0;
void ChooseCategory()
{
    category:
    int phlag1=0,phlag2=0,phlag3=0,phlag4=0;
    char number;
    char choice;
    cout << "\n------Choose Your Category------\n";
    cout << "P <<< Pizza\n";
    cout << "B <<< Burger\n";
    cout << "C <<< Continental\n";
    cout << "D <<< Dessert\n";
    cout << "0 <<< Back to Main Menu or Login to other account.";
    cin >> choice;
    if(choice=='p'||choice=='P')
    {
        fstream kick;
        kick.open("KickOutList.dat",ios::in |ios::binary);
        if(kick.is_open())
        {
            while(kick>>rest)
            {
                if(strcmp(rest,"Pizzahut")==0)
                phlag1=1;
                else if(strcmp(rest,"Broadway")==0)
                phlag2=1;
                else if(strcmp(rest,"NewYork")==0)        
                phlag3=1;
                else if(strcmp(rest,"California")==0)
                phlag4=1;            
            }
        }
        begin1:
        cout << "\t-------Choose Your Favourite Restaurant-------\n";
        if(phlag1==0)
        {
            cout << "P <<< Pizza Hut\n";
        }
        if(phlag2==0)
        {
            cout << "B <<< Broadway Pizza\n";
        }
        if(phlag3==0)
        {
            cout << "N <<< New York Pizza\n";
        }
        if(phlag4==0)
        {
            cout << "C <<< California Pizza\n";
        }
        cout << "0 <<< To choose any other category" << endl;
        cout <<" \nAny other key to exit!\n";
        cin >> number;
        switch(number)
            {
                case 'P':
                case 'p':
                {
                    Admin pizzahut;
                    pizzahut.ViewAllRecords("PizzahutMenu.dat");
                    pizzahut.PlaceOrder("PizzahutMenu.dat");
                    pizzahut.CustomerDetails();
                    pizzahut.CalculateProfit("PizzahutProfit.dat");
                    pizzahut.OrderDetails();
                    pizzahut.DeliveryNotfications();
                    pizzahut.Rating("PizzaHutRatings.dat");
                    break;
                }
                case 'B':
                case 'b':
                {
                    Admin broadway;
                    broadway.ViewAllRecords("BroadwayMenu.dat");            
                    broadway.PlaceOrder("BroadwayMenu.dat");
                    broadway.CustomerDetails();
                    broadway.CalculateProfit("BroadwayProfit.dat");
                    broadway.OrderDetails();
                    broadway.DeliveryNotfications();
                    broadway.Rating("BroadwayRatings.dat");
                    break;            
                }
                case 'N':
                case 'n':
                {
                    Admin newyork;
                    newyork.ViewAllRecords("NewYorkMenu.dat");
                    newyork.PlaceOrder("NewYorkMenu.dat");
                    newyork.CustomerDetails();
                    newyork.CalculateProfit("NewyorkProfit.dat");
                    newyork.OrderDetails();
                    newyork.DeliveryNotfications();
                    newyork.Rating("NewyorkRatings.dat");
                    break;
                }
                case 'C':
                case 'c':
                {
                    Admin california;
                    california.ViewAllRecords("CaliforniaMenu.dat");
                    california.PlaceOrder("CaliforniaMenu.dat");
                    california.CustomerDetails();
                    california.CalculateProfit("CaliforniaProfit.dat");
                    california.OrderDetails();
                    california.DeliveryNotfications();
                    california.Rating("CaliforniaRatings.dat");
                    break;          
                }
                case '0':
                {
                    ChooseCategory();
                }
                default:
                {
                    exit(1);
                }
            }
    }
    else if(choice=='b'||choice=='B')
    {
        fstream kick;
        kick.open("KickOutList.dat",ios::in |ios::binary);
        if(kick.is_open())
        {
            while(kick>>rest)
            {
                if(strcmp(rest,"BurgerLab")==0)
                phlag1=2;
                else if(strcmp(rest,"BurgerShake")==0)
                phlag2=2;
                else if(strcmp(rest,"BurgerOClock")==0)        
                phlag3=2;
                else if(strcmp(rest,"BurgerKing")==0)
                phlag4=2;            
            }
        }
        cout << "\t-------Choose Your Favourite Restaurant-------\n";
        if(phlag1==0)
        cout << "L <<< Burger Lab\n";
        if(phlag2==0)
        cout << "S <<< Burger Shake\n";
        if(phlag3==0)
        cout << "C <<< Burger'O Clock\n";
        if(phlag4==0)
        cout << "K <<< Burger King\n";
        cout << "0 <<< To choose any other category" << endl;
        cout << "Any other key to exit\n";
        cin >> number;
        switch(number)
            {
                case 'L':
                case 'l':
                {      
                    Admin burgerlab;
                    burgerlab.ViewAllRecords("BurgerLabMenu.dat");
                    burgerlab.PlaceOrder("BurgerLabMenu.dat");
                    burgerlab.CustomerDetails();
                    burgerlab.CalculateProfit("BurgerLabProfit.dat");
                    burgerlab.OrderDetails();
                    burgerlab.DeliveryNotfications();
                    burgerlab.Rating("BurgerLabRatings.dat");                  
                    break;    
                }  
                case 'S':
                case 's':
                {  
                    Admin burgershake;
                    burgershake.ViewAllRecords("BurgerShakeMenu.dat");
                    burgershake.PlaceOrder("BurgerShakeMenu.dat");
                    burgershake.CustomerDetails();
                    burgershake.CalculateProfit("BurgerShakeProfit.dat");
                    burgershake.OrderDetails();
                    burgershake.DeliveryNotfications();
                    burgershake.Rating("BurgerShakeRatings.dat");
                    break;
                }
                case 'C':
                case 'c':
                {  
                    Admin burgeroclock;
                    burgeroclock.ViewAllRecords("BurgerOClockMenu.dat");
                    burgeroclock.PlaceOrder("BurgerOClockMenu.dat");
                    burgeroclock.CustomerDetails();
                    burgeroclock.CalculateProfit("BurgerOClockProfit.dat");
                    burgeroclock.OrderDetails();  
                    burgeroclock.DeliveryNotfications();
                    burgeroclock.Rating("BurgerOClockRatings.dat");
                    break;
                }
                case 'K':
                case 'k':
                {
                    Admin burgerking;
                    burgerking.ViewAllRecords("BurgerKingMenu.dat");
                    burgerking.PlaceOrder("BurgerKingMenu.dat");
                    burgerking.CustomerDetails();
                    burgerking.CalculateProfit("BurgerKingProfit.dat");
                    burgerking.OrderDetails();
                    burgerking.DeliveryNotfications();
                    burgerking.Rating("BurgerKingRatings.dat");
                    break;
                }
                case '0':
                {
                    ChooseCategory();
                    break;
                }
                default:
                {
                    exit(1);
                }
            }
    }
    else if(choice=='C'||choice=='c')
    {
        fstream kick;
        kick.open("KickOutList.dat",ios::in |ios::binary);
        if(kick.is_open())
        {
            while(kick>>rest)
            {
                if(strcmp(rest,"Sizzlers")==0)
                phlag1=3;
                else if(strcmp(rest,"Bamboo")==0)
                phlag2=3;
                else if(strcmp(rest,"FoodsIn")==0)        
                phlag3=3;
                else if(strcmp(rest,"Kababjees")==0)
                phlag4=3;            
            }
        }
        cout << "\t-------Choose Your Favourite Restaurant-------\n";
        if(phlag1==0)
        cout << "S <<< Sizzlers\n";
        if(phlag2==0)
        cout << "B <<< Bamboo\n";
        if(phlag3==0)
        cout << "F <<< Foods In\n";
        if(phlag4==0)
        cout << "K <<< Kababjees\n";
        cout << "5 <<< To choose any other category." << endl;
        cout << "Any other key to exit\n";
        cin >> number;
        switch(number)
            {
                case 'S':
                case 's':
                {
                    Admin sizzlers;
                    sizzlers.ViewAllRecords("SizzlersMenu.dat");
                    sizzlers.PlaceOrder("SizzlersMenu.dat");
                    sizzlers.CustomerDetails();
                    sizzlers.CalculateProfit("SizzlersProfit.dat");
                    sizzlers.OrderDetails();
                    sizzlers.DeliveryNotfications();
                    sizzlers.Rating("SizzlersRatings.dat");
                    break;
                   
                }
                case 'B':
                case 'b':
                {
                    Admin bamboo;
                    bamboo.ViewAllRecords("BambooMenu.dat");
                    bamboo.PlaceOrder("BambooMenu.dat");
                    bamboo.CustomerDetails();
                    bamboo.CalculateProfit("BambooProfit.dat");
                    bamboo.OrderDetails();
                    bamboo.DeliveryNotfications();
                    bamboo.Rating("BambooRatings.dat");
                    break;
                }
                case 'F':
                case 'f':
                {
                    Admin foodsin;
                    foodsin.ViewAllRecords("FoodsInMenu.dat");
                    foodsin.PlaceOrder("FoodsInMenu.dat");
                    foodsin.CustomerDetails();
                    foodsin.CalculateProfit("FoodsInProfit.dat");
                    foodsin.OrderDetails();
                    foodsin.DeliveryNotfications();
                    foodsin.Rating("FoodsInRatings.dat");
                    break;                  
                }
                case 'K':
                case 'k':
                {
                    Admin kababjees;
                    kababjees.ViewAllRecords("KababjeesMenu.dat");
                    kababjees.PlaceOrder("KababjeesMenu.dat");
                    kababjees.CustomerDetails();
                    kababjees.CalculateProfit("KababjeesProfit.dat");
                    kababjees.OrderDetails();
                    kababjees.DeliveryNotfications();
                    kababjees.Rating("KababJeesRatings.dat");
                    break;
                }
                case '0':
                {
                    ChooseCategory();
                }
                default:
                {
                    exit(1);
                }
            }
    }
    else if(choice=='D'||choice=='d')
    {
        fstream kick;
        kick.open("KickOutList.dat",ios::in |ios::binary);
        if(kick.is_open())
        {
            while(kick>>rest)
            {
                if(strcmp(rest,"Delizia")==0)
                phlag1=4;
                else if(strcmp(rest,"Delfrio")==0)
                phlag2=4;
                else if(strcmp(rest,"DunkinDonut")==0)        
                phlag3=4;
                else if(strcmp(rest,"Vintage")==0)
                phlag4=4;            
            }
        }
        cout << "\t-------Choose Your Favourite Restaurant-------\n";
        if(phlag1==0)
        cout << "Z <<< Delizia\n";
        if(phlag2==0)
        cout << "F <<< Delfrio\n";
        if(phlag3==0)
        cout << "D <<< Dunkin Donut\n";
        if(phlag4==0)
        cout << "V <<< Vintage\n";
        cout<<"Press 5. back to choos category."<<endl;
        cout << "Any other key to exit\n";
        cin >> number;
        switch(number)
            {
                case 'z':
                case 'Z':
                {
                    Admin delizia;
                    delizia.ViewAllRecords("DeliziaMenu.dat");
                    delizia.PlaceOrder("DeliziaMenu.dat");
                    delizia.CustomerDetails();
                    delizia.CalculateProfit("DeliziaProfit.dat");
                    delizia.OrderDetails();
                    delizia.DeliveryNotfications();
                    delizia.Rating("DeliziaRatings.dat");
                    break;
                }
                case 'f':
                case 'F':
                {
                   
                        Admin delfrio;
                        delfrio.ViewAllRecords("DelfrioMenu.dat");
                        delfrio.PlaceOrder("DelfrioMenu.dat");
                        delfrio.CustomerDetails();
                        delfrio.CalculateProfit("DelfrioProfit.dat");
                        delfrio.OrderDetails();
                        delfrio.DeliveryNotfications();
                        delfrio.Rating("DelfrioRatings.dat");
                        break;
                }
                case 'D':
                case 'd':
                {
                    Admin dunkindonut;
                    dunkindonut.ViewAllRecords("DunkinDonutMenu.dat");
                    dunkindonut.PlaceOrder("DunkinDonutMenu.dat");
                    dunkindonut.CustomerDetails();
                    dunkindonut.CalculateProfit("DunkinDonutProfit.dat");
                    dunkindonut.OrderDetails();
                    dunkindonut.DeliveryNotfications();
                    dunkindonut.Rating("DunkinDonutsRatings.dat");
                    break;
                }
                case 'V':
                case 'v':
                {
                    Admin vintage;
                    vintage.ViewAllRecords("VintageMenu.dat");
                    vintage.PlaceOrder("VintageMenu.dat");
                    vintage.CustomerDetails();
                    vintage.CalculateProfit("VintageProfit.dat");
                    vintage.OrderDetails();
                    vintage.DeliveryNotfications();
                    vintage.Rating("VintageRatings.dat");
                    break;
                }
                case '0':
                {
                    ChooseCategory();
                }
                default:
                {
                    exit(1);
                }
            }
    }
    else if(choice=='0')
    {
        main();
    }
}
/*
The different color codes are
0   BLACK
1   BLUE
2   GREEN
3   CYAN
4   RED
5   MAGENTA
6   BROWN
7   LIGHTGRAY
8   DARKGRAY
9   LIGHTBLUE
10  LIGHTGREEN
11  LIGHTCYAN
12  LIGHTRED
13  LIGHTMAGENTA
14  YELLOW
15  WHITE
*/
int main()
{   
    int choice;
    char option,ch=219;
    char id[15], pass[15];
    Sleep(2000);
    start:
    system("cls");
    cout << "\t\t\t\t************************************************\n ";
    cout << "\t\t\t\t------------WELCOME TO FOOD DELIVERO------------\n";
    cout << "\t\t\t\t************************************************\n ";
    cout<<"\t\t\t\tLoading...Please Wait\n\t\t\t\t";
    SetConsoleTextAttribute(hConsole, 14);
    for(int i=0;i<48;i++) 
    {
        Sleep(20);
        cout<<ch;
    }
    SetConsoleTextAttribute(hConsole, 15);
    cout << "\nLet us know your identity? \n";
    cout << "U <<< User\n";
    cout << "A <<< Admin\n";
    cin >> option;
    cout << endl;
    if(option == 'u'||option == 'U')
    {
        again:
        cout <<"\t\t\t\t --------------------------------------- \n";
        cout <<"\t\t\t\t|"<< "\tLogin or create an account\t|\n";
        cout <<"\t\t\t\t|"<< "\t1 <<< Login               \t|\n";
        cout <<"\t\t\t\t|"<< "\t2 <<< Create an account   \t|\n";
        cout <<"\t\t\t\t ---------------------------------------\n";
        cin >> choice;

        try
        {
            if(choice != 1 && choice != 2)
            throw choice;
        }
        catch(...)
        {
            cout << "Exception caught\n";
            cin.clear();
            cin.ignore();
            goto again;
        }
        switch(choice)
        {
            case 1:
            {
                repeat:
                cout << "Enter ID : ";
                cin >> id;
                cout << "Enter Passward : ";
                cin >> pass;
                c.LoginCustomer(id,pass);
                break;
            }
            case 2:
            {
                c.SetCustomerData();
                cout << "\n************************New ID has been Created. Please Login to Proceed ************************\n";
                goto again;
            }
        }
    }
    else if(option == 'A'|| option == 'a')
    {
        fflush(stdin);
        am.getLogin();
    }
    else
    {
        cout << "Input Valid Choice\n";
        goto start;
    }
   
}
