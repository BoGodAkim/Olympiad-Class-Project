#ifndef CLASSES_HPP
#define CLASSES_HPP

#include <bits/stdc++.h>
using std::set;
using std::string;
using std::vector;
using std::pair;
using std::list;
using std::ofstream;
using std::istringstream;

class Olympiad
{
private:
    string name;
    string description;
    list <Country> countries;
    list <Competition> competitions;
    list <Athlete> athletes;
    void AddCountry();
    void AddCompetition();
    void AddAthlete();
    void ManageAthlete();
    void ManageCompetition();
    void PrintCountriesLeaderboard(const int number = 10);
    void PrintCountries(const string filter = "");
    void PrintListOfCompetitions(const string filter = "");
    void PrintListOfAthletes(const string filter = "");
    vector<Country>::iterator FindCountry(const string *name);
    vector<Competition>::iterator FindCompetition(const string *name);
    vector<Athlete>::iterator FindAthlete(const string *name_surname);

public:
    Olympiad();
    Olympiad(const string *name, const string *description);
    void Interface();
    void SaveToFile(const string fileName = "olympiad.txt");
    void LoadFromFile(const string fileName = "olympiad.txt");
};

class Country
{
private:
    string name;
    vector<Athlete *> athletes;
    int gold_medal;
    int silver_medal;
    int bronze_medal;
    list<Athlete> *all_athletes;

public:
    Country();
    Country(const string *name);
    void AddAthlete(const Athlete *athlete);
    void AddMedal(const int *medal);
    void ManageAthletes();
    void PrintAthletes(const string filter = "");
    void PrintCountry();
    vector<Athlete>::iterator FindAthlete(const string *name_surname);
    bool operator<(const Country &other);
    void SaveToFile(ofstream &file);
    void LoadFromFile(istringstream &line);
};

class Competition
{
private:
    string name;
    string description;
    list <Athlete *> athletes;
    int type_of_result = 0;
    bool first_place_is_smaller;
    bool finished;
    vector<Country> *countries;
    list <Athlete> *all_athletes;

public:
    Competition(const string *name, const string *description, vector<Country> *countries);
    void ReadCompetitionData();
    vector<Country>::iterator FindCountry(const string *name);
    vector<Athlete>::iterator FindAthlete(const string *name_surname);
    void AddAthlete();
    void ManageAthletes();
    void PrintCompetition();
    void PrintAthletes(const string filter = "");
    void PrintCountries(const string filter = "");
    bool CheckResult(const float *result);
    bool IsFinished();
    void AddCountry();
    void FinishCompetition();
    void Interface();
    void SaveToFile(ofstream &file);
    void LoadFromFile(istringstream &line);
};

class Athlete
{
private:
    string name;
    string surname;
    Country *country;
    int age;
    int height;
    int weight;
    pair <Competition*,pair <int,float>> results;
    bool gender;
    bool disqualification;

public:
    Athlete(const string name, const string surname, const Country *country, const int age, const int weight, const float result, const int type_of_result, const bool gender, const bool disqualification);
    void PrintAthlete();
    float GetResult(const Competition *competition);
    void UpdateAthlete();
    int Compair(const Athlete &other, const Competition* competition);
    void SaveToFile(ofstream &file);
    void LoadFromFile(istringstream &line);
};

#endif // CLASSES_HPP