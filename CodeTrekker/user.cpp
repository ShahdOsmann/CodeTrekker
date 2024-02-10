#include "user.h"
#include"valid.h"
#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map> 
#include <windows.h>  
#define ll long long
using namespace std;
int user::cnt = 0; 
set<pair<int, string>, greater<>>user::ranking_users;
user::user()
{
	handle = "", email = "", name = "", password = "", title = "Unrated", country = "", university = "";
	contest_rating = 0, number_of_friends = 0, contribution = 0, max_rating = 0, solved_problems = 0, max_streak = 0;
	 visible = 0;
}
user::user(string handle, string email, string password)
{
	name = "", title = "Unrated", country = "", university = "", solved_problems = 0, max_streak = 0;
	contest_rating = 0, number_of_friends = 0, contribution = 0, max_rating = 0;
	cnt++; visible = 0;
	this->handle = handle;
	this->email = email;
	this->password = password;
	ranking_users.insert({ contest_rating, handle });
}
user::user(string handle, string email, string name, string password, string country, string university,
	int contest_rating, int max_rating, int number_of_friends, int contribution, bool visible, int solved_problems, int max_streak)
{
	this->handle = handle, this->name = name, this->password = password, this->email = email, this->solved_problems = solved_problems,
		this->country = country, this->university = university, this->max_rating = max_rating, this->max_streak = max_streak;
	this->number_of_friends = number_of_friends, this->contribution = contribution, this->visible = visible;
	user::update_contest_rating(contest_rating);
	ranking_users.insert({ contest_rating, handle });
	cnt++;
}
void user::set_handle(string handle)
{
	ranking_users.erase({ contest_rating, this->handle });
	this->handle = handle;
	ranking_users.insert({ contest_rating, handle });

}

void user::set_name(string name)
{
	this->name = name;
}

void user::set_password(string password)
{
	this->password = password;
}

void user::set_email(string email)
{
	this->email = email;
}
void user::update_contest_rating(int contest_rating)
{
	ranking_users.erase({ this->contest_rating, handle });
	this->max_rating = max(max_rating, contest_rating);
	this->contest_rating = contest_rating;
	if (contest_rating < 1200 && contest_rating>0)title = "Newbie";
	else if (contest_rating >= 1200 && contest_rating < 1400)title = "Pupil";
	else if (contest_rating >= 1400 && contest_rating < 1600)title = "specialist";
	else if (contest_rating >= 1600 && contest_rating < 1900)title = "Expert";
	else if (contest_rating >= 1900 && contest_rating < 2100)title = "Candidate Master";
	else if (contest_rating >= 2100 && contest_rating < 2300)title = "Master";
	else if (contest_rating >= 2300 && contest_rating < 2400) title = "International Master";
	else if (contest_rating >= 2400 && contest_rating < 2600)title = "Grandmaster";
	else if (contest_rating >= 2600 && contest_rating < 3000)title = "International Grandmaster";
	else title = "Legendary Grandmaster";
	ranking_users.insert({ contest_rating, handle });
}

void user::update_country()
{
	string country;  cout << "Enter country: "; bool f = 1;
	while (1)
	{
		cin >> country; 
		if (validate_Country(country))break;
		cout << "Country isnot correct\n";
		cout << "Do you want to return to home page? (1:yes, 0:no): ";
	    cin >> f; if (!f)break;
		else cout << "ok, try again: ";
	}
	if(f)this->country = country;
}
void user::update_university(string university) {
	this->university = university;
}

void user::increment_number_of_friends()
{
	number_of_friends++;
}

void user::increment_contribution()
{
	contribution++;
}
void user::set_visible(bool visible)
{
	this->visible = visible;
}

void user::reset_password()
{
	cout << "Enter the old password: ";
	string pas; cin >> pas; 
	if (pas == password)
	{
		cout << "Enter the new one: ";
		cin >> pas;
		password = pas;
		cout << "password updated\n";
	}
	else cout << "incorrect\n";
}

string user::get_password()
{
	return password;
}
string user::get_handle()
{
	return handle;
}
void user::Color(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void user::color(string title)
{
	if (title == "Unrated")Color(7);
	else if (title == "Newbie")Color(8);
	else if (title == "Pupil")Color(10);
	else if (title == "specialist")Color(11);
	else if (title == "Expert")Color(9);
	else if (title == "Candidate Master")Color(5);
	else if (title == "Master")Color(14);
	else if (title == "International Master")Color(6);
	else Color(12);

}
void user::show_user()
{
	color(title);
	cout << title << "\n";
	cout << handle << "\n";
	Color(7);
	if (name != "")cout << "Name: " << name << "\n";
	if (university != "")cout << "From: " << university;
	if (country != "")cout << " , " << country << "\n";
	cout << "Contest rating: " << contest_rating << " , max rating ( " << max_rating << " )\n";
	cout << "Contribution: " << contribution << "\n";
	cout << "Friend of: " << number_of_friends << " users\n";
	if (visible)cout << "Email: " << email << "\n";
	cout << "Number of solved problems: " << solved_problems << "\n";
	cout << "Maximum Streak: " << max_streak << "\n";
	cout << "\n------------------------------------------------------\n\n";

}

void user::add_friend(string new_friend)
{
	friends.insert(new_friend);
}

void user::delete_friend(string the_friend)
{
	friends.erase(the_friend);
}

bool user::is_a_friend(string the_friend)
{
	return friends.count(the_friend);
}

void user::show_friends()
{
	for (auto s : friends)
		cout << s << "\n";
}

void user::submit(problem p)
{
	submission s;  	s.p = p;
	cout << "Enter the verdict : ";  cin >> s.verdict;
	cout << "Enter the lang: "; cin >> s.lang;
	cout << "Enter when you solved: "; cin >> s.when;
	cout << "Enter time of your program took: "; cin >> s.time;
	cout << "Enter memory your program took: "; cin >> s.memory;
	s.ID = cnt; cnt++;
	problems.push(s);
	cout << "Done\n";
	cout << "Do you want to add to favourites?(1:yes, 0/:no): ";
	bool c; cin >> c;
	if (c)add_favourite(s);
	cout << "Done\n";
}
void user::show_submissions()
{
	cout << handle << "Submissions: \n";
	stack< submission>st = problems;
	while (!st.empty())
	{
		st.top().show_submission(handle); 
		cout << "\n---------------------------------------------------------------------\n";
		st.pop();
	}
} 
void user::show_teams()
{
	cout << "Teams\n";
	for (auto team : teams)
	{
		cout << team.first << "\n";
		for (auto t : team.second)cout << t.get_handle() << ", ";
	}
	cout << "\n---------------------------------------------------------------------\n";
}

void user::add_team(pair<string, vector<user>> team)
{
	teams.push_back(team);
}

void user::add_favourite(submission s)
{
	favourites.push_back(s);
}

void user::show_favourites()
{
	cout << "Favorites\n";
	for (auto f : favourites)
		 f.show_submission(handle);
} 
void user::show_users_by_ranks()
{
	cout << "Users :\n"; 
	for (auto s : ranking_users)
		 cout << s.second << " " << s.first << "\n--------------------------------------\n";
}

void problem_setter::add_problem(problem p)
{
	createdProblems.push_back(p);
}

void problem_setter::show_problemsetting()
{
	cout << handle << " Problemsetting:\n";
	for (auto p : createdProblems)
		p.show_problem();
}

