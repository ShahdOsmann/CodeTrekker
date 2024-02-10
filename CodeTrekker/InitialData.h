#pragma once
#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>  
#include "valid.h"
#include <regex> 
using namespace std;
void init(map<string, bool>& found_handle, map<string, bool>& found_email, map<string, user>& users, map<string, problem>&problems)
{
    users["hager"] = user("Hager", "hagermdk@gmail.com", "", "mbdhub@5F", "Egypt", "beniswief university", 1165, 1165, 9, 0, 0, 25, 2); found_handle["hager"] = 1, found_email["hagermdk@gmail.com"] = 1;
    users["aliragab313"] = user("AliRagab313", "ra010250@gmail.com", "Ali Ragab", "ndj@548F", " Egypt", "Egyptian E-Learning University", 1669, 1713, 302, 0, 1, 866, 20); found_handle["aliragab313"] = 1, found_email["ra010250@gmail.com"] = 1;
    users["gamal74"] = user("gamal74", "abdelrahman-gamal@gmail.com", "Abdelrahman Gamal", "lksndj@548F", "Palestinian Territory", "FCI-Cairo university", 2154, 2154, 1228, 16, 0, 3438, 84); found_handle["gamal74"] = 1, found_email["abdelrahman-gamal@gmail.com"] = 1;
    users["raisefromdeath"] = user("RaiseFromDeath", "hazemadelkhalel@gmail.com", "Hazem Adel", "mbdb@4545F", "Egypt", "FCI-Cairo university", 1861, 2032, 667, 5, 1, 1033, 11); found_handle["raisefromdeath"] = 1, found_email["hazemadelkhalel@gmail.com"] = 1;
    users["triplem5da"] = user("TripleM5da", "anany@gmail.com", "Mohamed Anany", "jdsb@548F", "Palestinian Territory", "FCIS Ain Shams University", 2428, 2506, 3769, 63, 0, 8209, 86); found_handle["triplem5da"] = 1, found_email["anany@gmail.com"] = 1;
    users["abdel-azizmostafa"] = user("Abdel-AzizMostafa", "Abdel-AzizMostafa@gmail.com", "Abdel-Aziz Mostafa", "kjsdjn548P)", "Egypt", "FCIS Ain Shams University", 2007, 2176, 770, 0, 0, 2120, 18); found_handle["abdel-azizmostafa"] = 1, found_email["Abdel-AzizMostafa@gmail.com"] = 1;
    users["rowan_hamada"] = user("RoWan_Hamada", "rowan@gmail.com", "sndkjnK5&"); users["rowan_hamada"].set_name("Rowan hamada"); found_handle["rowan_hamada"] = 1, found_email["rowan@gmail.com"] = 1;
    users["rowan_hamada"].update_contest_rating(1245); users["rowan_hamada"].update_university("BFCAI Benha University"); 
    users["gargera0"] = user("Gargera0", "gargera@gmail.com", "sndkjnK5dsd*"); users["gargera0"].set_name("Esraa Taha"); users["gargera0"].update_contest_rating(1464); found_handle["gargera0"] = 1, found_email["gargera@gmail.com"] = 1;


    problems["1A"] = problem("Odd One Out", "CodefTrekker Round 918 (Div. 4)", "Check if the number is even or odd;",
        "flamestorm", "if number modulo 2 is 0 it is even else it is odd; input; an integer n<100; output; output even if n is even , else output odd;", "time limit per test1 second;memory limit per test256 megabytes;inputstandard input;outputstandard output",
        { "Brute Force" , "Math" }, { "Input;2;output;even","input;3;output;odd;" }, 800, 523, "1A");
    problems["2B"] = problem("LIS", "CodefTrekker Round 652 (Div. 3)", "Output the size of longest increasing subsequence;",
        "queen..", "search for largest increaing subsequeence; input n (n<50) size of the array forllowing n numbers the numbers in the array 1<=a[i]<600;", "time limit per test1 second;memory limit per test256 megabytes;inputstandard input;outputstandard output",
        { "Brute Force", "DP", "Greedy"}, {"Input;5;1 2 1 4 5;output;4"}, 1300, 325, "2B");
}