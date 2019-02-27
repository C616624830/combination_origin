//
//  main.cpp
//  keyboard_layout_combination
//
//  Created by LeOOON on 2/26/19.
//  Copyright © 2019 LeOOON. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

void keyboard(int num, int rowsize, string& temp_array, int counter[],string arrayofString[]);
void set_content(int row, int num, string& temp_array,string array[]);
bool is_there(char cha,string row_string);

int main(int argc, const char * argv[]) {
    int num=26;
    string arrayofString[27];
    for(int i=0;i<num+1;i++){
        for(int j=0;j<num;j++){
        arrayofString[i]+=' ';
        }
    }//create (num+1) x num 2-d array, the fifth row is used to store each combination
    string temp_string="abcdefghijklmnopqrstuvwxyz";
    int counter[2]={0};
    keyboard(num, num, temp_string, counter, arrayofString);
    cout << counter[0]<<endl;
}

void keyboard(int num, int rowsize, string& temp_string, int counter[], string array[]){//num is the number of keys, size is the size of each row used, temp_array refers to like "abcdefghijklmnopqrstuvwxyz" which includes all the unique chars needed.
    if (rowsize>=1){
        set_content(num-rowsize,num,temp_string,array);//set content for the current row,current row may have different contents depending on the
        for (int i=0;i<rowsize;i++){
            char a=array[num-rowsize][i];//num-rowsize is the row_number
            array[num][num-rowsize]=a;//set the num-th element of the keyboard
            for (int j=num-rowsize+1;j<num;j++){//used to erase the unused elements in the last row of the arrayofString
                array[num][j]=' ';
            }
            keyboard(num, rowsize-1, temp_string, counter, array);
        }
    }
    else{
        //cout<<array[num]<<endl;
        counter[0]++;//used to count then umber of keyboard layouts, should be num!
    }
}

void set_content(int row, int num, string& temp_string,string array[]){//arraysize is the size of current row, row is the row#, num is the number of keys
    string temp;
    //cout << array[num] <<endl;
    for(int i=0;i<num;i++){
        if(!is_there(temp_string[i], array[num])){
            temp+=temp_string[i];
        }
    }
    //cout << temp <<endl;
    for(int i=0;i<temp.length();i++){
        array[row][i]=temp[i];
    }
}

bool is_there(char cha,string row_string){// row_string means the string of characters of a row
    for(int i=0;i<row_string.length();i++){
        if(cha == row_string[i]){
            return true;
        }
    }
    return false;
}

