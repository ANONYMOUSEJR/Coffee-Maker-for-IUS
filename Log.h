#pragma once

#include<iostream>
#include<fstream>

void logCoffee(int* coffeeCups){

    std::ofstream dbW("database.txt",std::ios_base::out);


    for(int i=0; i<5; i++){
        switch (i){
        
        case 0:
                dbW<<"Latte: "<<coffeeCups[i]<<'\n';
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

}