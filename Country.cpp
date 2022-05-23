#include "classes.hpp"

Country::Country(const string *name)
{
    this->name = *name;
    this->gold_medal = 0;
    this->silver_medal = 0;
    this->bronze_medal = 0;
}

Country::Country()
{
    this->gold_medal = 0;
    this->silver_medal = 0;
    this->bronze_medal = 0;
}

void Country::AddAthlete(Athlete *athlete)
{
    if (athlete->GetCountry() == this)
    {
        this->athletes.push_back(athlete);
    }
    else
    {
        cout << "Athlete already exists in another country" << endl;
    }
}

void Country::RemoveAthlete(Athlete *athlete)
{
    if (athlete->GetCountry() != this)
    {
        if (find(this->athletes.begin(), this->athletes.end(), athlete) != this->athletes.end())
        {
            this->athletes.erase(find(this->athletes.begin(), this->athletes.end(), athlete));
        }
        else
        {
            cout << "Athlete doesn't exist in this country" << endl;
        }
    }
    else
    {
        cout << "To remove Athlete use Athlete::UpdateAthlete." << endl;
    }
}

void Country::AddMedal(const int *medal)
{
    switch (*medal)
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
    default:
        cout << "ERROR:Wrong medal type" << endl;
        break;
    }
}

void Country::PrintAthletes(const string filter /*= ""*/)
{
    for (auto it = this->athletes.begin(); it != this->athletes.end(); it++)
    {
        if (filter == (*it)->GetNameSurname().substr(0, filter.size()))
        {
            (*it)->PrintAthlete();
        }
    }
}

void Country::PrintCountry()
{
    cout << "Country: " << this->name << endl;
    cout << "Gold medal: " << this->gold_medal << endl;
    cout << "Silver medal: " << this->silver_medal << endl;
    cout << "Bronze medal: " << this->bronze_medal << endl;
    cout << "Athletes:" << this->athletes.size() << endl;
    for(auto it = this->athletes.begin(); it != this->athletes.end(); it++)
    {
        cout << (*it)->GetNameSurname() << endl;
    }
    cout << endl;
    //this->PrintAthletes();
}

bool Country::operator<(const Country &country)
{
    if (this->gold_medal < country.gold_medal)
    {
        return true;
    }
    else if (this->gold_medal == country.gold_medal && this->silver_medal < country.silver_medal)
    {
        return true;
    }
    else if (this->gold_medal == country.gold_medal && this->silver_medal == country.silver_medal && this->bronze_medal < country.bronze_medal)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Country::operator==(const Country &country)
{
    if (this->gold_medal == country.gold_medal && this->silver_medal == country.silver_medal && this->bronze_medal == country.bronze_medal)
    {
        return true;
    }
    else
    {
        return false;
    }
}

string Country::GetName()
{
    return this->name;
}

void Country::SaveToFile(ofstream &file, int countryID)
{
    file << countryID << "," << this->name << "," << this->gold_medal << "," << this->silver_medal << "," << this->bronze_medal << endl;
}

int Country::LoadFromFile(istringstream &iss)
{
    string value;
    int id;
    getline(iss, value, ',');
    id = stoi(value);
    getline(iss, value, ',');
    this->name = value;
    getline(iss, value, ',');
    this->gold_medal = stoi(value);
    getline(iss, value, ',');
    this->silver_medal = stoi(value);
    getline(iss, value, ',');
    this->bronze_medal = stoi(value);
    return id;
}