
#include <iostream>	//library for input/output
#include <string>	//library for strings
#include <fstream>	//for the file opening
#include <iomanip>	//library for setw
using namespace std;
//Prototype Identities
void get_store_data (ifstream&, string[], float[][5]);
float compute_store_total (float[][5], int);
void display_store_data (string[], float[][5], float[]);
int main()
{
    const int max_row = 7;
    const int max_column = 5;
    string name_array[max_row];     //1D array
    float sales_array[max_row][max_column]; //2D array
    float storeTotal[7];
    ifstream myfile;	//file into code
    get_store_data(myfile, name_array, sales_array);    //calls the get store data functin
    for (int store_index = 0; store_index < 7; store_index++) //for loop for store index
    {
        storeTotal[store_index] = compute_store_total (sales_array, store_index);
    }
    display_store_data (name_array, sales_array, storeTotal);   //calls the display_store_data
    cin.get();
    
}

void get_store_data (ifstream& myfile, string name_array[], float sales_array[][5]) // void function that gets the store data from file
{
    myfile.open("infile.txt");
    string name;
    for (int i = 0; i < 7; i++)
    {
        myfile >> name_array[i];
        for (int x = 0; x < 5; x++)
        {
            myfile >> sales_array[i][x];
            
        }
    }
}

float compute_store_total (float sales_array[][5], int store_index) //Value returning function to compute store total
{
    float store_total = 0;
    
    for(int column = 0; column < 5; column++)
    {
        store_total += sales_array[store_index][column];
    }
    return store_total;
}


void display_store_data (string name_array[], float sales_array[][5], float storeTotal[]) //Void function that displays the store data
{
    cout << "\tStore Name\t\t" << "JAN\t\t" << "FEB\t\t" << "MAR\t\t" << "APR\t\t" << "MAY\t\t" << "TOTAL\n" << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << name_array[i] << setw(9) << "\t";
        for(int col = 0; col < 5; col++)
        {
            cout << setw(8) << sales_array[i][col] << setw(9);
        }
        cout << storeTotal[i] << endl;
    }
    
}

//Store Name		JAN		FEB		MAR		APR		MAY		TOTAL
//
//Takomapar_store		2.7     71.3	14.7	23.9	51.2	163.8
//Bethesda_store		12.7       8.9     17.8	7.9     18.3	65.6
//Montgomery_store		22.2        23      32	54      65      196.2
//Wheaton_store         12          34      5    34     64      149
//Glenmont_store		33          65      23	65      65      251
//Hamshey_store         12          23      45	67      56      203
//Odd_Store             21          34      56  43      34      188

