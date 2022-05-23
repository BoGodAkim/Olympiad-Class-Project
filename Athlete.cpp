#include "classes.hpp"

Athlete::Athlete()
{
    this->gold_medal = 0;
    this->silver_medal = 0;
    this->bronze_medal = 0;
}

Athlete::Athlete(const string *name, const string *surname, Country *country, const int *age, const int *height, const int *weight, const bool *gender)
{
    this->name = *name;
    this->surname = *surname;
    this->country = country;
    this->age = *age;
    this->height = *height;
    this->weight = *weight;
    this->gender = *gender;
    this->gold_medal = 0;
    this->silver_medal = 0;
    this->bronze_medal = 0;
}

void Athlete::PrintAthlete()
{
    cout << "Name: " << this->name << endl
         << "Surname: " << this->surname << endl
         << "Age: " << this->age << endl
         << "Weight: " << this->weight << endl
         << "Height: " << this->height << endl
         << "Gender: " << (gender ? "Male" : "Female") << endl
         << "Number of gold medals: " << this->gold_medal << endl
         << "Number of silver medals: " << this->silver_medal << endl
         << "Number of bronze medals: " << this->bronze_medal << endl
         << "Country: " << this->country->GetName() << endl <<endl;
}

void Athlete::AddMedal(int medal)
{
    switch (medal)
    {
    case 1:
        this->gold_medal++;
        break;
    case 2:
        this->silver_medal++;
        break;
    case 3:
        this->bronze_medal++;
        break;
    }
    country->AddMedal(&medal);
}

void Athlete::AddCompetition(Competition *competition, const int *type_of_result, const float *result)
{
    this->results.push_back(pair<Competition *, pair<int, float>>(competition, pair<int, float>(*type_of_result, *result)));
}

float Athlete::GetResult()
{
    return this->GetResult(this->competition_for_sort);
}

float Athlete::GetResult(const Competition *competition)
{
    for (auto iter = this->results.begin(); iter != this->results.end(); iter++)
    {
        if (iter->first == competition)
        {
            return iter->second.second;
        }
    }
    return 0;
}

void Athlete::UpdateAthlete(const string *name /*= nullptr*/, const string *surname /*= nullptr*/, Country *country /*= nullptr*/, const int *age /*= nullptr*/, const int *height /*= nullptr*/, const int *weight /*= nullptr*/, const bool *gender /*= nullptr*/)
{
    if (name != nullptr)
    {
        this->name = *name;
    }
    if (surname != nullptr)
    {
        this->surname = *surname;
    }
    if (country != nullptr)
    {
        Country *old_country = this->country;
        this->country = country;
        old_country->RemoveAthlete(this);
        this->country->AddAthlete(this);
    }
    if (age != nullptr)
    {
        this->age = *age;
    }
    if (height != nullptr)
    {
        this->height = *height;
    }
    if (weight != nullptr)
    {
        this->weight = *weight;
    }
    if (gender != nullptr)
    {
        this->gender = *gender;
    }
}

int Athlete::Compare(Athlete *other, Competition *competition)
{
    this->SetCompetitionForSort(competition);
    if (this->GetResult() > other->GetResult())
    {

        return 1;
    }
    else if (this->GetResult() < other->GetResult())
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

void Athlete::SetCompetitionForSort(Competition *competition)
{
    competition_for_sort = competition;
}

bool Athlete::operator<(Athlete *other)
{
    if (this->GetResult() < other->GetResult())
    {
        return true;
    }
    return false;
}

string Athlete::GetNameSurname()
{
    return this->name + ' ' + this->surname;
}

Country *Athlete::GetCountry()
{
    return this->country;
}

void Athlete::SaveToFile(ofstream &file, ofstream &result_file, int athleteID, map<Country *, int> *countryID, map<Competition *, int> *competitionID, int *resultID)
{
    file << athleteID << "," << this->name << "," << this->surname << "," << (*countryID)[this->country] << "," << this->age << "," << this->height << "," << this->weight << "," << this->gender << "," << this->gold_medal << "," << this->silver_medal << "," << this->bronze_medal << endl;
    for (auto iter = results.begin(); iter != results.end(); iter++)
    {
        result_file << *resultID << "," << athleteID << "," << (*competitionID)[iter->first] << "," << iter->second.second << endl;
        (*resultID)++;
    }
}

int Athlete::LoadFromFile(istringstream &iss, map<int, Country *> *countryID)
{
    int id;
    string value;
    getline(iss, value, ',');
    id = stoi(value);
    getline(iss, value, ',');
    this->name = value;
    getline(iss, value, ',');
    this->surname = value;
    getline(iss, value, ',');
    this->country = (*countryID)[stoi(value)];
    getline(iss, value, ',');
    this->age = stoi(value);
    getline(iss, value, ',');
    this->height = stoi(value);
    getline(iss, value, ',');
    this->weight = stoi(value);
    getline(iss, value, ',');
    this->gender = ((value[0] == '0') ? false : true);
    getline(iss, value, ',');
    this->gold_medal = stoi(value);
    getline(iss, value, ',');
    this->silver_medal = stoi(value);
    getline(iss, value, ',');
    this->bronze_medal = stoi(value);
    return id;
}