#pragma once

#include<iostream>
#include<fstream>
#include<iostream>
#include<fstream>
#include<string>
#include <algorithm>


void logCoffee(int coffeeCups[], int coinsAmmount[]){

    time_t rawDate = time(nullptr);// taking the time as second
    std::string date = ctime(&rawDate);

    std::replace(date.begin(), date.end(), ' ','_');
    std::replace(date.begin(), date.end(), ':','-');
    std::replace(date.begin(), date.end(), '\n','.');

    date += "txt";

    //std::cout<< date <<"\n";


    std::ofstream dbW(date,std::ios_base::out);

    dbW<<"lefted Coffee:\n";
    for(int i=0; i<5; i++){
        switch (i){
        
        case 0:
                dbW<<"Latte: "<<coffeeCups[i]<<'\n';
                //ctotal + = 1 * coffeeCups[i];
            break;

        case 1:
                dbW<<"Capu: "<<coffeeCups[i]<<'\n';
            break;
        
        case 2:
                dbW<<"Kafa: "<<coffeeCups[i]<<'\n';
            break;
        
        case 3:
                dbW<<"Kahve: "<<coffeeCups[i]<<'\n';
            break;

        case 4:
                dbW<<"Kola: "<<coffeeCups[i]<<'\n';
            break;
        
        default:
            break;
        }
    }

    dbW<<"\nCoin amounts:\n";

    double total = 0;

    for(int i=0; i<7; i++){
        switch (i){
        
        case 0:
                dbW<<"0.5: "<<coinsAmmount[i]<<'\n';
                total += 0.5*coinsAmmount[i];
            break;

        case 1:
                dbW<<"0.1: "<<coinsAmmount[i]<<'\n';
                total += 0.1*coinsAmmount[i];
            break;
        
        case 2:
                dbW<<"0.2: "<<coinsAmmount[i]<<'\n';
                total += 0.2*coinsAmmount[i];
            break;
        
        case 3:
                dbW<<"1: "<<coinsAmmount[i]<<'\n';
                total += 1*coinsAmmount[i];
            break;

        case 4:
                dbW<<"5: "<<coinsAmmount[i]<<'\n';
                total += 5*coinsAmmount[i];
            break;
        case 5:
                dbW<<"10: "<<coinsAmmount[i]<<'\n';
                total += 10*coinsAmmount[i];
            break;
        case 6:
                dbW<<"20: "<<coinsAmmount[i]<<'\n';
                total += 20*coinsAmmount[i];
            break;
        default:
            break;
        }
    }


    dbW<<"\nTotal: "<<total<<" KM.\n\nEnd of the File\n\n";


}
