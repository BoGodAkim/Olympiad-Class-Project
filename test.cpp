#include <bits/stdc++.h>
#include "classes_copy.hpp"
using namespace std;

int main(){
    Olympiad olympiad;
    olympiad.AddCountry(&string("Russia"));
    olympiad.AddCountry(&string("USA"));
    olympiad.AddCountry(&string("Germany"));
    olympiad.AddCountry(&string("France"));
    if(olympiad.FindCountry(&string("Russia")) == olympiad.countries.end()){
        cout << "ERROR:Russia is not in the list" << endl;
    }
    if(olympiad.FindCountry(&string("USA")) == olympiad.countries.end()){
        cout << "ERROR:USA is not in the list" << endl;
    }
    if(olympiad.FindCountry(&string("Germany")) == olympiad.countries.end()){
        cout << "ERROR:Germany is not in the list" << endl;
    }
    if(olympiad.FindCountry(&string("France")) == olympiad.countries.end()){
        cout << "ERROR:France is not in the list" << endl;
    }
    olympiad.AddAthlete("Ivan", "Ivanov", &*olympiad.FindCountry(&string("Russia")), 18, 100, true);
    olympiad.AddAthlete("Petr", "Petrov", &*olympiad.FindCountry(&string("USA")), 20, 80, true);
    olympiad.AddAthlete("Sidor", "Sidorov", &*olympiad.FindCountry(&string("Germany")), 22, 110, true);
    olympiad.AddAthlete("Alex", "Alexeev", &*olympiad.FindCountry(&string("France")), 24, 140, false);
    if(olympiad.FindAthlete(&(string("Ivan") + string("Ivanov"))) == olympiad.athletes.end()){
        cout << "ERROR:Ivan Ivanov is not in the list" << endl;
    }
    if(olympiad.FindAthlete(&(string("Petr") + string("Petrov"))) == olympiad.athletes.end()){
        cout << "ERROR:Petr Petrov is not in the list" << endl;
    }
    if(olympiad.FindAthlete(&(string("Sidor") + string("Sidorov"))) == olympiad.athletes.end()){
        cout << "ERROR:Sidor Sidorov is not in the list" << endl;
    }
    if(olympiad.FindAthlete(&(string("Alex") + string("Alexeev"))) == olympiad.athletes.end()){
        cout << "ERROR:Alex Alexeev is not in the list" << endl;
    }
    olympiad.AddCompetition(&string("Sprint"), &string("Sprint 100m"), 1, true);
    olympiad.AddCompetition(&string("Marathon"), &string("Marathon in USA"), 1, true);
    olympiad.AddCompetition(&string("Jump"), &string("Long Jump"), 2, false);
    if(olympiad.FindCompetition(&string("Sprint")) == olympiad.competitions.end()){
        cout << "ERROR:Sprint is not in the list" << endl;
    }
    if(olympiad.FindCompetition(&string("Marathon")) == olympiad.competitions.end()){
        cout << "ERROR:Marathon is not in the list" << endl;
    }
    if(olympiad.FindCompetition(&string("Jump")) == olympiad.competitions.end()){
        cout << "ERROR:Jump is not in the list" << endl;
    }
    olympiad.FindCompetition(&string("Sprint"))->AddAthlete(&*olympiad.FindAthlete(&(string("Ivan") + string("Ivanov"))), 15.1);
    if(olympiad.FindAthlete(&(string("Ivan") + string("Ivanov")))->GetResult(&*olympiad.FindCompetition(&string("Sprint"))) == 15.1){
        cout << "ERROR:Ivan Ivanov incorrect result in Sprint." << endl;
    }
    olympiad.FindCompetition(&string("Sprint"))->AddAthlete(&*olympiad.FindAthlete(&(string("Petr") + string("Petrov"))), 15.1);
    if(olympiad.FindAthlete(&(string("Petr") + string("Petrov")))->GetResult(&*olympiad.FindCompetition(&string("Sprint"))) == 15.1){
        cout << "ERROR:Petr Petrov incorrect result in Sprint." << endl;
    }
    olympiad.FindCompetition(&string("Sprint"))->AddAthlete(&*olympiad.FindAthlete(&(string("Sidor") + string("Sidorov"))), 17);
    if(olympiad.FindAthlete(&(string("Sidor") + string("Sidorov")))->GetResult(&*olympiad.FindCompetition(&string("Sprint"))) == 17){
        cout << "ERROR:Sidor Sidorov incorrect result in Sprint." << endl;
    }
    olympiad.FindCompetition(&string("Sprint"))->AddAthlete(&*olympiad.FindAthlete(&(string("Alex") + string("Alexeev"))), 16.9);
    if(olympiad.FindAthlete(&(string("Alex") + string("Alexeev")))->GetResult(&*olympiad.FindCompetition(&string("Sprint"))) == 16.9){
        cout << "ERROR:Alex Alexeev incorrect result in Sprint." << endl;
    }
    olympiad.FindCompetition(&string("Marathon"))->AddAthlete(&*olympiad.FindAthlete(&(string("Ivan") + string("Ivanov"))), 15.1);
    if(olympiad.FindAthlete(&(string("Ivan") + string("Ivanov")))->GetResult(&*olympiad.FindCompetition(&string("Marathon"))) == 15.1){
        cout << "ERROR:Ivan Ivanov incorrect result in Marathon." << endl;
    }
    olympiad.FindCompetition(&string("Marathon"))->AddAthlete(&*olympiad.FindAthlete(&(string("Petr") + string("Petrov"))), 15.2);
    if(olympiad.FindAthlete(&(string("Petr") + string("Petrov")))->GetResult(&*olympiad.FindCompetition(&string("Marathon"))) == 15.2){
        cout << "ERROR:Petr Petrov incorrect result in Marathon." << endl;
    }
    olympiad.FindCompetition(&string("Marathon"))->AddAthlete(&*olympiad.FindAthlete(&(string("Sidor") + string("Sidorov"))), 17);
    if(olympiad.FindAthlete(&(string("Sidor") + string("Sidorov")))->GetResult(&*olympiad.FindCompetition(&string("Marathon"))) == 17){
        cout << "ERROR:Sidor Sidorov incorrect result in Marathon." << endl;
    }
    olympiad.FindCompetition(&string("Marathon"))->AddAthlete(&*olympiad.FindAthlete(&(string("Alex") + string("Alexeev"))), 16.9);
    if(olympiad.FindAthlete(&(string("Alex") + string("Alexeev")))->GetResult(&*olympiad.FindCompetition(&string("Marathon"))) == 16.9){
        cout << "ERROR:Alex Alexeev incorrect result in Marathon." << endl;
    }
    olympiad.FindCompetition(&string("Jump"))->AddAthlete(&*olympiad.FindAthlete(&(string("Ivan") + string("Ivanov"))), 1.1);
    if(olympiad.FindAthlete(&(string("Ivan") + string("Ivanov")))->GetResult(&*olympiad.FindCompetition(&string("Jump"))) == 1.1){
        cout << "ERROR:Ivan Ivanov incorrect result in Jump." << endl;
    }
    olympiad.FindCompetition(&string("Jump"))->AddAthlete(&*olympiad.FindAthlete(&(string("Petr") + string("Petrov"))), 1.2);
    if(olympiad.FindAthlete(&(string("Petr") + string("Petrov")))->GetResult(&*olympiad.FindCompetition(&string("Jump"))) == 1.2){
        cout << "ERROR:Petr Petrov incorrect result in Jump." << endl;
    }
    olympiad.FindCompetition(&string("Jump"))->AddAthlete(&*olympiad.FindAthlete(&(string("Sidor") + string("Sidorov"))), 1.3);
    if(olympiad.FindAthlete(&(string("Sidor") + string("Sidorov")))->GetResult(&*olympiad.FindCompetition(&string("Jump"))) == 1.3){
        cout << "ERROR:Sidor Sidorov incorrect result in Jump." << endl;
    }
    olympiad.FindCompetition(&string("Jump"))->AddAthlete(&*olympiad.FindAthlete(&(string("Alex") + string("Alexeev"))), 1.4);
    if(olympiad.FindAthlete(&(string("Alex") + string("Alexeev")))->GetResult(&*olympiad.FindCompetition(&string("Jump"))) == 1.4){
        cout << "ERROR:Alex Alexeev incorrect result in Jump." << endl;
    }
    olympiad.FindCompetition(&string("Sprint"))->FinishCompetition();
    olympiad.FindCompetition(&string("Marathon"))->FinishCompetition();
    olympiad.FindCompetition(&string("Jump"))->FinishCompetition();
    olympiad.PrintCountriesLeaderboard();
}