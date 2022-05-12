#ifndef CLASSES_HPP
#define CLASSES_HPP

#include <bits/stdc++.h>
using std::set;
using std::string;
using std::vector;

class Olympiad
{
private:
    string name;
    string description;
    vector<Country> countries;
    vector<Competition> competitions;
    void AddCountry();
    void AddCompetition();
    void ManageCompetition();
    void PrintCountriesLeaderboard();
    void PrintListOfCompetitions();
    vector<Country>::iterator FindCountry(const string name);
    vector<Competition>::iterator FindCompetition(const string name);

public:
    Olympiad();
    Olympiad(const string name, const string description);
    void Interface();
};

class Country
{
private:
    string name;
    vector<Athlete *> athletes;
    int gold_medal;
    int silver_medal;
    int bronze_medal;

public:
    Country();
    Country(const string name);
    void AddAthlete(const Athlete *athlete);
    void AddMedal(const int medal);
    void PrintAthletes();
    void PrintCountry();
    bool operator<(const Country &other);
};

class Competition
{
private:
    string name;
    string description;
    set<Athlete> athletes;
    int type_of_result = 0;
    bool first_place_is_smaller;
    bool finished;
    vector<Country> *countries;

public:
    Competition(const string name, const string description, vector<Country> *countries);
    void ReadCompetitionData();
    vector<Country>::iterator FindCountry(const string name);
    void ReadAthleteData();
    void PrintCompetition();
    void PrintAthletes();
    bool CheckResult(const float result);
    bool IsFinished();
    void AddCountry();
    void FinishCompetition();
    void Interface();
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
    float result;
    int type_of_result;
    bool gender;
    bool disqualification;

public:
    Athlete(const string name, const string surname, const Country *country, const int age, const int weight, const float result, const int type_of_result, const bool gender, const bool disqualification);
    void PrintAthlete();
    float GetResult();
    bool operator<(const Athlete &other);
};

#endif // CLASSES_HPP