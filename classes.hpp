#ifndef CLASSES_HPP
#define CLASSES_HPP

#include <bits/stdc++.h>
using std::istringstream;
using std::list;
using std::map;
using std::ofstream;
using std::pair;
using std::set;
using std::string;
using std::vector;

class Olympiad;
class Country;
class Competition;
class Athlete;

class Olympiad
{
private:
    string name;
    string description;
    list<Country> countries;
    list<Competition> competitions;
    list<Athlete> athletes;

public:
    void AddCountry(const string *name);
    void AddCompetition(const string *name, const string *description, const int *type_of_result, const bool first_place_is_smaller);
    void AddAthlete(const string *name, const string *surname, Country *country, const int *age, const int *height, const int *weight, const bool *gender);
    void AddResult(Competition *competition, Athlete *athlete, const float *result);
    void FinishCompetition(Competition *competition);
    void PrintCountriesLeaderboard(int number = 10);
    void PrintCountries(const string filter = "");
    void PrintListOfCompetitions(const string filter = "");
    void PrintListOfAthletes(const string filter = "");
    list<Country>::iterator FindCountry(const string *name);
    list<Competition>::iterator FindCompetition(const string *name);
    list<Athlete>::iterator FindAthlete(const string *name_surname);
    Olympiad();
    Olympiad(const string *name, const string *description);
    void SaveToFile(const string fileName = "data/olympiad.txt");
    void LoadFromFile(const string fileName = "data/olympiad.txt");
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
    Country(const string *name);
    void AddAthlete(Athlete *athlete);
    void RemoveAthlete(Athlete *athlete);
    void AddMedal(const int *medal);
    void PrintAthletes(const string filter = "");
    void PrintCountry();
    bool operator<(const Country &other);
    bool operator==(const Country &other);
    void SaveToFile(ofstream &file, int countryID);
    int LoadFromFile(istringstream &iss);
    string GetName();
};

class Competition
{
private:
    string name;
    string description;
    list<Athlete *> athletes;
    int type_of_result = 0;
    bool first_place_is_smaller;
    bool finished;

public:
    Competition();
    Competition(const string *name, const string *description, const int *type_of_result, const bool first_place_is_smaller);
    void AddAthlete(Athlete *athlete, const float *result);
    void AddAthleteFromFile(Athlete *athlete, const float *result);
    void PrintCompetition();
    void PrintAthletesLeaderboard(int number = 10);
    bool CheckResult(const float *result);
    bool IsFinished();
    void FinishCompetition();
    void SaveToFile(ofstream &file, int competitionID);
    int LoadFromFile(istringstream &iss);
    string GetName();
};

class Athlete
{
private:
    inline static Competition *competition_for_sort;
    string name;
    string surname;
    Country *country;
    int age;
    int height;
    int weight;
    int gold_medal;
    int silver_medal;
    int bronze_medal;
    list<pair<Competition *, pair<int, float>>> results;
    bool gender;

public:
    Athlete();
    Athlete(const string *name, const string *surname, Country *country, const int *age, const int *height, const int *weight, const bool *gender);
    void PrintAthlete();
    void AddMedal(int medal);
    void AddCompetition(Competition *competition, const int *type_of_result, const float *result);
    float GetResult(const Competition *competition);
    float GetResult();
    void UpdateAthlete(const string *name = nullptr, const string *surname = nullptr, Country *country = nullptr, const int *age = nullptr, const int *height = nullptr, const int *weight = nullptr, const bool *gender = nullptr);
    int Compare(Athlete *other, Competition *competition);
    void SetCompetitionForSort(Competition *competition);
    bool operator<(Athlete *other);
    void SaveToFile(ofstream &file, ofstream &result_file, int athleteID, map<Country *, int> *countryID, map<Competition *, int> *competitionID, int *resultID);
    int LoadFromFile(istringstream &iss, map<int, Country *> *countryID);
    string GetNameSurname();
    Country *GetCountry();
};

#endif // CLASSES_HPP