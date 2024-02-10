#include "problem.h"
#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map> 
#include <windows.h>  
#define ll long long
using namespace std; 
 set<pair<int, pair<string, string>>> problem::st_fromHardToEasy;
 set<pair<int, pair<string, string>>, greater<>> problem::st_fromEasyToHard;
problem::problem()
{
    name = contest = statement = setter = tutorial = constraints , problemID = "";
    difficulty = 0, users_solved = 0;
}

problem::problem(string name, string contest, string statement, string setter, string tutorial,
    string constraints, vector<string> topics, vector<string> examples, int difficulty, int users_solved, string problemID)
{
    this->name = name, this->contest = contest, this->statement = statement, this->setter = setter, this->tutorial = tutorial, this->problemID = problemID;
    this->constraints = constraints, this->topics = topics, this->examples = examples, this->difficulty = difficulty, this->users_solved = users_solved;
    st_fromEasyToHard.insert({ users_solved ,{name, problemID} }); st_fromHardToEasy.insert({ users_solved ,{name,problemID } });
}

void problem::set_name(string name)
{
    if (st_fromHardToEasy.count({ this->users_solved , {this->name, this->problemID} }))
        st_fromHardToEasy.erase({ this->users_solved , {this->name, this->problemID} }),
        st_fromEasyToHard.erase({ this->users_solved , {this->name, this->problemID} }),
        st_fromHardToEasy.insert({ users_solved ,{name, problemID} }),
        st_fromEasyToHard.insert({ users_solved ,{name, problemID} });
    this->name = name;
}

void problem::set_contest(string contest)
{
    this->contest = contest;
}

void problem::set_statement(string statement)
{
    this->statement = statement;
}

void problem::set_settter(string setter)
{
    this->setter = setter;
}

void problem::set_tutorial(string tutorial)
{
    this->tutorial = tutorial;
}

void problem::set_constraints(string constraints)
{
    this->constraints = constraints;
}

void problem::set_topics(vector<string> topics)
{
    this->topics = topics;
}

void problem::set_examples(vector<string> examples)
{
    this->examples = examples;
}

void problem::set_difficulty(int difficulty)
{
    this->difficulty = difficulty;
}

void problem::increment_user_solved()
{
    users_solved++;
    if (st_fromHardToEasy.count({ this->users_solved - 1, {this->name, this->problemID} }))
        st_fromHardToEasy.erase({ this->users_solved - 1, {this->name, this->problemID} }),
        st_fromEasyToHard.erase({ this->users_solved - 1, {this->name, this->problemID} }),
        st_fromHardToEasy.insert({ users_solved ,{name, problemID} }),
        st_fromEasyToHard.insert({ users_solved ,{name, problemID} });
}

int problem::get_difficulty()
{
    return difficulty;
}

string problem::get_name()
{
    return name;
}

string problem::get_problemID()
{
    return problemID;
}

vector<string> problem::get_topics()
{
    return topics;
}

void problem::set_problemID(string problemID)
{
    if (st_fromHardToEasy.count({ this->users_solved , {this->name, this->problemID} }))
        st_fromHardToEasy.erase({ this->users_solved , {this->name, this->problemID} }),
        st_fromEasyToHard.erase({ this->users_solved , {this->name, this->problemID} }),
        st_fromHardToEasy.insert({ users_solved ,{name, problemID} }),
        st_fromEasyToHard.insert({ users_solved ,{name, problemID} });
    this->problemID = problemID;
}

void problem::showFromEasyToHard()
{
    cout << "The  problem list from easy to hard: \n\n";
    for (auto s : st_fromEasyToHard)
            cout << s.second.second << " " << s.second.first << " " << s.first << "\n";
    cout << "\n\n---------------------------------------------------------\n\n";
}

void problem::showFromHardToEasy()
{
    cout << "The  problem list from hard to easy: \n\n";
    for (auto s : st_fromHardToEasy)
        cout << s.second.second << " " << s.second.first << " " <<  s.first << "\n";
    cout << "\n\n---------------------------------------------------------\n\n";

}

void problem::show_problem()
{

    cout << "\n" <<  problemID << " " << name << "\t\t\t" << contest << "\n\n";
    for (int i = 0; i < constraints.size(); i++)
        if (constraints[i] == ';')cout << "\n"; else cout << constraints[i];
    cout << "\n\n"; for (int i = 0; i < statement.size(); i++)
        if (statement[i] == ';')cout << "\n"; else cout << statement[i];
    cout << "\n\n"; for (auto example : examples)
        for (int i = 0; i < example.size(); i++)
            if (example[i] == ';')cout << "\n"; else cout << example[i];
    cout << "\n\n"; for (auto topic : topics)cout << topic << " "; 
    cout << difficulty << "\n\n---------------------------------------------------------\n\n"; 

}

void problem::show_tutorial()
{
    cout << name << " " << "tutorial\n";
    cout << "problem setter: " << setter << "\n";
    for (int i = 0; i < tutorial.size(); i++)
        if (tutorial[i] == ';')cout << "\n"; else cout << tutorial[i];
}

