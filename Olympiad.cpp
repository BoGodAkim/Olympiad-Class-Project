#include "classes.hpp"

void Olympiad::AddCountry(const string *name)
{
    if (FindCountry(name) == countries.end())
    {
        countries.push_back(Country(name));
    }
    else
    {
        cout << "Country already exists" << endl;
    }
}

void Olympiad::AddCompetition(const string *name, const string *description, const int *type_of_result, const bool first_place_is_smaller)
{
    if (*type_of_result < 0 || *type_of_result > 3)
    {
        cout << "Wrong type of result" << endl;
        return;
    }
    if (FindCompetition(name) == competitions.end())
    {
        competitions.push_back(Competition(name, description, type_of_result, first_place_is_smaller));
    }
    else
    {
        cout << "Competition already exists" << endl;
    }
}

void Olympiad::AddAthlete(const string *name, const string *surname, Country *country, const int *age, const int *height, const int *weight, const bool *gender)
{
    auto country_name = country->GetName();
    auto athlete_name = string(*name + *surname);
    if (FindCountry(&country_name) == countries.end())
    {
        cout << "Wrong Country.";
    }
    if (*age < 1 || *height < 1 || *weight < 1 || country == nullptr)
    {
        cout << "Wrong input data.";
    }
    if (FindAthlete(&athlete_name) == athletes.end())
    {
        Athlete athlete(name, surname, country, age, height, weight, gender);
        this->athletes.push_back(athlete);
    }
    else
    {
        cout << "Athlete already exists";
    }
}

void Olympiad::AddResult(Competition *competition, Athlete *athlete, const float *result)
{
    competition->AddAthlete(athlete, result);
}

void Olympiad::FinishCompetition(Competition *competition)
{
    competition->FinishCompetition();
}

    // void Olympiad::PrintCountriesLeaderboard(int number = 10)
    // {
    //     Country *prev_country = nullptr;
    //     vector<Country *> country;
    //     if (number > this->countries.size())
    //     {
    //         number = this->countries.size();
    //     }
    //     for (int i = 0; i < number; i++)
    //     {
    //         country.push_back(nullptr);
    //         auto it = countries.begin();
    //         for (auto it : this->countries)
    //         {
    //             if ((country[0] == nullptr && (prev_country == nullptr || it < *prev_country)) || (*country[0] < it && (prev_country == nullptr || it < *prev_country)))
    //             {
    //                 country.clear();
    //                 country.push_back(&it);
    //             }
    //             else if (country[0] != nullptr && it == *country[0])
    //             {
    //                 country.push_back(&it);
    //             }
    //         }
    //         prev_country = country[0];
    //         for (auto iter : country)
    //         {
    //             iter->PrintCountry();
    //         }
    //     }
    // }

    void Olympiad::PrintCountriesLeaderboard(int number /*= 10*/)
{
    if (number > this->countries.size())
    {
        number = this->countries.size();
    }
    this->countries.sort();
    this->countries.reverse();
    auto it = this->countries.begin();
    for (int i = 0; i < number; i++)
    {
        cout << i + 1 << " place: " << endl;
        it->PrintCountry();
        it++;
    }
}

void Olympiad::PrintCountries(const string filter /*= ""*/)
{
    for (auto it = this->countries.begin(); it != this->countries.end(); it++)
    {
        if (filter == it->GetName().substr(0, filter.size()))
        {
            it->PrintCountry();
        }
    }
}

void Olympiad::PrintListOfCompetitions(const string filter /*= ""*/)
{
    for (auto it = this->competitions.begin(); it != this->competitions.end(); it++)
    {
        if (filter == it->GetName().substr(0, filter.size()))
        {
            it->PrintCompetition();
        }
    }
}

void Olympiad::PrintListOfAthletes(const string filter /*= ""*/)
{
    for (auto it = this->athletes.begin(); it != this->athletes.end(); it++)
    {
        if (filter == it->GetNameSurname().substr(0, filter.size()))
        {
            it->PrintAthlete();
        }
    }
}

list<Country>::iterator Olympiad::FindCountry(const string *name)
{
    for (auto it = this->countries.begin(); it != this->countries.end(); it++)
    {
        if (it->GetName() == *name)
        {
            return it;
        }
    }
    return this->countries.end();
}

list<Competition>::iterator Olympiad::FindCompetition(const string *name)
{
    for (auto it = this->competitions.begin(); it != this->competitions.end(); it++)
    {
        if (it->GetName() == *name)
        {
            return it;
        }
    }
    return this->competitions.end();
}

list<Athlete>::iterator Olympiad::FindAthlete(const string *name_surname)
{
    for (auto it = this->athletes.begin(); it != this->athletes.end(); it++)
    {
        if (it->GetNameSurname() == *name_surname)
        {
            return it;
        }
    }
    return this->athletes.end();
}

void Olympiad::SaveToFile(const string fold_name /*= "data/"*/)
{
    map<Country *, int> countryID;
    map<Competition *, int> competitionID;
    map<Athlete *, int> athleteID;
    auto it = this->countries.size();
    int id = 0;
    for (auto it = this->countries.begin(); it != this->countries.end(); it++)
    {
        countryID[&(*it)] = id;
        id++;
    }
    id = 0;
    for (auto it = this->competitions.begin(); it != this->competitions.end(); it++)
    {
        competitionID[&(*it)] = id;
        id++;
    }
    id = 0;
    for (auto it = this->athletes.begin(); it != this->athletes.end(); it++)
    {
        athleteID[&(*it)] = id;
        id++;
    }
    ofstream file(fold_name + "Olympiad.txt");
    file << name << endl
         << description << endl;
    file.close();

    ofstream country_file(fold_name + "Country.csv");
    country_file << "ID,Name,GoldMedals,SilverMedals,BronzeMedals" << endl;
    for (auto it = this->countries.begin(); it != this->countries.end(); it++)
    {
        it->SaveToFile(country_file, countryID[&(*it)]);
    }
    country_file.close();

    ofstream competition_file(fold_name + "Competition.csv");
    competition_file << "ID,Name,Description,TypeOfResult,FirstPlaceIsSmaller,Finished" << endl;
    for (auto it = this->competitions.begin(); it != this->competitions.end(); it++)
    {
        it->SaveToFile(competition_file, competitionID[&(*it)]);
    }
    competition_file.close();

    ofstream athlete_file(fold_name + "Athlete.csv");
    athlete_file << "ID,Name,Surname,CountryID,Age,Height,Weight,Gender,GoldMedals,SilverMedals,BronzeMedals" << endl;
    ofstream result_file(fold_name + "Result.csv");
    result_file << "ID, AthleteID,CompetitionID,Result" << endl;
    int resultID = 0;
    for (auto it = this->athletes.begin(); it != this->athletes.end(); it++)
    {
        it->SaveToFile(athlete_file, result_file, athleteID[&(*it)], &countryID, &competitionID, &resultID);
    }
    athlete_file.close();
}

void Olympiad::LoadFromFile(const string fold_name /*= "data/"*/)
{
    map<int, Country *> countryID;
    map<int, Competition *> competitionID;
    map<int, Athlete *> athleteID;
    int id;

    ifstream file(fold_name+"Olympiad.txt");
    string line;
    getline(file, line);
    this->name = line;
    getline(file, line);
    this->description = line;
    file.close();

    ifstream country_file(fold_name + "Country.csv");
    string line_country;
    getline(country_file, line_country);
    while (getline(country_file, line_country))
    {
        Country country;
        istringstream iss(line_country);
        id = country.LoadFromFile(iss);
        this->countries.push_back(country);
        countryID[id] = &this->countries.back();
    }
    country_file.close();

    ifstream athlete_file(fold_name + "Athlete.csv");
    string line_athlete;
    getline(athlete_file, line_athlete);
    while (getline(athlete_file, line_athlete))
    {
        Athlete athlete;
        istringstream iss(line_athlete);
        id = athlete.LoadFromFile(iss,&countryID);
        this->athletes.push_back(athlete);
        athleteID[id] = &this->athletes.back();
    }

    ifstream competition_file(fold_name + "Competition.csv");
    string line_competition;
    getline(competition_file, line_competition);
    while (getline(competition_file, line_competition))
    {
        Competition competition;
        istringstream iss(line_competition);
        id = competition.LoadFromFile(iss);
        this->competitions.push_back(competition);
        competitionID[id] = &this->competitions.back();
    }
    competition_file.close();

    ifstream result_file(fold_name + "Result.csv");
    string line_result;
    getline(result_file, line_result);
    while (getline(result_file, line_result))
    {
        istringstream iss(line_result);
        string value;
        int athlete_id;
        int competition_id;
        float result;
        getline(iss, value, ',');
        getline(iss, value, ',');
        athlete_id = stoi(value);
        getline(iss, value, ',');
        competition_id = stoi(value);
        getline(iss, value, ',');
        result = stof(value);
        competitionID[competition_id]->AddAthleteFromFile(athleteID[athlete_id], &result);
    }
}

Olympiad::Olympiad()
{
}

Olympiad::Olympiad(const string *name, const string *description)
{
    this->name = *name;
    this->description = *description;
}