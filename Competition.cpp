#include "classes.hpp"

bool compare_athletes(Athlete *a1, Athlete *a2)
{
    return !a1->operator<(a2);
}

Competition::Competition()
{
    this->finished = false;
}

Competition::Competition(const string *name, const string *description, const int *type_of_result, const bool first_place_is_smaller)
{
    this->finished = false;
    this->name = *name;
    this->description = *description;
    if (*type_of_result > 0 && *type_of_result < 4)
    {
        this->type_of_result = *type_of_result;
    }
    else
    {
        cout << "ERROR:Wrong type of result. Function automaticaly save type_of_result as 1" << endl;
        this->type_of_result = 1;
    }

    this->first_place_is_smaller = first_place_is_smaller;
    this->finished = false;
}

void Competition::AddAthlete(Athlete *athlete, const float *result)
{
    if (finished == true)
    {
        cout << "ERROR:Competition is finished" << endl;
        return;
    }
    if (find(this->athletes.begin(), this->athletes.end(), athlete) != this->athletes.end())
    {
        cout << "ERROR:Athlete already exists in competition" << endl;
        return;
    }
    if (CheckResult(result))
    {
        this->athletes.push_back(athlete);
        athlete->AddCompetition(this, &this->type_of_result, result);
    }
    else
    {
        cout << "ERROR:Wrong result" << endl;
    }
}

void Competition::AddAthleteFromFile(Athlete *athlete, const float *result)
{
    if (find(this->athletes.begin(), this->athletes.end(), athlete) != this->athletes.end())
    {
        cout << "ERROR:Athlete already exists in competition" << endl;
        return;
    }
    if (CheckResult(result))
    {
        this->athletes.push_back(athlete);
        athlete->AddCompetition(this, &this->type_of_result, result);
    }
    else
    {
        cout << "ERROR:Wrong result" << endl;
    }
}

void Competition::PrintCompetition()
{
    cout << "Competition: " << this->name << endl;
    cout << "Description: " << this->description << endl;
    cout << "Type of result: ";
    switch (this->type_of_result)
    {
    case 1:
        cout << "time" << endl;
        break;
    case 2:
        cout << "distance" << endl;
        break;
    case 3:
        cout << "points" << endl;
        break;
    }
    cout << "First place is smaller: " << this->first_place_is_smaller << endl;
    cout << "Athletes:" << athletes.size() << endl;
    this->PrintAthletesLeaderboard();
    cout << "Finished:" << this->finished << endl
         << endl;
}

void Competition::PrintAthletesLeaderboard(int number /*= 10*/)
{
    this->athletes.back()->SetCompetitionForSort(this);
    this->athletes.sort(compare_athletes);
    if (this->first_place_is_smaller)
    {
        athletes.reverse();
    }
    if (number > this->athletes.size())
    {
        number = this->athletes.size();
    }
    auto it = this->athletes.begin();
    for (int i = 0; i < number; i++)
    {
        cout << i + 1 << ". " << (*it)->GetCountry()->GetName() << " " << (*it)->GetNameSurname() << ' ' << (*it)->GetResult() << endl;
        // (*it)->PrintAthlete();
        it++;
    }
}

bool Competition::CheckResult(const float *result)
{
    this->athletes.front()->SetCompetitionForSort(this);
    for (auto it = this->athletes.begin(); it != this->athletes.end(); it++)
    {
        if ((*it)->GetResult() == *result)
        {
            return false;
        }
    }
    return true;

}

bool Competition::IsFinished()
{
    return this->finished;
}

void Competition::FinishCompetition()
{
    this->finished = true;
    athletes.back()->SetCompetitionForSort(this);
    athletes.sort(compare_athletes);
    if (this->first_place_is_smaller)
    {
        athletes.reverse();
    }
    auto it = athletes.begin();
    (*it)->AddMedal(1);
    it++;
    (*it)->AddMedal(2);
    it++;
    (*it)->AddMedal(3);
}

string Competition::GetName()
{
    return this->name;
}

void Competition::SaveToFile(ofstream &file, int competitionID)
{
    file << competitionID << "," << this->name << "," << this->description << "," << this->type_of_result << "," << this->first_place_is_smaller << "," << this->finished << endl;
}

int Competition::LoadFromFile(istringstream &iss)
{
    string value;
    int id;
    getline(iss, value, ',');
    id = stoi(value);
    getline(iss, value, ',');
    this->name = value;
    getline(iss, value, ',');
    this->description = value;
    getline(iss, value, ',');
    this->type_of_result = stoi(value);
    getline(iss, value, ',');
    this->first_place_is_smaller = stoi(value);
    getline(iss, value, ',');
    this->finished = stoi(value);
    return id;
}