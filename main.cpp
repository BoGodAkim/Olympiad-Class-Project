#include <bits/stdc++.h>
using namespace std;
#include "classes.hpp"
#include "Olympiad.cpp"
#include "Country.cpp"
#include "Competition.cpp"
#include "Athlete.cpp"

int main()
{
    string name = "Olympic Games 2018";
    string description = "Olympic Games 2018";
    Olympiad olympiad(&name, &description);
    string country_name = "Belarus";
    olympiad.AddCountry(&country_name);
    country_name = "USA";
    olympiad.AddCountry(&country_name);
    country_name = "Germany";
    olympiad.AddCountry(&country_name);
    country_name = "France";
    olympiad.AddCountry(&country_name);

    string athlete_name = "Vladimir";
    string athlete_surname = "Vladimir";
    int athlete_age = 35;
    int athlete_height = 180;
    int athlete_weight = 80;
    bool athlete_gender = false;
    country_name = "Belarus";
    olympiad.AddAthlete(&athlete_name, &athlete_surname, &*olympiad.FindCountry(&country_name), &athlete_age, &athlete_height, &athlete_weight, &athlete_gender);
    athlete_name = "Smith";
    athlete_surname = "Smith";
    athlete_age = 30;
    athlete_height = 150;
    athlete_weight = 70;
    athlete_gender = false;
    country_name = "USA";
    olympiad.AddAthlete(&athlete_name, &athlete_surname, &*olympiad.FindCountry(&country_name), &athlete_age, &athlete_height, &athlete_weight, &athlete_gender);
    athlete_name = "Kate";
    athlete_surname = "Kate";
    athlete_age = 20;
    athlete_height = 170;
    athlete_weight = 60;
    athlete_gender = true;
    country_name = "Germany";
    olympiad.AddAthlete(&athlete_name, &athlete_surname, &*olympiad.FindCountry(&country_name), &athlete_age, &athlete_height, &athlete_weight, &athlete_gender);
    athlete_name = "Sonia";
    athlete_surname = "Sonia";
    athlete_age = 25;
    athlete_height = 160;
    athlete_weight = 50;
    athlete_gender = true;
    country_name = "France";
    olympiad.AddAthlete(&athlete_name, &athlete_surname, &*olympiad.FindCountry(&country_name), &athlete_age, &athlete_height, &athlete_weight, &athlete_gender);
    
    string competition_name = "100m";
    string competition_description = "100m";
    int type_of_results = 1;
    bool first_place_is_smaller = true;
    olympiad.AddCompetition(&competition_name, &competition_description, &type_of_results, first_place_is_smaller);
    competition_name = "jump";
    competition_description = "jump";
    type_of_results = 2;
    first_place_is_smaller = false;
    olympiad.AddCompetition(&competition_name, &competition_description, &type_of_results, first_place_is_smaller);
    competition_name = "archery";
    competition_description = "archery";
    type_of_results = 3;
    first_place_is_smaller = false;
    olympiad.AddCompetition(&competition_name, &competition_description, &type_of_results, first_place_is_smaller);

    competition_name = "100m";
    athlete_name = "Vladimir";
    athlete_surname = "Vladimir";
    string athlete_name_surname = athlete_name + ' ' + athlete_surname;
    float result = 100;
    olympiad.AddResult(&*olympiad.FindCompetition(&competition_name), &*olympiad.FindAthlete(&athlete_name_surname), &result);
    athlete_name = "Smith";
    athlete_surname = "Smith";
    athlete_name_surname = athlete_name + ' ' + athlete_surname;
    result = 200;
    olympiad.AddResult(&*olympiad.FindCompetition(&competition_name), &*olympiad.FindAthlete(&athlete_name_surname), &result);
    athlete_name = "Kate";
    athlete_surname = "Kate";
    athlete_name_surname = athlete_name + ' ' + athlete_surname;
    result = 300;
    olympiad.AddResult(&*olympiad.FindCompetition(&competition_name), &*olympiad.FindAthlete(&athlete_name_surname), &result);
    athlete_name = "Sonia";
    athlete_surname = "Sonia";
    athlete_name_surname = athlete_name + ' ' + athlete_surname;
    result = 400;
    olympiad.AddResult(&*olympiad.FindCompetition(&competition_name), &*olympiad.FindAthlete(&athlete_name_surname), &result);
    competition_name = "jump";
    athlete_name = "Vladimir";
    athlete_surname = "Vladimir";
    athlete_name_surname = athlete_name + ' ' + athlete_surname;
    result = 1.1;
    olympiad.AddResult(&*olympiad.FindCompetition(&competition_name), &*olympiad.FindAthlete(&athlete_name_surname), &result);
    athlete_name = "Smith";
    athlete_surname = "Smith";
    athlete_name_surname = athlete_name + ' ' + athlete_surname;
    result = 1.2;
    olympiad.AddResult(&*olympiad.FindCompetition(&competition_name), &*olympiad.FindAthlete(&athlete_name_surname), &result);
    athlete_name = "Kate";
    athlete_surname = "Kate";
    athlete_name_surname = athlete_name + ' ' + athlete_surname;
    result = 1.3;
    olympiad.AddResult(&*olympiad.FindCompetition(&competition_name), &*olympiad.FindAthlete(&athlete_name_surname), &result);
    athlete_name = "Sonia";
    athlete_surname = "Sonia";
    athlete_name_surname = athlete_name + ' ' + athlete_surname;
    result = 1.4;
    olympiad.AddResult(&*olympiad.FindCompetition(&competition_name), &*olympiad.FindAthlete(&athlete_name_surname), &result);
    competition_name = "archery";
    athlete_name = "Vladimir";
    athlete_surname = "Vladimir";
    athlete_name_surname = athlete_name + ' ' + athlete_surname;
    result = 31.5;
    olympiad.AddResult(&*olympiad.FindCompetition(&competition_name), &*olympiad.FindAthlete(&athlete_name_surname), &result);
    athlete_name = "Smith";
    athlete_surname = "Smith";
    athlete_name_surname = athlete_name + ' ' + athlete_surname;
    result = 32.5;
    olympiad.AddResult(&*olympiad.FindCompetition(&competition_name), &*olympiad.FindAthlete(&athlete_name_surname), &result);
    athlete_name = "Kate";
    athlete_surname = "Kate";
    athlete_name_surname = athlete_name + ' ' + athlete_surname;
    result = 33.5;
    olympiad.AddResult(&*olympiad.FindCompetition(&competition_name), &*olympiad.FindAthlete(&athlete_name_surname), &result);
    athlete_name = "Sonia";
    athlete_surname = "Sonia";
    athlete_name_surname = athlete_name + ' ' + athlete_surname;
    result = 34.5;
    olympiad.AddResult(&*olympiad.FindCompetition(&competition_name), &*olympiad.FindAthlete(&athlete_name_surname), &result);
    
    competition_name = "100m";
    olympiad.FinishCompetition(&*olympiad.FindCompetition(&competition_name));
    competition_name = "jump";
    olympiad.FinishCompetition(&*olympiad.FindCompetition(&competition_name));
    competition_name = "archery";
    olympiad.FinishCompetition(&*olympiad.FindCompetition(&competition_name));

    olympiad.SaveToFile();
    cout << "OK" << endl;

    Olympiad olympiad2;
    olympiad2.LoadFromFile();
    olympiad2.PrintCountriesLeaderboard();

    olympiad2.PrintListOfAthletes();
    olympiad2.PrintListOfCompetitions();

    
}