#pragma once
#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map> 
#include <windows.h> 
#include "valid.h"
#include "Register.h"
#include "login.h"
#include "InitialData.h"
#include <regex> 
#include "problem.h";
using namespace std;
void show_users(map<string, user>& users)
{
	cout << "Users\n";
	for (auto m : users)
	{
		m.second.show_user();
	}

}
void show_problems(map<string, problem>problems)
{
	cout << "Probemset:\n";
	for (auto m : problems)
	{
		m.second.show_problem();
	}
	cout << "choose:\n";
	cout << "1. Sort them from easy to hard\n2. Sort them from hard to easy\n3. Return to main page\n";
	cout << "Your choice: "; int c; cin >> c;
	if (c == 1)problem::showFromEasyToHard();
	else if (c == 2)problem::showFromHardToEasy();
}
void search_for_user(map<string, bool>& found_handle, map<string, user>& users, bool logged_in, user &profile)
{
	cout << "Enter Handle: ";
	string handle, h; bool f = 1;
	while (1) {
		cin >> handle;
		h = handle; for (ll i = 0; i < h.size(); i++)h[i] = tolower(h[i]);
		if (found_handle[h])break;
		cout << "Invalid handle\n"; 
		cout << "Do you want to return to home page? (1:yes, 0:no): ";
	    cin >> f; if (!f)break;
		else cout << "ok, try again: ";
	}
	if (!f)return;
	users[h].show_user();
	if (logged_in)
	{
		if (profile.is_a_friend(users[h].get_handle())) {
			cout << "Do you want to friend him ? (1:yes, 0:no) : ";
			bool choice = 0; cin >> choice;
			if (choice)users[h].increment_number_of_friends(), profile.add_friend(users[h].get_handle()), cout << "\nDone\n";
		}
		else
		{
			cout << "Do you want to delete the friendship ? (1:yes, 0:no) : ";
			bool choice = 0; cin >> choice;
			if (choice)profile.delete_friend(users[h].get_handle()), cout << "\nDone\n";
		}
	}
}
void search_for_problem(map<string, problem>&problems, map<string, bool> &found_problem, bool logged_in, user& profile)
{
	cout << "Enter the ID of the problem: ";
	string p; bool f = 1;
	while (1) {
		cin >> p;
		if (found_problem[p])break;
		cout << "Invalid handle\n";
		cout << "Do you want to return to home page? (1:yes, 0:no): ";
		cin >> f; if (!f)break;
		else cout << "ok, try again: ";
	}
	if (!f)return;
	problems[p].show_problem();
	if (logged_in)
	{
		cout << "Submit the problem? (1:yes, 0:no): ";
		bool c; cin >> c;
		if (c)
		{
			cout << "\nEnter problem ID: "; 
			string id; cin >> id;
			profile.submit(problems[id]);
		}
	}
}