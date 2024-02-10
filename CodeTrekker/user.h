#pragma once 
#ifndef USER_H
#define USER_H
#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
#include <windows.h>  
#include "problem.h"
#include "problem_setter.h"
using namespace std;
class user
{
private:
	string handle, email, name, password, title, country, university;
	int contest_rating, max_rating, number_of_friends, contribution, solved_problems, max_streak;
	bool visible;
	set<string>friends;
	struct submission{
		problem p;
		string verdict;
		string lang;
		string when;
		int time;
		int memory;
		int ID;
		void show_submission(string handle)
		{
			cout << ID << " " << when << " " << handle << " " << p.get_problemID() << "-" <<
				p.get_name() << " " << lang << " " << verdict << " " <<
				time << "ms " << memory << "KB ";
		}
	};
	stack<submission>problems;
	vector<pair<string, vector<user>>>teams;
	vector< submission>favourites;
	static set<pair<int, string>, greater<>>ranking_users;
	static int cnt;
public:
	user();
	user(string handle, string email, string password);
	user(string handle, string email, string name, string password, string country, string university,
		int contest_rating, int max_rating, int number_of_friends, int contribution, bool visible, 
		int solved_problems, int max_streak);
	void set_handle(string handle);
	void set_name(string name);
	void set_email(string email);
	void set_password(string password);
	void update_country();
	void update_university(string university);
	void update_contest_rating(int contest_rating);
	void increment_number_of_friends();
	void increment_contribution();
	void set_visible(bool visible);
	void reset_password();
	string get_password();
	string get_handle();
	void color(string title);
	void Color(int color);
	void show_user();
	void add_friend(string new_friend);
	void delete_friend(string the_friend);
	bool is_a_friend(string the_friend);
	void show_friends();
	void submit(problem p);
	void show_submissions(); 
	void show_teams();
	void add_team(pair<string, vector<user>> team);
	void add_favourite(submission s);
	void show_favourites();
	static void show_users_by_ranks();
	friend class problem_setter;

};
class problem_setter :public user
{
private:
	vector<problem>createdProblems;
public:
	void add_problem(problem p);
	void show_problemsetting();
};


#endif