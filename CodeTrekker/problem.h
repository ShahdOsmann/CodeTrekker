#pragma once
#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
#include <windows.h> 
using namespace std;
class problem
{
private:
    string name, contest, statement, setter, tutorial, constraints, problemID;
    vector<string>topics, examples;
    int difficulty, users_solved;
    static  set<pair<int, pair<string, string>>, greater<>> st_fromEasyToHard;
    static  set<pair<int, pair<string, string>>> st_fromHardToEasy;
public:
    problem();
    problem(string name, string contest, string statement, string setter, string tutorial, string constraints,
        vector<string>topics, vector<string>examples, int difficulty, int users_solved, string problemID);
    void set_name(string name);
    void set_contest(string contest);
    void set_statement(string statement);
    void set_settter(string setter);
    void set_tutorial(string tutorial);
    void set_constraints(string constraints);
    void set_topics(vector<string> topics);
    void set_examples(vector<string> examples);
    void set_difficulty(int difficulty);
    void increment_user_solved();
    int get_difficulty();
    string get_name();
    string get_problemID();
    vector<string> get_topics();
    void set_problemID(string problemID);
    static void showFromEasyToHard();
    static void showFromHardToEasy();
    void show_problem();
    void show_tutorial();
};

